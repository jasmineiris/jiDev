// File: poker_hand.cpp
// Author: Jasmine Farrell
// Date: Sep. 12, 2015
// Course: cs110b
// Description: the programs reads five cards from the user, then analyzes the
// cards and prints out the category of hand that they represent. 
// Usage: Collect five integer values from the user. ex: Card 1: X, Card 2: X
// user input integer value '5' Card 1:'5'


#include<iostream>
using namespace std;

//Declaring a contant for user's card hand
const int HANDSIZE = 5;

//function prototypes
void getHand(int (&hand)[HANDSIZE]);
bool containsPair(int hand[]);
bool containsTwoPair(int hand[]);
bool containsThreeOfaKind(int hand[]);
bool containsStraight(int hand[]); 
bool containsFullHouse(int hand[]);
bool containsFourOfaKind(int hand[]);

int main() {
    //array declaring user's hand size
    int hand[HANDSIZE];
    cout << "Enter five numeric cards, no face cards. Use 2-9." << endl;        
    getHand(hand);
    //loop to evaluate user's hand
    if (containsFourOfaKind(hand)) {
        cout << "Four of a Kind! I personally prefer to be one of a kind." << endl;        
    } else if (containsFullHouse(hand)) {
        cout << "Full House! Do you remember that show?" << endl;
    } else if (containsStraight(hand)) {
        cout << "Straight! Well played, my friend." << endl;
    } else if (containsThreeOfaKind(hand)) {
        cout << "Three of a kind! Ménage à trois." << endl;
    } else if (containsTwoPair(hand)) {
        cout << "Two Pair!" << endl;
    } else if (containsPair(hand)) {
        cout << "Pair!" << endl;
    } else cout << "High card!" << endl;
    return 0;
}
//function to gather input from user's hand
void getHand(int (&hand)[HANDSIZE])
{
    for(int i = 0; i < HANDSIZE; i++)
    {
        do {      
        cout << "Card " << i+1 << ":" << endl;
        cin >> hand[i];
        }
        while (hand[i] > 9 || hand[i] < 2);  
    }
}
//function declarations:
//user's hand values are arranged in numeric order
bool containsStraight(int hand[])
{
    //intializing variables
    int max = 1;
    int min = 10;
    
    for (int i = 0; i < HANDSIZE; i++)
    {
        if (max < hand[i])
        {
            max = hand[i];
        } 
             
        if (min > hand[i])
        {
            min = hand[i];
        }
    }   
    if (max - min != 4)
    {
        return false;       
    }    

    if (containsPair(hand) || containsTwoPair(hand) || 
            containsThreeOfaKind(hand) || containsFourOfaKind(hand))
    {
        return false;
    }     
    return true;     
}
//user's hand values contain a single pair and three of a kind  
bool containsFullHouse(int hand[])
{
    if (containsTwoPair(hand) && containsThreeOfaKind(hand))
    {
        return true;
    }
}
//user's hand values contain a single pair 
bool containsPair(int hand[])
{    
    int repeated;
    for (int i = 0; i < HANDSIZE; i++)
    {
        repeated = 0;
        for (int j = 0; j < HANDSIZE; j++)
        { 
            if (hand[i] == hand[j])
            {   
               repeated++;
            } 
        }
        if (repeated == 2)
        {
            return true;
        }    
    } 
    return false;
}
//user's hand contains two pairs of values.
bool containsTwoPair(int hand[])
{
    int repeated;
    for (int i = 0; i < HANDSIZE; i++)
    {
        repeated = 0;
        for (int j = 0; j < HANDSIZE; j++)
        {
            if (hand[i] == hand[j])
            {
                repeated++;
            }
        }
        if (repeated == 2)
        {
            return true;
        }
    }
    return false;
}
//user's hand contains three of the same value.
bool containsThreeOfaKind(int hand[])
{
    int repeated;
    for (int i = 0; i< HANDSIZE; i++)
    {
        repeated = 0;
        for (int j = 0; j < HANDSIZE; j++)
        {
            if (hand[i] == hand[j])
            {
                repeated++;
            }
        }
   
        if (repeated == 3)
        {
            return true;
        }
    }
    return false;
}
//user's hand contains four of the same value.
bool containsFourOfaKind(int hand[])
{
    int repeated;
    for (int i = 0; i< HANDSIZE; i++)
    {
        repeated = 0;
        for (int j = 0; j < HANDSIZE; j++)
        {
            if (hand[i] == hand[j])
            {
                repeated++;
            }
        }
        if (repeated == 4)
        {
            return true;
        }
    }
    return false;
}

/*
[jfarrel6@hills hw]$ g++ poker_hands.cpp 
[jfarrel6@hills hw]$ a.out

Enter five numeric cards, no face cards. Use 2-9.
Card 1:
2
Card 2:
3
Card 3:
4
Card 4:
5
Card 5:
6
Straight! Well played, my friend.
[jfarrel6@hills hw]$ a.out
Enter five numeric cards, no face cards. Use 2-9.
Card 1:
3
Card 2:
3
Card 3:
3
Card 4:
4
Card 5:
4
Full House! Do you remember that show?
[jfarrel6@hills hw]$ a.out
Enter five numeric cards, no face cards. Use 2-9.
Card 1:
4
Card 2:
4
Card 3:
5
Card 4:
5
Card 5:
6
Two Pair!
[jfarrel6@hills hw]$ a.out
Enter five numeric cards, no face cards. Use 2-9.
Card 1:
7
Card 2:
7
Card 3:
7
Card 4:
2
Card 5:
3
Three of a kind! Ménage à trois.
[jfarrel6@hills hw]$ a.out
Enter five numeric cards, no face cards. Use 2-9.
Card 1:
9
Card 2:
4
Card 3:
7
Card 4:
5
Card 5:
1
Card 5:
2
High card!
[jfarrel6@hills hw]$ a.out
Enter five numeric cards, no face cards. Use 2-9.
Card 1:
6
Card 2:
5
Card 3:
5
Card 4:
5
Card 5:
5
Four of a Kind! I personally prefer to be one of a kind.
[jfarrel6@hills hw]$ a.out
Enter five numeric cards, no face cards. Use 2-9.
Card 1:
456
Card 1:
456
Card 1:
4
Card 2:
1
Card 2:
1
Card 2:
2
Card 3:
*\
