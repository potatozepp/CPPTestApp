#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

/**
 * A simple Calculator class demonstrating basic C++ concepts:
 * - Class declaration
 * - Constructor and destructor
 * - Public and private members
 * - Member functions
 */
class Calculator {
private:
    double lastResult;          // Private member variable
    std::string calculatorName; // String member variable

public:
    // Constructor with default parameter
    Calculator(const std::string& name = "BasicCalculator");
    
    // Destructor
    ~Calculator();
    
    // Basic arithmetic operations
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    
    // Getter and setter for demonstration
    double getLastResult() const;           // const member function
    void setCalculatorName(const std::string& name);
    std::string getCalculatorName() const;
    
    // Function demonstrating method chaining
    Calculator& reset();
    
    // Static function
    static double power(double base, int exponent);
};

#endif // CALCULATOR_H