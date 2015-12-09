// Author: Jasmine Farrell
// Date: Dec. 2nd 2015
// File:RandomNumberGuesser.h
// Course: cs110b
//include numberguess.h

#ifndef RANDOMNUMBERGUESSER_H
#define RANDOMNUMBERGUESSER_H

#include <stdlib.h>
#include "NumberGuesser.h"

#include <iostream>

using namespace std;

//Generated random class for number guesser to out put random number
class RandomNumberGuesser : public NumberGuesser
{
    private:
        int randg;
        void generateg()
        { randg = rand() % (high - low + 1) + low; }
        void errorCheck()
        {
            //cout << "(debug) low: " << low << endl;
            //cout << "(debug) high: " << high << endl;
            if (high < low)
            {
                cout << "No funny business!\nResetting the game." << endl; 
                reset();
            }
        }
    public:
        //Constructor w/parameters
        RandomNumberGuesser(int l, int h) : NumberGuesser(l, h)
        { srand (time(NULL)); generateg(); }
        int getCurrentGuess()
        { return randg; }
        //random high guess genrated
        void higher()
        {
            NumberGuesser::higher();
            errorCheck();
            generateg();
        }
        //random low guess genrated
        void lower()
        {
            NumberGuesser::lower();
            errorCheck();
            generateg();
        }
        //reset game
        void reset()
        { 
            NumberGuesser::reset();
            generateg(); cout << "R\n" << endl; 
        }
};

#endif
