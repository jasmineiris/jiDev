// File: pointerTasks.cpp
// Author: Jasmine Farrell
// Date: Oct. 3rd, 2015
// Course: CS110B
// Description: practicing pointers with main function and void functions 

#include<iostream>
using namespace std;

void noNegatives(int *p1);
void swap(int *x, int *y);

int main()
{
    //two integer variables named x and y
    int x;
    int y;
    //int pointer named p1,Store the address of x in p1,
    //p1 to set the value of x to 99
    int *p1 = NULL;
    p1 = &x;
    *p1 = 99;

    //cout and x, display the value of x 
    //cout and the pointer p1, display the value of x    
    cout << x << endl;
    cout << *p1 << endl;
    
    //Store the address of y into p1
    //Use p1 to set the value of y to -300
    p1 = &y;
    *p1 = -300;

    //Created two new variables:
    //int named temp, and an int pointer named p2
    //Use temp, p1, and p2 to swap the values in x and y
    int temp = *p1;
    int *p2 = NULL;
    p2 = &x;
    *p1 = *p2;
    *p2 = temp;
    
    //Invoke the function twice: once with the address of x as the argument,
    //and once with the address of y 
    noNegatives(&x);
    noNegatives(&y);

    //p2 to display the values in x and y
    cout << *p2 << endl;    
    p2 = &y;
    cout << *p2 << endl;

    //an int array with two elements using 'a'
    int a[2];
    //p2 to initialize the first element of a with the value of x
    p2 = &x;
    //p2 to initialize the second element of a with the value of y
    a[0] = *p2;
    p2 = &y;
    a[1] = *p2;

    //cout, display the address of the first element in a
    //cout display the address of the second element in a
    cout << "From Array a:\n";
    cout << a[0] << endl;
    cout << a[1] << endl;

    //p1, p2, and temp to swap the values in the two elements of array ‘a’. 
    cout << "Swapping\n";   
    p1 = &a[0];
    p2 = &a[1];
    
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    
    //Display the values of the two elements
    cout << "From Array a:\n";
    cout << a[0] << endl;
    cout << a[1] << endl;

    //Invoke your swap function with the addresses of x and y, 
    //then print their values.     
    cout << "Swapping x and y\n";
    swap(&x, &y);
    cout << x << endl;
    cout << y << endl;

    //Invoke your swap function with the address of 
    //the two elements in array ‘a’, then print their values.    
    cout << "Swapping A\n";
    swap(a[0],a[1]);
    cout << a[0] << endl;
    cout << a[1] << endl;     
}

//Accept the address of an int variable. 
//If the value of this integer is negative then it should set it to zero
void noNegatives(int *x)
{  
    if ( *x < 0 )
        *x = 0;   
}

//accepts two integer addresses as arguments, 
//and then swaps the contents of the two integers.
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;   
}

/*[jfarrel6@hills hw]$ g++ pointerTasks.cpp 
[jfarrel6@hills hw]$ a.out
99
99
0
99
From Array a:
0
99
Swapping
From Array a:
99
0
Swapping x and y
99
0
Swapping A
0
99
*/