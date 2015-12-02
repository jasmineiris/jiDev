// Author: Jasmine Farrell
// Date: Dec. 1st, 2015
// Course: cs110b
// File: Board.h
// File: Battleship


#ifndef BOARD_H
#define BOARD_H

#include <iostream>

// needs variables for board dimensions (could use one to force squares, but let's be flexible)
// a variable to store the number of ships, plus an array for the ships

class Board
{
/*
    private:
        int width;
        int height;
        int numShips;
        
        // storing the characters for making the board
        char ship;
        char water;
        char hit;
        char miss;
    
        Ship* ships;
        PointsCollection sea; // might be unnecessary
        PointsCollection shots; // might be useful to store all shots, to block repeat moves
        
        displayBoard(); // no need for functions to decide this, this will be called because of the results of class actions
        void shotFiredAtPoint(point&);
        bool isSea(point&) const;
        bool isShip(point&) const;
        
    public:
        Board();
        ~Board();
*/        point playerTurn(int, int);
};


#endif
