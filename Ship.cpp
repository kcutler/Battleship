//
//  Ship.cpp
//  Battleship
//
#include <iostream>
using namespace std;
#include "Ship.h"

//*******************************************************************************************
//
//*******************************************************************************************

Ship::Ship(point originPoint, direction o, int l) 
{
	origin = originPoint;
	orientation = o;
	length = l;	
	lencopy = length;
	hits = 0;

	points.add(originPoint);
	if (orientation == HORIZONTAL)
	{
		while((lencopy - 1) > 0)
		{
			points.add((originPoint.getX() + 1), originPoint.getY)
			lencopy -= 1;
		}
	}
	else
	{
		while((lencopy - 1) > 0)
		{
			points.add(originPoint.getX(), (originPoint.getY()+1))
			lencopy -= 1;
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
		if (points.containsPoint(s[i]))
			return true;
	}	
	return false;
}

//*******************************************************************************************
// Shot Fired At Point
//*******************************************************************************************

void Ship::shotFiredAtPoint(const point& p)
{
	IntCollection hits;
	if points.collidesWith(p)
	{
		hits.add(p);
	}
	//add hits to point collection hits -- can access pointcollection hits
}

//*******************************************************************************************
// Is Hit At Point
//*******************************************************************************************

bool Ship::isHitAtPoint(const point& p)
{
	if (hits.containsPoint(p))
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
	//return hits
    return hits.getSize();
}

//*******************************************************************************************
// Operator =
//*******************************************************************************************

const Ship& Ship::operator=(const Ship& s)
{
	origin = s.originPoint;
	orientation = s.o;
	length = s.l;

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
		cout << "You sank a ship of length " << points.getSize() << "!" << endl;
		return true;
	return false;	
}











