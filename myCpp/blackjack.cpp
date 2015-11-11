// File: blackjack.cpp 
// Author: Jasmine Farrell
// Date: Aug. 28th, 2015
// Course: cs110b
// Description: The program generates random numbers between 1 to 10.
// User loses if total numbers is  over 21. 
// Usage: Call 'BlackJack' from terminal and follow the prompts

#include<ctime>
#include<cstdlib>
#include<iostream>
using namespace std;


int main ()
{
    int total_num; //Player's score
    int card_1, card_2; //Player's showing card variables 
    int dealer_1; //Dealer showing card variable
    int dealer_total; //Total cards dealt to dealer
    char hit = 'y'; //Take another hit if player wants another card
    char play_again = 'y'; //Prompts game to play again if user states 'y'
    srand (time(NULL)); //Random seed; ensures a unique starting point   

    while ( play_again == 'y') //Full game loop;if user states 'y' repeat game
    {
        //cards are dealt random numbers between 1 to 10
        dealer_1 = rand() % 10 + 1; 
        card_1 = rand() % 10 + 1;
        card_2 = rand() % 10 + 1;
        total_num = card_1 + card_2;    

        cout << "Dealer's card: ";
        cout << dealer_1 << endl;
        cout << "Your hand: ";
        cout << card_1 << ", " << card_2 << endl;

        do //Ask user to take a new card
        {
            cout << "Hand total " << total_num << "!\n";
            cout << "Feeling lucky?? Take a chance! Take a hit?! y or n? "; 
            cin >> hit; 
                
            if (hit == 'y') //if user states 'y' take a new card
            {
                card_1 = rand() % 10 + 1;
                cout << "New card: ";
                cout << card_1 << endl;
                total_num = card_1 + total_num;      
            } 
                    
        // User takes another card and total user's number is equal or less than 21 
        } while (hit != 'n' && total_num <= 21); 

        cout << "FINAL hand " << total_num << "!\n";

        // User's total hand is greater than 21, user loses; prompts user to play again
        if (total_num > 21) 
        {
            cout << "BUST!\n"; 
            cout << "Do you want to play again? y or n \n";
            cin >> play_again;            
             
        } else {  

            //Automate second card for dealer
            dealer_total = dealer_1; 
            dealer_1 = rand() % 10 + 1; 
            cout << "Dealer's second card: ";
            cout << dealer_total << endl;                
            dealer_total = dealer_total + dealer_1;            

           //Automate additional dealer cards until it's less than 17   
           while (dealer_total < 17)
            {
                cout << "Dealer gets a hit!\n";
                dealer_1 = rand() % 10 + 1;
                cout << dealer_1 << endl;
                cout << "Dealer's total: ";
                dealer_total = dealer_1 + dealer_total;
                cout << dealer_total << endl;
            } 
            
            //Dealer win's if total cards is greater than user cards and under or equal to 21
            if (dealer_total > total_num && dealer_total <= 21)
            {
                cout << "Dealer's the winner! Try your luck again? y or n\n";
                cin >> play_again;
 
           //Dealer and user ties than prompts user to play again 
            } else if (dealer_total == total_num) {
     
                cout << "Push! Win or lose, there's always the holosuite.\n";
                cout << "Try your luck again? y or n\n";
                cin >> play_again; 
     
            } else {
                
               //User win's if non of the other conditions are met 
                cout << "Winner! I guess it's you're lucky day! Try your luck again? y or n\n";
                cin >> play_again;
            }
        }
    }
    return 0;
}
/*
[jfarrel6@hills hw]$ vim blackjack.cpp 
[jfarrel6@hills hw]$ g++ blackjack.cpp 
[jfarrel6@hills hw]$ a.out
Dealer's card: 4
Your hand: 7, 8
Hand total 15!
Feeling lucky?? Take a chance! Take a hit?! y or n? y
New card: 6
Hand total 21!
Feeling lucky?? Take a chance! Take a hit?! y or n? n
FINAL hand 21!
Dealer's second card: 4
Dealer gets a hit!
6
Dealer's total: 14
Dealer gets a hit!
7
Dealer's total: 21
Push! Win or lose, there's always the holosuite.
Try your luck again? y or n
y
Dealer's card: 3
Your hand: 10, 2
Hand total 12!
Feeling lucky?? Take a chance! Take a hit?! y or n? y
New card: 3
Hand total 15!
Feeling lucky?? Take a chance! Take a hit?! y or n? y
New card: 8
FINAL hand 23!
BUST!
Do you want to play again? y or n 
y
Dealer's card: 1
Your hand: 10, 4
Hand total 14!
Feeling lucky?? Take a chance! Take a hit?! y or n? n
FINAL hand 14!
Dealer's second card: 1
Dealer gets a hit!
1
Dealer's total: 9
Dealer gets a hit!
7
Dealer's total: 16
Dealer gets a hit!
3
Dealer's total: 19
Dealer's the winner! Try your luck again? y or n
n
[jfarrel6@hills hw]$ 
*/
