// Author: Jasmine Farrell
// Date: Dec. 4th 2015
// File: inheritance.cpp


#include <iostream>
using namespace std;

//base class shape
class Shape
{
    public:
        void setWidth(int w)
        {
            width = w;
        }
        void setHeight(int h)
        {
            height = h;
        }
    protected:
        int width;
        int height;
};

//Base class PaintCost
class PaintCost
{ 
    public:
        int getCost(int area)
        {
            return area * 70;
        }
};

//Derived class
class Rectangle: public Shape, public PaintCost
{
    public:
        int getArea()
        {
            return (width * height);
        }
};

int main(void)
{
    Rectangle Rect;
    int area;

    Rect.setWidth(5);
    Rect.setHeight(7);

    area = Rect.getArea();

    //print the area of the object.
    cout << "Total area: " << Rect.getArea() << endl;

    //Print the total cost of painting 
    cout << "Total paint cost: $" << Rect.getCost(area) << endl;

    return 0;
}

/*
 * A derived class can access all the non-private members of its base class. Thus base-class members that should not be accessible to the member functions of derived classes should be declared private in the base class.
 * 
 * A derived class inherits all base class methods with the following exceptions:
 *
 * Constructors, destructors and copy constructors of the base class.
 *
 * Overloaded operators of the base class.
 *
 * The friend functions of the base class.
 *
 * same class: public: Y Protected: Y Private: Y
 * Dervied class: YYN
 * Outside classes: YNN
 *
 * Public Inheritance: When deriving a class from a public base class, public members of the base class become public members of the derived class and protected members of the base class become protected members of the derived class. A base class's private members are never accessible directly from a derived class, but can be accessed through calls to the public and protected members of the base class.
 *
 * Protected Inheritance: When deriving from a protected base class, public and protected members of the base class become protected members of the derived class.
 *
 * Private Inheritance: When deriving from a private base class, public and protected members of the base class become private members of the derived class.
 *
 *A C++ class can inherit members from more than one class and here is the extended syntax:

 class derived-class: access baseA, access baseB....
 * Where access is one of public, protected, or private and would be given for every base class and they will be separated by comma as shown above.
