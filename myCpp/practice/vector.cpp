// Author:Jasmine Farrell
// Date: Dec. 4th 2015
// File: stl.cpp

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //create a vector to store int
    vector<int> vec;
    int i;

    //display the original size of vec
    cout << "vector size = " << vec.size() << endl;

    //push 5 values into the vector
    //The push_back( ) member function inserts value at the end of the vector, expanding its size as needed.
    for(i=0; i<5; i++)
    {
        vec.push_back(i);
    }

    //display extended size of vec
    //The size( ) function displays the size of the vector.
    cout << "extended vector size = " << vec.size() << endl;

    for(i=0; i<5; i++)
    {
        cout << "value of vec [" << i << "] = " << vec[i] << endl;
    }

    //use iterator to access the values
    //The function begin( ) returns an iterator to the start of the vector.
    vector<int>::iterator v = vec.begin();
    while( v != vec.end()) 
    { 
        cout << "value of v = " << *v << endl;
        v++;
    }
    //The function end( ) returns an iterator to the end of the vector.
    return 0;
}
