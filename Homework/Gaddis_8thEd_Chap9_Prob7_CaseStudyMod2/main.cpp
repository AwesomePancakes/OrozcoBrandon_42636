/* 
   File:   main
   Author: Brandon Orozco
   Created on March 10, 2017, 1:42 PM
   Purpose: Sorting Donations
 */

// System Libraries
#include <iostream>   // Input/Output objects

using namespace std;  // Name-space used in the System Library

// User Libraries

// Global Constants

// Function prototypes
void arraySelectSort(int *[], int);
void showArray(const int [], int);
void showArrPtr(int *[], int);

// Execution Begins Here!
int main(int argc, char** argv) {
    // Declaration of Variables
    int nDonate;    // Number of donations
    int *donations; // Array of the donation amounts
    int **arrPtr;   // Array of pointers to donations
    
    // Get the number of donations
    do {
        cout << "Input the number of donations" << endl;
        cin >> nDonate;
    } while (nDonate <= 0);
    
    // Allocate the arrays
    donations = new int[nDonate];
    arrPtr = new int*[nDonate];
    
    // Get the donation amounts
    for (int i = 0; i < nDonate; i++) {
        do {
            cout << "Input the amount of donation #" << i + 1 << endl;
            cin >> donations[i];
        } while (donations[i] <= 0);
    }
    
    // Each element of arrPtr is a pointer to int. Make each
    // element point to an element in the donations array.
    for (int count = 0; count < nDonate; count++)
      arrPtr[count] = &donations[count];
    
    // Sort the elements of the array of pointers.
    arraySelectSort(arrPtr, nDonate);
   
    // Display the donations using the array of pointers. This
    // will display them in sorted order.
    cout << "The donations, sorted in descending order order are: \n";
    showArrPtr(arrPtr, nDonate);
    
    
    // Display the donations in their original order.
    cout << "The donations, in their original order are: \n";
    showArray(donations, nDonate);

    // Delete the arrays
    delete [] donations;
    delete [] arrPtr;
    
    // Exit Program
    return 0;
}

//****************************************************************
// Definition of function arraySelectSort.                         *
// This function performs an ascending order selection sort on   *
// arr, which is an array of pointers. Each element of array     *
// points to an element of a second array. After the sort,       *
// arr will point to the elements of the second array in         *
// ascending order.                                              *
//****************************************************************
void arraySelectSort(int *arr[], int size) {
    int startScan, minIndex;
    int *minElem;

    for (startScan = 0; startScan < (size - 1); startScan++) {
        minIndex = startScan;
        minElem = arr[startScan];
        for(int index = startScan + 1; index < size; index++) {
            if (*(arr[index]) > *minElem) {
                minElem = arr[index];
                minIndex = index;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minElem;
    }
}

//*************************************************************
// Definition of function showArray.                          *
// This function displays the contents of arr. size is the    *
// number of elements.                                        *
//*************************************************************
void showArray(const int arr[], int size){
    for (int count = 0; count < size; count++)
        cout << arr[count] << " ";
    cout << endl;
}

//**************************************************************
// Definition of function showArrPtr.                          *
// This function displays the contents of the array pointed to *
// by arr. size is the number of elements.                     *
//**************************************************************
void showArrPtr(int *arr[], int size) {
    for (int count = 0; count < size; count++)
        cout << *(arr[count]) << " ";
    cout << endl;
}