/* 
   File:   main
   Author: Brandon Orozco
   Created on March 10, 2017, 11:30 AM
   Purpose: Shift Array Elements
 */

// System Libraries
#include <iostream>   // Input/Output objects

using namespace std;  // Name-space used in the System Library

// User Libraries

// Global Constants

// Function prototypes
void printArray(int *, int, int);
int *shiftArray(int *, int);

// Execution Begins Here!
int main(int argc, char** argv) {
    // Declaration of Variables
    int size;  // Size of the array
    int *arry; // Array to be shifted
    
    // Get the array size
    do {
        cout << "Input the size of the array" << endl;
        cin >> size;
    } while (size <= 0);
    
    // Allocate the new array
    arry = new int[size];
    
    // Fill the array
    for (int i = 0; i < size; i++) {
        arry[i] = i;
    }
   
    //Print the array
    cout << "Original array:" << endl;
    printArray(arry, size, 100);
    
    // Shift the array
    arry = shiftArray(arry, size);
    
    // Print the shifted array
    cout << "Shifted array:" << endl;
    printArray(arry, size + 1, 100);
    
    // Delete the array
    delete [] arry;

    // Exit Program
    return 0;
}

//****************************** Print Array ***********************************
// Purpose: Print the array
// Input:   Input to function here -> Description, Range, Units
//      a    -> The array to print
//      size -> Size of array a
//      col  -> Number of columns to print it in
// Output:  Output to function here -> Description, Range, Units
void printArray(int *a, int size, int col) {
    for (int i = 0; i < size; i++) {
       cout << *(a + i) << "  ";
       if ((i + 1) % col == 0) cout << endl;
    }
    cout << endl;
}

//****************************** Shift Array ***********************************
// Purpose: Shift the array over 1 element
// Input:   Input to function here -> Description, Range, Units
//      a    -> The array to shift
//      size -> Size of array a
// Output:  Output to function here -> Description, Range, Units
//      a    -> a shifted over 1 element
int *shiftArray(int *a, int size) {
    int *nue; // The new shifted array
    nue = new int[size + 1]; // Allocate the new array
    nue[0] = 0; // Set the first element to 0
    
    // Copy the elements from the old to the new
    for (int i = 0; i < size; i++) {
        nue[i + 1] = a[i];
    }
    
    // Delete the original
    delete [] a;
    
    return nue; // Return the new array
}