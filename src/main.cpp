#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Calculator.h"
#include "utilities.h"

// Using namespace std for convenience (though not always recommended in headers)
using namespace std;

// Function prototypes
void demonstrateBasicTypes();
void demonstrateControlStructures();
void demonstrateArraysAndVectors();
void demonstrateClassUsage();
void demonstrateFunctionOverloading();
void demonstratePassingMechanisms();
void demonstratePointers();
void demonstrateStringOperations();

int main() {
    cout << "========================================" << endl;
    cout << "     Welcome to C++ Learning App!" << endl;
    cout << "========================================" << endl;
    cout << endl;

    try {
        // Demonstrate basic data types
        demonstrateBasicTypes();
        cout << endl;

        // Demonstrate control structures
        demonstrateControlStructures();
        cout << endl;

        // Demonstrate arrays and vectors
        demonstrateArraysAndVectors();
        cout << endl;

        // Demonstrate class usage
        demonstrateClassUsage();
        cout << endl;

        // Demonstrate function overloading
        demonstrateFunctionOverloading();
        cout << endl;

        // Demonstrate passing mechanisms
        demonstratePassingMechanisms();
        cout << endl;

        // Demonstrate pointers
        demonstratePointers();
        cout << endl;

        // Demonstrate string operations
        demonstrateStringOperations();
        cout << endl;

    } catch (const exception& e) {
        cerr << "Error occurred: " << e.what() << endl;
    }

    cout << "========================================" << endl;
    cout << "         Program completed!" << endl;
    cout << "========================================" << endl;

    return 0;
}

void demonstrateBasicTypes() {
    cout << "=== Basic Data Types ===" << endl;
    
    // Integer types
    int wholeNumber = 42;
    short smallNumber = 100;
    long bigNumber = 1000000L;
    
    // Floating point types
    float singlePrecision = 3.14f;
    double doublePrecision = 3.141592653589793;
    
    // Character and boolean
    char singleChar = 'A';
    bool isTrue = true;
    bool isFalse = false;
    
    // String (from std::string)
    string message = "Hello, C++!";
    
    cout << "Integer: " << wholeNumber << endl;
    cout << "Short: " << smallNumber << endl;
    cout << "Long: " << bigNumber << endl;
    cout << "Float: " << fixed << setprecision(2) << singlePrecision << endl;
    cout << "Double: " << setprecision(15) << doublePrecision << endl;
    cout << "Character: " << singleChar << endl;
    cout << "Boolean true: " << boolalpha << isTrue << endl;
    cout << "Boolean false: " << isFalse << endl;
    cout << "String: " << message << endl;
}

void demonstrateControlStructures() {
    cout << "=== Control Structures ===" << endl;
    
    int number = 15;
    
    // If-else statement
    cout << "Number is " << number << endl;
    if (number > 0) {
        cout << "Number is positive" << endl;
    } else if (number < 0) {
        cout << "Number is negative" << endl;
    } else {
        cout << "Number is zero" << endl;
    }
    
    // Switch statement
    int day = 3;
    cout << "Day " << day << " is: ";
    switch (day) {
        case 1: cout << "Monday"; break;
        case 2: cout << "Tuesday"; break;
        case 3: cout << "Wednesday"; break;
        case 4: cout << "Thursday"; break;
        case 5: cout << "Friday"; break;
        default: cout << "Weekend or invalid";
    }
    cout << endl;
    
    // For loop
    cout << "For loop (1 to 5): ";
    for (int i = 1; i <= 5; ++i) {
        cout << i << " ";
    }
    cout << endl;
    
    // While loop
    cout << "While loop countdown: ";
    int countdown = 5;
    while (countdown > 0) {
        cout << countdown << " ";
        --countdown;
    }
    cout << "Blast off!" << endl;
    
    // Do-while loop
    cout << "Do-while loop: ";
    int count = 1;
    do {
        cout << count << " ";
        ++count;
    } while (count <= 3);
    cout << endl;
}

void demonstrateArraysAndVectors() {
    cout << "=== Arrays and Vectors ===" << endl;
    
    // Traditional array
    int numbers[5] = {10, 20, 30, 40, 50};
    cout << "Array demonstration:" << endl;
    printArray(numbers, 5);
    
    // Vector (dynamic array)
    vector<int> dynamicNumbers = {1, 2, 3, 4, 5};
    cout << "Vector demonstration:" << endl;
    printVector(dynamicNumbers);
    
    // Adding elements to vector
    dynamicNumbers.push_back(6);
    dynamicNumbers.push_back(7);
    cout << "After adding elements:" << endl;
    printVector(dynamicNumbers);
    
    // Create sequence using utility function
    vector<int> sequence = createSequence(10, 15);
    cout << "Generated sequence:" << endl;
    printVector(sequence);
}

void demonstrateClassUsage() {
    cout << "=== Class and Object Usage ===" << endl;
    
    // Create calculator object
    Calculator myCalc("LearningCalculator");
    
    // Use basic operations
    myCalc.add(10.5, 5.3);
    myCalc.multiply(3.0, 4.0);
    myCalc.subtract(20.0, 8.0);
    
    // Try division
    try {
        myCalc.divide(15.0, 3.0);
        // This will throw an exception
        // myCalc.divide(10.0, 0.0);
    } catch (const runtime_error& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    
    // Get last result
    cout << "Last result: " << myCalc.getLastResult() << endl;
    
    // Demonstrate method chaining
    myCalc.reset().add(1.0, 2.0);
    
    // Use static function
    Calculator::power(2.0, 8);
    
    // Create another calculator with default name
    Calculator defaultCalc;
    cout << "Default calculator name: " << defaultCalc.getCalculatorName() << endl;
}

void demonstrateFunctionOverloading() {
    cout << "=== Function Overloading ===" << endl;
    
    // Same function name, different parameter types
    int maxInt = findMax(15, 25);
    cout << "Max of integers: " << maxInt << endl;
    
    double maxDouble = findMax(3.14, 2.71);
    cout << "Max of doubles: " << maxDouble << endl;
    
    vector<int> testNumbers = {5, 2, 8, 1, 9, 3};
    int maxInVector = findMax(testNumbers);
    cout << "Max in vector: " << maxInVector << endl;
}

void demonstratePassingMechanisms() {
    cout << "=== Parameter Passing Mechanisms ===" << endl;
    
    int testValue = 100;
    string testString = "Hello World";
    
    cout << "Before pass by value: " << testValue << endl;
    demonstratePassByValue(testValue);
    cout << "After pass by value: " << testValue << endl;
    cout << endl;
    
    cout << "Before pass by reference: " << testValue << endl;
    demonstratePassByReference(testValue);
    cout << "After pass by reference: " << testValue << endl;
    cout << endl;
    
    cout << "Demonstrating const reference:" << endl;
    demonstratePassByConstReference(testString);
}

void demonstratePointers() {
    cout << "=== Pointer Demonstration ===" << endl;
    demonstrateBasicPointers(); // Call the function from utilities.cpp
}

void demonstrateStringOperations() {
    cout << "=== String Operations ===" << endl;
    
    string testString = "Hello World";
    cout << "Original string: " << testString << endl;
    cout << "Uppercase: " << toUpperCase(testString) << endl;
    
    string palindrome1 = "racecar";
    string palindrome2 = "hello";
    cout << "'" << palindrome1 << "' is palindrome: " << boolalpha << isPalindrome(palindrome1) << endl;
    cout << "'" << palindrome2 << "' is palindrome: " << boolalpha << isPalindrome(palindrome2) << endl;
    
    // Template function demonstration
    cout << "Absolute value of -42: " << getAbsoluteValue(-42) << endl;
    cout << "Absolute value of -3.14: " << getAbsoluteValue(-3.14) << endl;
}