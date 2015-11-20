//File: IntCollectionProgram.cpp
//Author: Jasmine Farrell
//Date: Nov. 15th, 2015
//Course: cs110b


#include "IntCollection.h"
#include <iostream>
using namespace std;
void checkEqual(IntCollection &ic1, IntCollection &ic2);
void printCheck(IntCollection &c);

int main()
{
    IntCollection d;
    IntCollection c;

    c.add(45);
    c.add(-210);
    c.add(77);
    c.add(2);
    c.add(-21);
    c.add(42);
    c.add(7);
    d = c;
    c << 4 << 7 << 9 << 10;
    printCheck(c);
    checkEqual(c,d);

    d << 10 << 4 << 84;
    printCheck(d);
    checkEqual(c,d);
}

//tester helper function to check if two IntCollectors are equal 
void checkEqual (IntCollection &ic1, IntCollection &ic2)
{
    if(ic1==ic2)
    {
        cout << "Equal!" << endl;
    }
    else
    {
        cout << "Not Equal!" << endl;
    }
}

//printer helper function to print results of Intcollector
void printCheck (IntCollection &c)
{

    for (int i = 0; i < c.getSize(); i++)
    {
        cout << c.get(i) << endl;
    }
}
