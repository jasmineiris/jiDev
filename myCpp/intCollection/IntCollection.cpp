// File: IntCollection.cpp
// Author: Jasmine Farrell
// Date: Nov. 15th, 2015
// Course: cs110b

#include "IntCollection.h"
#include <iostream>
using namespace std;

//constructor
IntCollection::IntCollection()
{
    //initialize member data to reflect an empty IntCollection
    size = capacity = 0;
    data = NULL;
}

//deconstructor
IntCollection::~IntCollection()
{
    delete [] data;
}

//The copy constructor should perform a deep copy of the argument object.
IntCollection::IntCollection( const IntCollection &c)
{
    size = c.size;
    capacity = c.capacity;
    data = c.data;
}

void IntCollection::addCapacity()
{
    //create a new, bigger buffer, copy the current data to it, delete
    //the old buffer, and point our data pointer to the new buffer

    //note: there is a more efficient way to do this using the c
    //memory management function realloc(), but that is beyond the
    //scope of or course
    int* newData;
    capacity += CHUNK_SIZE;
    newData = new int[capacity];
    for (int i=0; i<size; i++)
        newData[i] = data[i];
    delete [] data;
    data = newData;
}

void IntCollection::add(int value)
{
    //first, allocate more memory if we need to
    if (size == capacity)
        addCapacity();

    //now, add the data to our array and increment size
    data[size++] = value;
}

int IntCollection::get(int index)
{
    if (index<0 || index>=size)
    {
        cout << "Error: get() tring to access index out of range.\n";
        exit(1);
    }

    return data[index];
}

int IntCollection::getSize()
{
    return size;
}

//The assignment operator should also perform a deep copy of the argument object a reference to itself
IntCollection& IntCollection:: operator=(const IntCollection &c)
{
    size = capacity = c.size;
    data = new int[size];

    for (int i=0; i<size; i++)
    {
        data[i] = c.data[i];
    }
    return *this;
}

//should return true if the argument object has the same size as the receiving object, and the values in both objects’ data arrays are identical.
bool IntCollection::operator==(const IntCollection &c)
{
    if (size != c.size)
        return false;
    else
    {
        for (int i=0; i<size; i++)
        {
            if (data[i] != c.data[i])
                return false;
        }
    }
    return true;
}

//insertion operator should add the int parameter into the receiving IntCollection
IntCollection& IntCollection::operator<<(int value)
{
    add(value);
    return *this;
}


