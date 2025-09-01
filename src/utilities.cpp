#include "utilities.h"
#include <iostream>
#include <algorithm>
#include <cctype>

// Function overloading implementations

// Find max of two integers
int findMax(int a, int b) {
    std::cout << "Finding max of two integers: " << a << " and " << b << std::endl;
    return (a > b) ? a : b;
}

// Find max of two doubles
double findMax(double a, double b) {
    std::cout << "Finding max of two doubles: " << a << " and " << b << std::endl;
    return (a > b) ? a : b;
}

// Find max in a vector
int findMax(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        std::cout << "Empty vector provided!" << std::endl;
        return 0;
    }
    
    int max = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    std::cout << "Max value in vector: " << max << std::endl;
    return max;
}

// Pass by value - creates a copy
void demonstratePassByValue(int value) {
    std::cout << "Original value (pass by value): " << value << std::endl;
    value = 999;  // This won't affect the original variable
    std::cout << "Modified value (inside function): " << value << std::endl;
}

// Pass by reference - works with the original variable
void demonstratePassByReference(int& value) {
    std::cout << "Original value (pass by reference): " << value << std::endl;
    value = 777;  // This WILL affect the original variable
    std::cout << "Modified value (inside function): " << value << std::endl;
}

// Pass by const reference - efficient but read-only
void demonstratePassByConstReference(const std::string& text) {
    std::cout << "Text length (const reference): " << text.length() << std::endl;
    std::cout << "Text content: " << text << std::endl;
    // text = "modified"; // This would cause a compilation error!
}

// Array utility
void printArray(const int arr[], int size) {
    std::cout << "Array contents: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Vector utility
void printVector(const std::vector<int>& vec) {
    std::cout << "Vector contents: ";
    for (const int& value : vec) {  // Range-based for loop (C++11)
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

// Create a sequence vector
std::vector<int> createSequence(int start, int end) {
    std::vector<int> sequence;
    for (int i = start; i <= end; ++i) {
        sequence.push_back(i);
    }
    return sequence;
}

// String to uppercase
std::string toUpperCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

// Check if string is palindrome
bool isPalindrome(const std::string& str) {
    std::string cleaned;
    for (char c : str) {
        if (std::isalnum(c)) {
            cleaned += std::tolower(c);
        }
    }
    
    std::string reversed = cleaned;
    std::reverse(reversed.begin(), reversed.end());
    
    return cleaned == reversed;
}

// Swap values using pointers
void swapValues(int* a, int* b) {
    if (a != nullptr && b != nullptr) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

// Demonstrate basic pointer usage
void demonstrateBasicPointers() {
    int x = 10;
    int y = 20;
    int* ptr = &x;  // Pointer to x
    
    std::cout << "\n=== Pointer Demonstration ===" << std::endl;
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "Address of x: " << &x << std::endl;
    std::cout << "Pointer value: " << ptr << std::endl;
    std::cout << "Value pointed to: " << *ptr << std::endl;
    
    ptr = &y;  // Now point to y
    std::cout << "After pointing to y: " << *ptr << std::endl;
    
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swapValues(&x, &y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
}