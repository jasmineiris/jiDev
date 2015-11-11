// File: num-guesser.cpp
// Author: Jasmine Farrell
// Date: Sept. 5th, 2015
// Course: cs110b
// Description: Guesses the user's number by asking higher or lower between 1 to 10//until final guess is made by program.

#include<iostream>
#include<cstdlib>
using namespace std;

//function prototypes
void playOneGame();
int getMidpoint(int, int);
int getRandomMidpoint(int,int);
char getUserResponseToGuess(int);

//function declarations
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

void playOneGame()
{
    //initializing variables 
    int low = 1;
    int high = 100;
    char resp;    
    int guess;

    cout << "Think of a number between 1 and 100.\n";
    do 
    {
        //loop to evaluate guesses
        guess = getRandomMidpoint(low, high);
        resp = getUserResponseToGuess(guess);
        if (resp == 'l')
        {
            high = guess;
        } else if (resp == 'h')
        {
            low = guess;
        }      
    } while (resp != 'c');
    
    return;   
}

int getRandomMidpoint(int low, int high)
{ 
    //gets random num between low - high
    srand (time(NULL));//ensures random initial seed
    return rand() % (high - low) + low; 
}    

int getMidpoint(int low, int high) 
{
    //formula for midpoint
    return (low + high)/ 2; 
}

char getUserResponseToGuess(int guess)
{
    //returns response from user
    char resp;
    cout << "Is it " << guess << "? (h, l, c):\n";
    cin >> resp;
    return resp;
}

//below is main funtion
int main()
{
    do
    {
        playOneGame();
    } while (shouldPlayAgain());

    return 0;
}

/*[jfarrel6@hills ~]$ vim num_guesser.cpp 
 * [jfarrel6@hills ~]$ g++ num_guesser.cpp 
 * [jfarrel6@hills ~]$ a.out
 * Think of a number between 1 and 100.
 * Is it 50? (h, l, c):
 * l
 * Is it 25? (h, l, c):
 * h
 * Is it 37? (h, l, c):
 * c
 * Do you want to play again?(y/n)
 * f
 * Do you want to play again?(y/n)
 * w
 * Do you want to play again?(y/n)
 * y
 * Think of a number between 1 and 100.
 * Is it 50? (h, l, c):
 * c
 * Do you want to play again?(y/n)
 * n
 */
/*[jfarrel6@hills ~]$ a.out
 * Think of a number between 1 and 100.
 * Is it 76? (h, l, c):
 * l
 * Is it 47? (h, l, c):
 * h
 * Is it 55? (h, l, c):
 * l
 * Is it 51? (h, l, c):
 * l
 * Is it 47? (h, l, c):
 * h
 * Is it 49? (h, l, c):
 * l
 * Is it 48? (h, l, c):
 * c
 * Do you want to play again?(y/n)
 * y
 * Think of a number between 1 and 100.
 * Is it 63? (h, l, c):
 * h
 * Is it 74? (h, l, c):
 * h
 * Is it 97? (h, l, c):
 * l
 * Is it 96? (h, l, c):
 * l
 * Is it 91? (h, l, c):
 * l
 * Is it 82? (h, l, c):
 * h
 * Is it 86? (h, l, c):
 * h
 * Is it 88? (h, l, c):
 * l
 * Is it 86? (h, l, c):
 * h
 * Is it 87? (h, l, c):
 * c
 * Do you want to play again?(y/n)
 * n
 * [jfarrel6@hills ~]$ 
 * */
