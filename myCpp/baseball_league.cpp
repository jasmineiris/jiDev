// File: baseball_league.cpp
// Author: Jasmine Farrell
// Date: Sept. 18th, 2015
// Course: cs110b
// Description: the program will ask the user to enter five team names,
// and five win amounts. It will store the data in memory, and
// print it back out soted by wins.
// Usage: The program records and displays league standings for a baseball
// league. 



#include<iostream>
#include<string>

using namespace std;

//Prototypes that will be invoked with main
void initializeArrays(string n[], int s[], int size);
void sortData(string n[], int s[], int size);
void displayData(string n[], int s[], int size);
void swapper(int& x, int& y);

//Main calls functions to gather data, sort data and display data from user.
int main ()
{
    int size = 5;
    int wins[size];
    string teams[size]; 

    initializeArrays(teams, wins, size);
    sortData(teams, wins, size);
    displayData(teams, wins, size);

    return 0;
}

//Request teams names and wins from user
void initializeArrays(string n[], int s[], int size)
{
    for (int i = 0; i < size; i++)
    {
        do 
        {
            cout << "Enter team #" << 1+i << ":\n";
            cin >> n[i];
            cout << "Enter the wins for team #" << 1+i << ":\n";
            cin >> s[i];
            if (s[i] < 0)
            {
                cout << "Only positive scores.\n";
            }
        }
        while (s[i] < 0);
    }
}    
//temp string place holder for sortData function
void strswapper(string& x, string& y)
{
    string temp;

    temp = x;
    x = y;
    y = temp;
}

//temp integer place holder for sortData function
void intswapper(int& x, int& y)
{
    int temp;
    
    temp = x;
    x = y;
    y = temp;    
}

//Sorts wins in numberic order
void sortData(string n[], int s[], int size)
{
    bool swapped;

    do
    {
        swapped = false;
        for (int i = 0; i < (size-1); i++)
        {
            if (s[i] > s[i+1])
            {
                intswapper(s[i],s[i+1]);
                strswapper(n[i],n[i+1]);
                swapped = true;
            }
        }
    } while (swapped);        
}
//displays data in order from largest to smallest wins
void displayData(string n[], int s[], int size)
{
    cout << "League Standings:\n";
 
    for (int i = size-1; i >= 0; i--)
    {
        cout << n[i] << ": " << s[i] << endl;
    }
}

/* [jfarrel6@hills hw]$ g++ baseball_league.cpp 
 * [jfarrel6@hills hw]$ a.out
 * Enter team #1:
 * Roxy
 * Enter the wins for team #1:
 * 234
 * Enter team #2:
 * Ryan
 * Enter the wins for team #2:
 * 332
 * Enter team #3:
 * Cocoa
 * Enter the wins for team #3:
 * 554
 * Enter team #4:
 * Jasmine
 * Enter the wins for team #4:
 * 345
 * Enter team #5:
 * Iris
 * Enter the wins for team #5:
 * 543
 * League Standings:
 * Cocoa: 554
 * Iris: 543
 * Jasmine: 345
 * Ryan: 332
 * Roxy: 234
 *
 * Enter team #2:
 * Cocoa
 * Enter the wins for team #2:
 * -45
 *  Only positive scores.
 *  Enter team #2:
 *  Cocoa
 *  Enter the wins for team #2:
 *  45
 */
