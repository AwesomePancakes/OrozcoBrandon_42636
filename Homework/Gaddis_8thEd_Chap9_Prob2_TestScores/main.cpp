/* 
   File:   main
   Author: Brandon Orozco
   Created on March 10, 2017, 12:12 AM
   Purpose: Average/Sort Test Scores
 */

// System Libraries
#include <iostream>   // Input/Output objects

using namespace std;  // Name-space used in the System Library

// User Libraries

// Global Constants

// Function prototypes
float averageScore(float *, int);
void markSrt(float *, int);
void outputArray(float *, int, int);

// Execution Begins Here!
int main(int argc, char** argv) {
    // Declaration of Variables
    int nTests; // Number of tests taken
    float avg; // Average test score
    float *scores; // Scores of each test
    
    // Input values
    do {
        cout << "Input the number of tests taken" << endl;
        cin >> nTests;
    } while (nTests <= 0);
    
    scores = new float[nTests]; // Initialize the array
    
    // Get the test scores
    for (int i = 0; i < nTests; i++) {
        do {
            cout << "Input the score on test #" << i + 1 << endl;
            cin >> *(scores + i);
        } while (*(scores + i) < 0);
    }
    
    // Process values -> Map inputs to Outputs
    markSrt(scores, nTests); // Sort the array
    avg = averageScore(scores, nTests); // Get the average score
    
    // Display Output
    cout << "Average Score = " << avg << endl;
    cout << "Sorted Scores:" << endl;
    outputArray(scores, nTests, 1);

    // Delete the array
    delete [] scores;
    
    // Exit Program
    return 0;
}

//****************************** Output Array ***********************************
// Purpose: Output the array
// Input:   Input to function here -> Description, Range, Units
//      a    -> The array to Output
//      size -> Size of array a
//      col  -> Number of columns to Output it in
// Output:  Output to function here -> Description, Range, Units
void outputArray(float *a, int size, int col) {
    for (int i = 0; i < size; i++) {
       cout << *(a + i) << "  ";
       if ((i + 1) % col == 0) cout << endl;
    }
}

//******************************** Mark Sort ***********************************
// Purpose: Sort the array using a simple mark sort
// Input:   Input to function here -> Description, Range, Units
//      a    -> The array to sort
//      size -> Size of array a
// Output:  Output to function here -> Description, Range, Units
//      a   -> The original a sorted in ascending order
void markSrt(float *a, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(a + i) > *(a + j)) {
                *(a + i) = *(a + i) ^ *(a + j);
                *(a + j) = *(a + i) ^ *(a + j);
                *(a + i) = *(a + i) ^ *(a + j);
            }
        }
    }
}

//**************************** Average Score ***********************************
// Purpose: Find the average of an array of test scores
// Input:   Input to function here -> Description, Range, Units
//      a    -> The array to average
//      size -> Size of array a
// Output:  Output to function here -> Description, Range, Units
//      float -> The average of the elements of a
float averageScore(float *a, int size) {
    float sum = 0; // Sum of all the element in a
    
    for (int i = 0; i < size; i++) {
        sum += *(a + i);
    }
    
    return sum / size;
}