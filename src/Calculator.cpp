#include "Calculator.h"
#include <iostream>
#include <stdexcept>

// Constructor implementation
Calculator::Calculator(const std::string& name) 
    : lastResult(0.0), calculatorName(name) {
    std::cout << "Calculator '" << calculatorName << "' created." << std::endl;
}

// Destructor implementation
Calculator::~Calculator() {
    std::cout << "Calculator '" << calculatorName << "' destroyed." << std::endl;
}

// Addition
double Calculator::add(double a, double b) {
    lastResult = a + b;
    std::cout << a << " + " << b << " = " << lastResult << std::endl;
    return lastResult;
}

// Subtraction
double Calculator::subtract(double a, double b) {
    lastResult = a - b;
    std::cout << a << " - " << b << " = " << lastResult << std::endl;
    return lastResult;
}

// Multiplication
double Calculator::multiply(double a, double b) {
    lastResult = a * b;
    std::cout << a << " * " << b << " = " << lastResult << std::endl;
    return lastResult;
}

// Division with error handling
double Calculator::divide(double a, double b) {
    if (b == 0.0) {
        throw std::runtime_error("Division by zero!");
    }
    lastResult = a / b;
    std::cout << a << " / " << b << " = " << lastResult << std::endl;
    return lastResult;
}

// Getter for last result
double Calculator::getLastResult() const {
    return lastResult;
}

// Setter for calculator name
void Calculator::setCalculatorName(const std::string& name) {
    calculatorName = name;
}

// Getter for calculator name
std::string Calculator::getCalculatorName() const {
    return calculatorName;
}

// Reset method demonstrating method chaining
Calculator& Calculator::reset() {
    lastResult = 0.0;
    std::cout << "Calculator reset. Last result is now: " << lastResult << std::endl;
    return *this;  // Return reference to self for chaining
}

// Static function implementation
double Calculator::power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    std::cout << base << "^" << exponent << " = " << result << std::endl;
    return result;
}