 //File 0: Circle.h
 //Author: Jasmine Farrell
 //Date: Oct. 27th, 2015
 //Course: cs110b


#ifndef CIRCLE_H
#define CIRCLE_H


class Circle
{
    private:
        double radius;
        double x;
        double y;
    public:
        void setRadius(double);
        void setX(double);
        void setY(double);
        double getRadius() const
            { return radius; }
        double getX() const
            { return x; }
        double getY() const
            { return y; }
        double getArea() const;
        bool containsPoint(double, double);
};

#endif
