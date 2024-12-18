#include <iostream>
using namespace std;

// Function template for Selection Sort
template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        // Find the minimum element in the unsorted portion
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the minimum element with the first element of the unsorted portion
        if (minIndex != i) {
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Function template to print an array
template <typename T>
void printArray(const T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function template to input an array
template <typename T>
void inputArray(T arr[], int size) {
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

int main() {
    int intSize, floatSize;

    // Input for integer array
    cout << "Enter the number of elements in the integer array: ";
    cin >> intSize;
    int* intArray = new int[intSize]; // Dynamically allocate memory for the integer array
    inputArray(intArray, intSize);

    // Input for float array
    cout << "Enter the number of elements in the float array: ";
    cin >> floatSize;
    float* floatArray = new float[floatSize]; // Dynamically allocate memory for the float array
    inputArray(floatArray, floatSize);

    // Display original arrays
    cout << "\nOriginal Integer Array: ";
    printArray(intArray, intSize);
    cout << "Original Float Array: ";
    printArray(floatArray, floatSize);

    // Sorting the arrays
    selectionSort(intArray, intSize);
    selectionSort(floatArray, floatSize);

    // Display sorted arrays
    cout << "\nSorted Integer Array: ";
    printArray(intArray, intSize);
    cout << "Sorted Float Array: ";
    printArray(floatArray, floatSize);

    // Free allocated memory
    delete[] intArray;
    delete[] floatArray;

    return 0;
}
