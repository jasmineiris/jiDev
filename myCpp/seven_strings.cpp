// File:seven_strings.ccp
// Author: Jasmine Farrell
// Date: Oct. 13th, 2015
// Course: cs110b
// Description: The program genrates different out comes for phrases. ex: reverse, replace, 
// swap and Palindrome.
// Usage: Type Phrase.


#include<iostream>
using namespace std;

int lastIndexOf(char *s, char target);
void reverse(char *s);
int replace(char *s, char target, char replacementChar);
int findSubstring(char *s, char substring[]);
bool isPalindrome(char *s);
int length(char *s);
void swapper(char *x, char *y);
void printout(char *s);

const int MAX_CHARS = 128;


int main()
{
char phrase[MAX_CHARS];
char sub[] = "ise";
cout<< "What is your phrase?\n";
cin>> phrase;
int li = lastIndexOf(phrase, 't');
cout<< li;
cout << endl;
printout(phrase);
replace(phrase, 't', 'T');
printout(phrase);
li = findSubstring(phrase, sub);
cout<< li;
cout << endl;
printout(phrase);
if (isPalindrome(phrase))
{
    cout<< "It's a PALINDROME!!!\n";
}
printout(phrase);
reverse(phrase);
printout(phrase);
}

void printout(char *s)
{
    for (int i = 0; i < length(s); i++)
    {
        cout<< s[i];
    }
    cout<< endl;
}
void swapper(char *x, char *y) 
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

int length(char *s) 
{
    for (int i = 0; i < MAX_CHARS; i++)
    {
        if (s[i] == '\0')
        return i;
    }
}
//*This function returns the last index where the target char can be found in 
//the string. it returns -1 if the target char does not appear in the string. 
int lastIndexOf(char *s, char target)
{
    for (int i = length(s)-1; i >= 0 ;i--)
    {
        if (s[i] == target)
        {
            return i;
        }
    }
    return -1;
}


//This function alters any string that is passed in.It should reverse the string
void reverse(char *s)
{
    int l = length(s);
    for (int i = 0; i < (l/2); i++)
    {
        swapper(&s[i],&s[l-1-i]);
    }   
}

//This function finds all instances of the char ‘target’ in the string and replaces them with ‘replacementChar’.
int replace(char *s, char target, char replacementChar)
{
    int count = 0;
    for (int i = 0; i < length(s); i++)
    { 
        if (s[i] == target)
        {
            s[i] = replacementChar;
            count++;
        }
    }
    return count;   
}

//This function returns the index in string s where the substring can first be found. For example if s is “Skyscraper” and substring is “ysc” the function would return 2.  It should return -1 if the substring does not appear in the string.
int findSubstring(char *s, char substring[])
{
    for (int i = 0; i < length(s); i++)
    {
        for (int j = 0; j < length(substring); j++)
        {
            if (s[i+j] != substring[j])
            {
                break;
            } else if (j == length(substring)-1)
            {
                return i;
            }   
        }
    } 
}
//This function returns true if the argument string is a palindrome. It returns false if it is not.  
bool isPalindrome(char *s)
{
    int l = length(s);
    for (int i = 0; i <= l/2; i++)
    {
        if (s[i] != s[l-1-i])
        {
            return false;
        }
    }
    return true;
}

//Extra Credit, up to 10 extra points.  This function should reverse the words in a string.  A word can be considered to be any characters, including punctuation, separated by spaces (only spaces, not tabs, \n etc.).  So, for example, if s is “The Giants won the Pennant!” the function should change s to “Pennant! the won Giants The”
//void reverseWords(char *s)

/*[jfarrel6@hills hw]$ g++ seven_strings.cpp
 * [jfarrel6@hills hw]$ a.out
 * What is your phrase?
 * exitiseesitixe
 * 10
 * exitiseesitixe
 * exiTiseesiTixe
 * 4
 * exiTiseesiTixe
 * It's a PALINDROME!!!
 * exiTiseesiTixe
 * exiTiseesiTixe
 * [jfarrel6@hills hw]$ a.out
 * What is your phrase?
 * jasmine
 * -1
 *  jasmine
 *  jasmine
 *  0
 *  jasmine
 *  jasmine
 *  enimsaj
 */
