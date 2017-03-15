/* 
   File:   main
   Author: Brandon Orozco
   Created on March 10, 2017, 4:12 PM
   Purpose: Median Function
 */

// System Libraries
#include <iostream>   // Input/Output objects

using namespace std;  // Name-space used in the System Library

// User Libraries

// Global Constants

// Function prototypes
void outputArray(int *, int, int);
void markSort(int *, int);
float median(int *, int);

// Execution Begins Here!
int main(int argc, char** argv) {
    // Declaration of Variables
    int size;
    int *array;
    
    // Input values
    do {
        cout << "Input array size: " << endl;
        cin >> size;
    } while (size <= 0);
    
    // Allocate the array
    array = new int[size];
    
    //Fill the array
    for (int index= 0; index< size; index++) {
        *(array + index) = index;
    }
    
    // Output the array
    cout << "Array:" << endl;
    outputArray(array, size, 100);
    
    // Calculate the median
    cout << "Median: " << median(array, size) << endl;
    
    // Delete the array
    delete [] array;

    // Exit Program
    return 0;
}

//****************************** Output Array ***********************************
// Purpose: Output the array
// Input:   Input to function here -> Description, Range, Units
//      array   -> The array to Output
//      size -> Size of the array
//      col  -> Number of columns to Output it in
// Output:  Output to function here -> Description, Range, Units
void outputArray(int *array, int size, int col) {
    for (int index= 0; index< size; index++) {
       cout << *(array+ index) << "  ";
       if ((index+ 1) % col == 0) cout << endl;
    }
    cout << endl;
}

//******************************** Mark Sort ***********************************
// Purpose: Sort the array using a simple mark sort
// Input:   Input to function here -> Description, Range, Units
//      array   -> The array to sort
//      size -> Size of the array
// Output:  Output to function here -> Description, Range, Units
//      array  -> The original array sorted in ascending order
void markSort(int *array, int size) {
    for (int index= 0; index< size; index++) {
        for (int sort = index+ 1; sort < size; sort++) {
            if (*(array+ index) > *(array+ sort)) {
                *(array+ index) = *(array+ index) ^ *(array+ sort);
                *(array+ sort) = *(array+ index) ^ *(array+ sort);
                *(array+ index) = *(array+ index) ^ *(array+ sort);
            }
        }
    }
}

//********************************* Median ************************************
// Purpose: Calculate the median of the array
// Input:   Input to function here -> Description, Range, Units
//      array   -> The array to find median of
//      size -> Size of the array
// Output:  Output to function here -> Description, Range, Units
//      float -> median of a
float median(int *array, int size) {
    // Sort the array first
    markSort(array, size);
    
    // Find the median
    if (size % 2 == 1) {
        return *(array+ size / 2);
    } else {
        return (*(array+ size / 2) + *(array+ size / 2 - 1)) / 2.0f;
    }
}