//File 0: Circle.cpp
//Author: Jasmine Farrell
//Date: Oct. 27th, 2015
//Course: cs110b


#include<iostream>
#include<math.h>
#include"Circle.h"
using namespace std;


void Circle::setRadius(double r)
{
    radius = r;
}
void Circle::setX(double value)
{
    x = value;
}
void Circle::setY(double value)
{
    y = value;
}

double Circle::getArea() const 
{
    return radius*radius*M_PI;
}

bool Circle::containsPoint(double xValue, double yValue)
{
    int d;
    d=sqrt(xValue*xValue+yValue*yValue);

    if(d <= radius)
    {
        return true;
    }
    else
    {
        return false;
    }
}
