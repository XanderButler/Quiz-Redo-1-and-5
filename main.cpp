#include <iostream>
#include <fstream>

const int MAX_ARRAY = 1000;

// populate array from file
void populateArray(int array[], int& size) {
    std::ifstream inputFile("input.txt"); // file is replaceable, or just edit contents of file
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file\n";
        exit(EXIT_FAILURE);
    }

    size = 0;
    while (size < MAX_ARRAY && inputFile >> array[size]) {
        size++;
    }

    inputFile.close();
}

// print contents of array
void printArray(const int array[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

// calculates average of array
float calculateAverage(const int array[], int size) {
    if (size == 0) {
        return 0.0; // Avoid division by zero
    }

    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }

    return static_cast<float>(sum) / size;
}

int main() {
    int myArray[MAX_ARRAY];
    int arraySize;

    // Populate array
    populateArray(myArray, arraySize);

    // Print array
    std::cout << "Array Contents:\n";
    printArray(myArray, arraySize);

    // Calculate and print average
    float avg = calculateAverage(myArray, arraySize);
    std::cout << "Average: " << avg << "\n";

    return 0;
}
