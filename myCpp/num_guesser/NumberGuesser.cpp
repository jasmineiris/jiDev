//File: NumberGuesser.cpp
//Author: Jasmine Farrell
//Date: Oct. 28th, 2015
//Course: cs110b

#include <iostream>
#include "NumberGuesser.h"
using namespace std;

NumberGuesser::NumberGuesser(int lowerBound, int upperBound)
{
    lowerI = lowerBound;
    higherI = upperBound;
    reset();
}

void NumberGuesser::higher()
{
    lowerB = getCurrentGuess();
}

void NumberGuesser::lower()
{
    upperB = getCurrentGuess();
}

int NumberGuesser::getCurrentGuess()
{
    return (upperB + lowerB)/2;
}

void NumberGuesser::reset()
{
    lowerB = lowerI;
    upperB = higherI;
}
