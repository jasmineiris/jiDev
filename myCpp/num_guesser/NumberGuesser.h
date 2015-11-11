//File: NumberGuesser.h
//Author: Jasmine Farrell
//Date: Oct. 28th, 2015
//Course: cs160b


#ifndef NUMBERGUESSER_H
#define NUMBERGUESSER_H

class NumberGuesser
{
    private:
        int lowerB;
        int upperB;
        int lowerI;
        int higherI;
    public:
        NumberGuesser(int lowerBound, int upperBound);
        void higher();
        void lower();
        int getCurrentGuess();
        void reset();
};

#endif
