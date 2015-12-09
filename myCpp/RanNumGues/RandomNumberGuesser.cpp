// Author: Jasmine Farrell
// Date: Dec. 2nd 2015
// File: RandomNumberGuesser.cpp
// Course: cs110b

#include <iostream>
#include <stdlib.h>
#include "RandomNumberGuesser.h"

using namespace std;

char getUserResponseToGuess(int guess)
{
    char resp;
    cout << "Is it " << guess << "? (h, l, c):\n";
    cin >> resp;
    return resp;
}

bool checkValidGuess(char g)
{
    if (g == 'c' || g == 'l' || g == 'h')
    {
        return true;
    } else {
        return false;
    }
}

int main()
{
    char guess;

    NumberGuesser *ng = new RandomNumberGuesser(1, 10);

    cout << "Welcome to Number Guesser Game!\n";
    do {
        do {
            guess = getUserResponseToGuess(ng->getCurrentGuess());
        } while(!checkValidGuess(guess));

        if(guess == 'h')
        {
            ng->higher();
        }
        else if (guess == 'l')
        {
            ng->lower();
        }
    } while(guess != 'c');

    cout << "YOUR NUMBER WAS " << ng->getCurrentGuess();


    return 0;
}
