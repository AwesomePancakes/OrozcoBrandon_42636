/* 
   File:   main
   Author: Brandon Orozco
   Created on March 10, 2017, 11:13 AM
   Purpose: Rewrite Function With Pointers
 */

// System Libraries
#include <iostream>   // Input/Output objects

using namespace std;  // Name-space used in the System Library

// User Libraries

// Global Constants

// Function prototypes
int doSomething(int *, int *);

// Execution Begins Here!
int main(int argc, char** argv) {
    // Declaration of Variables
    int *a, *b;
    
    // Input values
    cout << "Input two numbers" << endl;
    cin >> *a >> *b;
    
    // Display Output
    cout << "Do something: " << doSomething(a, b) << endl;
    cout << "Originals: " << *a << " " << *b << endl;

    // Exit Program
    return 0;
}

//****************************** Do Something **********************************
// Purpose: Function from book rewrote with pointers
// Input:   Input to function here -> Description, Range, Units
//      x    -> Pointer to first varaible
//      y    -> Pointer to second variable
// Output:  Output to function here -> Description, Range, Units
//      int  -> A calculation using x and y
int doSomething(int *x, int *y){
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}