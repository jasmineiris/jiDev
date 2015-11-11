// File: asterisk.cpp 
// Author: Jasmine Farrell
// Date: Aug. 25th, 2015
// Course: cs110b
// Description: Prints specified number of asterisks as provided from the user
// Usage: Call 'asterisk' from terminal and follow the prompts

#include<iostream>
using namespace std;

int main()
{
    int num;
    char repeat = 'y';
    while ( repeat != 'n' )
    {
        cout << "How many asterisks would you like to print?\n";
        cin >> num;
        for ( int n = 0; n < num; n++)
        {
            cout << "*";
        }
        cout << endl;
        cout << "Would you like to pick another number (y/n)?\n";
        cin >> repeat;

    }
    return 0;
}

How many asterisks would you like to print?
5
*****
Would you like to pick another number (y/n)?
y
How many asterisks would you like to print?
3
***
Would you like to pick another number (y/n)?
y
How many asterisks would you like to print?
7
*******
Would you like to pick another number (y/n)?
n
[jfarrel6@hills assgt1_8-24-15]$ 
