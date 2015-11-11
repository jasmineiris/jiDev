//Author: Jasmine Farrell
//File: league_structs.cpp
//Date: Oct. 17th 2015
//Course: cs110b
//Assignment 8: The League with Structs


#include<cstring>
#include<string>
#include<iostream>
using namespace std;

//data type with wins and names listed
struct winRecord {
    int wins;
    char* name;
};

//prototypes for sorting , displaying and initializing wins and names
void initializeData(winRecord* standings, int size);
void sortData(winRecord* standings, int size);
void displayData(winRecord* standings, int size);
void recswapper(winRecord *x, winRecord *y);

//function to use getline
char* getline()
{
    const int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];

    cin.ignore();
    cin.getline(buffer,BUFFER_SIZE);
    int length = strlen(buffer);

    char *rValue = new char[length +1];
    strncpy(rValue, buffer, length);

    return rValue;
}


int main ()
{
    // the number of baseball teams from user
    int size;
    winRecord* rec;
    
    cout << "How many teams will you enter?";
    cin >> size;

    rec = new winRecord[size];

    // Calling functions to sort, initialize, and display user data
    initializeData( rec, size);
    sortData(rec, size);
    displayData(rec, size);

    delete [] rec;

    rec = NULL;

    return 0;
}

//Collecting Team name and wins from baseball games played.
void initializeData(winRecord* standings, int size)
{
    for (int i=0; i<size; i++)
    {
        do
        {
            cout << "Enter team #" << 1+i << ": ";
            standings[i].name = getline();
            cout << "Enter the wins for team #" << 1+i << ": ";
            cin >> standings[i].wins;
            if (standings[i].wins < 0)
            {
                cout << "Only positive scores.\n";
            }
        }
        while (standings[i].wins < 0);
    }
}

//swapping data to place highest to lowest team scores
void recswapper(winRecord *x, winRecord *y)
{
    winRecord temp = *x;
    *x = *y;
    *y = temp;
}

//Calling recswapper and placing team scores from highest to lowest
void sortData(winRecord* standings, int size)
{
    bool swapped;

    do
    {
        swapped = false;
        for (int i=0; i<(size-1); i++)
        {
            if (standings[i].wins > standings[i+1].wins)
            {
                recswapper(&standings[i],&standings[i+1]);
                swapped = true;
            }
        }
    } while (swapped);
}

//Displaying data from users input: Team names and baseball games wins and loses
void displayData(winRecord* standings, int size)
{
    cout << "\nLeague Standings:\n";
    
    for (int i = size-1; i >= 0; i--)
    {
        cout << standings[i].name << ": " << standings[i].wins << endl;
    }
}

/*$ ./a.out
 * How many teams will you enter?3
 * Enter team #1: Cocoa
 * Enter the wins for team #1: 3
 * Enter team #2: Rox
 * Enter the wins for team #2: 5
 * Enter team #3: Jas
 * Enter the wins for team #3: 6
 *
 * League Standings:
 * Jas: 6
 * Rox: 5
 * Cocoa: 3
 * */




