/* 
   File:   main
   Author: Brandon Orozco
   Created on March 10, 2017, 3:13 PM
   Purpose: Mode Function
 */

// System Libraries
#include <iostream>   // Input/Output obsortects
#include <cstdlib>    // Random number seed
#include <ctime>      // Seed the random number generator

using namespace std;  // Name-space used in the System Library

// User Libraries

// Global Constants

// Function prototypes
void outputArray(int *, int, int);
void markSort(int *, int);
int *storeMode(int *, int, int &, int &);
void fillArray(int *, int, int);

// Execution Begins Here!
int main(int argc, char** argv) {
    
    // Set the random number generator seed
    srand(static_cast<unsigned int>(time(0)));
    
    // Declaration of Variables
    int size; // Size of the array
    int maximum;  // maximum value of the array
    int frequency; // frequency of the mode
    int numOfElements; // Number of elements in the mode
    int *array; // The array to find the mode of
    int *mode;   // Mode of array
    
    // Get the size
    do {
        cout << "Input array size: " << endl;
        cin >> size;
    } while (size <= 0);
    
    // Get the maximum value to fill
    do {
        cout << "Input maximum: "  << endl;
        cin >> maximum;
    } while (maximum <= 0);
    
    // Allocate the array
    array = new int[size];
    
    // Fill the array
    fillArray(array, size, maximum);
    
    // Print the array
    cout << "Original array: " << endl;
    outputArray(array, size, 10);
    
    // Get the mode
    mode = storeMode(array, size, frequency, numOfElements);

    // Print the mode
    cout << "Mode: " << endl;
    outputArray(mode, numOfElements, 10);
    
    // Print some info
    cout << "Frequency: " << frequency << endl;
    cout << "# of Elements: " << numOfElements << endl;
    
    // Delete the arrays
    delete [] array;
    delete [] mode;
    
    // Exit Program
    return 0;
}

int *storeMode(int *array, int size, int &frequency, int &nElemnt) {
    int *m; // The final mode array
    frequency = 0; // frequency of the mode
    nElemnt = 1; // Number of elements of the mode
    
    // Sort the array
    markSort(array, size);
    
    // Find the highest frequency and the number of elements
    int currentFreq = 1;
    for (int index= 1; index< size; index++) {
        if (array[index] == array[index- 1]) {
            currentFreq++;
            if (currentFreq == frequency) nElemnt++;
            if (currentFreq > frequency) {
                frequency = currentFreq;
                nElemnt = 1;
            }
        } else currentFreq = 1;
    }
    
    // Allocate the mode array
    m = new int[nElemnt];
    
    // Fill the mode array
    int indx = 0;
    currentFreq = 1;
    for (int count = 1; count < size; count++) {
        if (array[count] == array[count - 1]) {
            currentFreq++;
            if (currentFreq == frequency) {
                m[indx] = array[count];
                indx++;
            }
        } else currentFreq = 1;
    }
    
    return m;
}



void fillArray(int *array, int size, int maximum) {
    for (int index= 0; index< size; index++) {
        array[index] = rand() % maximum + 1;
    }
}

//****************************** Print Array ***********************************
// Purpose: Print the array
// Input:   Input to function here -> Description, Range, Units
//      array   -> The array to print
//      size -> Size of the array 
//      col  -> Number of columns to print it in
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
//      size -> Size of array a
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