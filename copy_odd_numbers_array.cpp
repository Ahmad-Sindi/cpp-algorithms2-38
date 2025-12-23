/* Algorithm Challenge & Problem Solving
 * 38 - Copy Odd Numbers to a New Array
 *
 * This program fills an array with random numbers between 1 and 100, then copies only the odd numbers into another array using the AddArrayElement function.
 *
 * The challenge focuses on filtering data while copying arrays, and simulating dynamic behavior using a fixed-size array.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Generates a random number within a specific range
int RandNumber(int From, int To)
{
    int Rand = rand() % (To - From + 1) + From;
    return Rand;
}

// Fills the array with random numbers based on user-defined length
void FillArrayWhithRandomNumber(int arr[100], int &arrlength)
{
    cout << "Enter number of elements:\n";
    cin >> arrlength;

    for (int i = 0; i < arrlength; i++)
    {
        arr[i] = RandNumber(1, 100);
    }
}

// Prints all elements of an array
void PrintArray(int arr[100], int arrlength)
{
    for (int i = 0; i < arrlength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Adds a single element to the array and updates its length
void AddArrayElement(int Number, int arr[100], int &arrlength)
{
    arrlength++;                 // Increase array length
    arr[arrlength - 1] = Number; // Insert element at the correct position
}

// Copies only odd numbers from source array to destination array
void OddArrayUsindAddArrayElement(
    int arrSource[100],
    int arrDistination[100],
    int arrlength,
    int &arrDistinationLength)
{
    for (int i = 0; i < arrlength; i++)
    {
        // Check if the number is odd
        if (arrSource[i] % 2 != 0)
        {
            AddArrayElement(arrSource[i], arrDistination, arrDistinationLength);
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrlength = 0;
    int arr2[100], arr2length = 0;

    // Fill the original array
    FillArrayWhithRandomNumber(arr, arrlength);

    // Copy only odd numbers to the second array
    OddArrayUsindAddArrayElement(arr, arr2, arrlength, arr2length);

    cout << "Array 1 Elements: ";
    PrintArray(arr, arrlength);

    cout << "\nOdd Numbers Array: ";
    PrintArray(arr2, arr2length);

    return 0;
}
