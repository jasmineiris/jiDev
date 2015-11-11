// File: NumberGuessingGame.cpp
// Author: Jasmine Farrell
// Date: Oct. 28th, 2015
// Course: cs110b

#include <iostream>
#include "NumberGuesser.h"
using namespace std;

bool shouldPlayAgain()
{
    //gets input from user; returns true or false
    char resp;
    cout << "Do you want to play again?(y/n)\n";
    cin >> resp;
    if (resp == 'y')
    {
        return true;
    } else if (resp == 'n') {
        return false;
    } else {
        return shouldPlayAgain();
    }
}

char getUserResponseToGuess(int guess)
{
    char resp;
    cout << "It is " << guess << "? (h, l, c):\n";
    cin >> resp;
    return resp;
}


int main()
{
    int temp1;
    int temp2;
    char resp;

    cout << "Welcome to Number Guesser Game!\n";
    cout << "What is your lower boundary you'd like to play at?\n";
    cin >> temp1;
    cout << "What is your higher boundary you'd like to play at?\n";
    cin >> temp2;

    NumberGuesser guessObj(temp1, temp2);
    cout << "Think of a number between your lower and higher boundaries. \n";
    do
    {
        do
        {
            temp1 = guessObj.getCurrentGuess();
            resp = getUserResponseToGuess(temp1);

            if (resp == 'l')
                guessObj.lower();
            else if (resp == 'h')
                guessObj.higher();
        } while (resp!= 'c');

        guessObj.reset();

    } while (shouldPlayAgain());

    return 0;
}
