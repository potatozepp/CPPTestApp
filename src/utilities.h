#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>
#include <string>

/**
 * Utility functions demonstrating various C++ concepts:
 * - Function overloading
 * - Pass by reference vs pass by value
 * - Working with arrays and vectors
 * - Template basics
 */

// Function overloading - same name, different parameters
int findMax(int a, int b);
double findMax(double a, double b);
int findMax(const std::vector<int>& numbers);

// Pass by reference vs pass by value demonstrations
void demonstratePassByValue(int value);
void demonstratePassByReference(int& value);
void demonstratePassByConstReference(const std::string& text);

// Array and vector utilities
void printArray(const int arr[], int size);
void printVector(const std::vector<int>& vec);
std::vector<int> createSequence(int start, int end);

// String utilities
std::string toUpperCase(const std::string& str);
bool isPalindrome(const std::string& str);

// Pointer demonstration
void swapValues(int* a, int* b);
void demonstrateBasicPointers();

// Template function (basic)
template<typename T>
T getAbsoluteValue(T value) {
    return (value < 0) ? -value : value;
}

#endif // UTILITIES_H