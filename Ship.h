//
//  Ship.h
//  Battleship
//

#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include "Point.h"
#include "PointCollection.h"

enum direction { HORIZONTAL, VERTICAL};

class Ship
{
  private:
    int length;
    direction orientation;
    point origin;
    
    PointCollection points;
    PointCollection hits;
    
  public:
    //constructors
    Ship(point originPoint, direction orientationDirection, int lengthValue);
    Ship(const Ship& s);
    
    //member functions
    bool containsPoint(const point& p) const;
    bool collidesWith(const Ship& s) const;
    
    void shotFiredAtPoint(const point& p);
    bool isHitAtPoint(const point& p);
    int hitCount() const;
    
    const Ship& operator=(const Ship& s);

    bool isSunk();

};

#endif
//
//  Ship.cpp
//  Battleship
//

#include "Ship.h"

//*******************************************************************************************
//
//*******************************************************************************************

Ship::Ship(point originPoint, direction o, int l)
{
	origin = originPoint;
	orientation = o;
	length = l;
	points.add(originPoint);
	if (orientation == HORIZONTAL)
	{
		for (int i = 1; i <= l - 1; i++)
		{
			points.add(point((originPoint.getX() + i), originPoint.getY()));
		}
	}
	else
	{
		for (int i = 1; i <= l - 1; i++)
		{
			points.add(point(originPoint.getX(), (originPoint.getY() + i)));
		}
	}
}

//*******************************************************************************************
//
//*******************************************************************************************

Ship::Ship(const Ship& s)
{
	*this = s;
}

//*******************************************************************************************
// Contains Point
//*******************************************************************************************

bool Ship::containsPoint(const point& p) const
{
	if (points.contains(p))
		return true;
	return false;
}

//*******************************************************************************************
// Collides With
//*******************************************************************************************

bool Ship::collidesWith(const Ship& s) const
{
	for (int i = 0; i < points.getSize(); i++)
	{
		if (points.contains(s.points[i]))
			return true;
	}
	return false;
}

//*******************************************************************************************
// Shot Fired At Point
//*******************************************************************************************

void Ship::shotFiredAtPoint(const point& p)
{
	if (points.contains(p))
	{
		hits.add(p);
	}
}

//*******************************************************************************************
// Is Hit At Point
//*******************************************************************************************

bool Ship::isHitAtPoint(const point& p)
{
	if (hits.contains(p))
	{
		return true;
	}
	return false;
}

//*******************************************************************************************
// Hit Count
//*******************************************************************************************

int Ship::hitCount() const
{
	return hits.getSize();
}

//*******************************************************************************************
// Operator =
//*******************************************************************************************

const Ship& Ship::operator=(const Ship& s)
{
	origin = s.origin;
	orientation = s.orientation;
	length = s.length;
	points = s.points;
	hits = s.hits;
	return *this;
}


//*******************************************************************************************
//  Is Sunk
//*******************************************************************************************

bool Ship::isSunk()
{
	if (points.getSize() == hits.getSize())
		return true;
	return false;
}











