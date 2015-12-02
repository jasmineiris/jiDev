// Author: Jasmine Farrell
// Date: Dec. 1st, 2015
// Course: cs110b
// File: Ship.cpp
// File: Battleship

#include "Ship.h"

//*******************************************************************************************
// Ship constructor
//*******************************************************************************************

Ship::Ship(point originPoint, direction o, int l) 
{
    //variables assigned 
    origin = originPoint;
    orientation = o;
    length = l;

    if ( o == HORIZONTAL )
        for (int i=0; i<l; i++) 
        {
            originPoint.setX(origin.getX() + i);
            points << originPoint;
        }
    else
        for (int i=0; i<l; i++) 
        {
            originPoint.setY(origin.getY() + i);
            points << originPoint;
        }
}

//*******************************************************************************************
//
//*******************************************************************************************

Ship::Ship(const Ship& s) 
{
    *this = s;
}

//***********************i********************************************************************
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
    bool collide = false;
    int i = 0;

    while (collide == false && i < s.length)
    {
        if (s.points.get(i) == points.get(i))
            collide = true;
        i++;
    }
    return collide;
}

//*******************************************************************************************
// Shot Fired At Point
//*******************************************************************************************

void Ship::shotFiredAtPoint(const point& p)
{
    if (points.contains(p) && !hits.contains(p))
        hits.add(p);
}

//*******************************************************************************************
// Is Hit At Point
//*******************************************************************************************

bool Ship::isHitAtPoint(const point& p)
{
    if (hits.contains(p))
            return true;

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
    length = s.length;
    orientation = s.orientation;
    origin = s.origin;
    
    points = s.points;
    hits = s.hits;
    
    return *this;
}


//*******************************************************************************************
//  Is Sunk
//********************************************************************** *********************

bool Ship::isSunk() 
{
    if (hits.getSize() == length)
        return true;
    else
        return false;   
}






