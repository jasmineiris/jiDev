// File: league_DMA.cpp
// Author: Jasmine Farrell
// Date Modified: Oct. 3rd, 2015
// Course: CS110B
// Description: the program will ask the user to enter five team names,
// and five win amounts. It will stor the data in memory, and
// print it back out soted by wins.
// Usage: The program records and displays league standings for a baseball
// league. 



#include<iostream>
#include<string>

using namespace std;

//Prototypes for my funcitons
void initializeArrays(string n[], int s[], int size);
void sortData(string n[], int s[], int size);
void displayData(string n[], int s[], int size);
void swapper(int& x, int& y);

int main ()
{
    //size of baseball teams
    int size;

    //pointer for array for # of wins
    int *winsptr = NULL;

    //pointer for array for team names
    string *teamsptr = NULL; 

    //user input regarding amount of teams
    cout << "How many teams will you enter? "; 
    cin >> size;

    //creating new arrays reference by pointers
    winsptr = new int[size];
    teamsptr = new string[size];

    //passing the address to the arrays
    initializeArrays(teamsptr, winsptr, size);
    sortData(teamsptr, winsptr, size);
    displayData(teamsptr, winsptr, size);

    //deleting array after functions run
    delete [] winsptr;
    delete [] teamsptr;

    //setting pointers to NULL
    winsptr = NULL;
    teamsptr = NULL;    

    return 0;
}

//use a for loop to get user's input for team wins and team name's
void initializeArrays(string n[], int s[], int size)
{
    for (int i = 0; i < size; i++)
    {
        do 
        {
            cout << "Enter team #" << 1+i << ": ";
            cin >> n[i];
            cout << "Enter the wins for team #" << 1+i << ": ";
            cin >> s[i];
            if (s[i] < 0)
            {
                cout << "Only positive scores.\n";
            }
        }
        while (s[i] < 0);
    }
}    

//accepts two string arguments then swaps the contents of the two strings
void strswapper(string& x, string& y)
{
    string temp;

    temp = x;
    x = y;
    y = temp;
}

//accepts two integer arguments then swaps the contents of the two integers
void intswapper(int& x, int& y)
{
    int temp;
    
    temp = x;
    x = y;
    y = temp;    
}

//arrages the input from highest scoring teams to lowest- descending order
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

//displays data from user's input
void displayData(string n[], int s[], int size)
{
    cout << "\nLeague Standings:\n";
 
    for (int i = size-1; i >= 0; i--)
    {
        cout << n[i] << ": " << s[i] << endl;
    }
}

/* [jfarrel6@hills hw]$ g++ league_DMA.cpp 
 * [jfarrel6@hills hw]$ a.out
 * How many teams will you enter? 5
 * Enter team #1: ryan
 * Enter the wins for team #1: 3
 * Enter team #2: cocoa
 * Enter the wins for team #2: 2
 * Enter team #3: roxy
 * Enter the wins for team #3: 6
 * Enter team #4: jasmine
 * Enter the wins for team #4: 4
 * Enter team #5: rocco
 * Enter the wins for team #5: 2
 * League Standings:
 * roxy: 6
 * jasmine: 4
 * ryan: 3
 * rocco: 2
 * cocoa: 2
 * /
