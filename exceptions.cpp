#include <iostream>
#include <stdexcept> // Create a derived class based on this class
using namespace std;
const int dbz = 1; // First method

class DivideByZero : public runtime_error {
    public: 
        DivideByZero() 
            : runtime_error("Divide by zero exception") {} 
            
};

double quotient(double numer, double denom) {
    if (denom == 0) {
        throw DivideByZero();
    }
    else {
        return numer/denom;
    }
}

int main() {

    // Exception handling using a try and catch block
    // First method without using a class
    try {
        int numer = 12;
        int denom = 0;
        if (denom == 0) {
            throw dbz;
        } else {
            cout << numer/denom;        
        }
    }
    catch(int e)
    {
        if (e == dbz) {
            cout << "Cant divide by 0 [generally use ceer (error stream for this)]" << endl;
        }
    }

    double number1, number2, ratio;
    cout << "Enter a numerator: ";
    cin >> number1;
    cout << "Enter a denominator: ";
    cin >> number2;
    try {
        ratio = quotient(number1, number2);
        cout << "The result is: " << ratio << endl;
    }
    // catch (DivideByZero &except) {
    //     cout << except.what() << endl; // what is a runtime_error function
    // }
    catch (...) {
        cout << "Exception thrown and caught" << endl;
    }
    
    return 0;
}