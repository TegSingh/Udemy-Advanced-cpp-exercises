#include <iostream>
using namespace std;

// Make sure to use your arguments correctly with the template placeholders 
template <typename T, typename U>
T max(T arg1, U arg2) {
    return (arg1 > arg2) ? arg1 : arg2;
}

int main() {

    double num1 = 35.55;
    int num2 = 130;
    cout << "Max value is: " << max(num1, num2) << endl;
    return 0;
}