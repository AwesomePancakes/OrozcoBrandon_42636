/* 
   File:   main
   Author: Brandon Orozco
   Created on March 10, 2017, 11:13 AM
   Purpose: Reverse Array
 */

// System Libraries
#include <iostream>   // Input/Output objects

using namespace std;  // Name-space used in the System Library

// User Libraries

// Global Constants

// Function prototypes
void outputArray(int *, int, int);
void reverseArray(int [], int);

// Execution Begins Here!
int main(int argc, char** argv) {
    // Declaration of Variables
    int size;  // Size of the array
    int *array; // Array to be reversed
    
    // Get the array size
    do {
        cout << "Input array size: " << endl;
        cin >> size;
    } while (size <= 0);
    
    // Allocate the new array
    array = new int[size];
    
    // Fill the array
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }
   
    //Output the array
    cout << "Original array:" << endl;
    outputArray(array, size, 100);
    
    // Reverse the array
    reverseArray(array, size);
    
    // Output the reversed array
    cout << "Reversed array:" << endl;
    outputArray(array, size, 100);
    
    // Delete new data
    delete [] array;

    // Exit Program
    return 0;
}

//****************************** Output Array ***********************************
// Purpose: Output the array
// Input:   Input to function here -> Description, Range, Units
//      array  -> The array to Output
//      size   -> Size of the array
//      cols   -> Number of columns to Output it in
// Output:  Output to function here -> Description, Range, Units
void outputArray(int *array, int size, int cols) {
    for (int index = 0; index < size; index++) {
       cout << *(array + index) << "  ";
       if ((index + 1) % cols == 0) cout << endl;
    }
    cout << endl;
}

//***************************** Reverse Array **********************************
// Purpose: Reverse the array
// Input:   Input to function here -> Description, Range, Units
//      array -> The array to reverse
//      size  -> Size of the array
// Output:  Output to function here -> Description, Range, Units
//      a    -> The reversed array
void reverseArray(int array[], int size) {
    for (int index = 0; index < size / 2 + 1; index++) {
        int temp = array[index];
        array[index] = array[size - index - 1];
        array[size - index - 1] = temp;
    }
}