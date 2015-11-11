//File 0: CircleProgram.cpp
//File 1: Circle.h contains your class declaration
//File 2: Circle.cpp contains your class implementation 
//Author: Jasmine Farrell
//Date: Oct. 27th, 2015
//Couse: cs110b
//Description: takes in coordinates from user and checks for points in circle.



#include<iostream>
#include"Circle.h"
using namespace std;

int main()
{
    double temp;
    double temp2;
    Circle myCircle;
    Circle *cirPtr = NULL;
    cirPtr = &myCircle;

    cout << "Enter center x: \n";
    cin >> temp;
    myCircle.setX(temp);
    cout << "Enter center y: \n"; 
    cin >> temp; 
    myCircle.setY(temp);
    cout << "Enter radius: \n";
    cin >> temp;
    myCircle.setRadius(temp);
    cout << "Your area is " << myCircle.getArea() << endl;

    cout << "Enter new center x: \n";
    cin >> temp;
    cirPtr->setX(temp);
    cout << "Enter new center y: \n"; 
    cin >> temp; 
    cirPtr->setY(temp);
    cout << "Enter new radius: \n";
    cin >> temp;
    cirPtr->setRadius(temp);

    cout << "Checking if point is in circle. Enter point x: \n";
    cin >> temp;
    cout << "Enter point y: \n";
    cin >> temp2;

    if (cirPtr->containsPoint(temp,temp2))
        cout << "Your values are inside the CIRCLE! WOOHOO!\n";
    else 
        cout << "Your values are outside the circle. Enter new values.\n";    
}

/*$ ./a.out
 * Enter center x: 
 * 4
 * Enter center y: 
 * 8
 * Enter radius: 
 * 4
 * Your area is 50.2655
 * Enter new center x: 
 * 2
 * Enter new center y: 
 * 3
 * Enter new radius: 
 * 2
 * Checking if point is in circle. Enter point x: 
 * 0
 * Enter point y: 
 * 0
 * Your values are inside the CIRCLE! WOOHOO!
 * $ ./a.out
 * Enter center x: 
 * 2
 * Enter center y: 
 * 8
 * Enter radius: 
 * 2
 * Your area is 12.5664
 * Enter new center x: 
 * 2
 * Enter new center y: 
 * 6
 * Enter new radius: 
 * 3
 * Checking if point is in circle. Enter point x: 
 * 8
 * Enter point y: 
 * 9
 * Your values are outside the circle. Enter new values.*/



