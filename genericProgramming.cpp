// Generic programming reduces the need for 2 different functions to handle 2 different data types
#include <iostream>

using namespace std;

// Add a template for assistance in generic programming and instead of using 2 different display function we can just use one
template <typename T>
// Use T instead of the original data type for the function to increase reusability
void display(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Tempate declaration should immediately be followed by the function that uses the typename
template <typename T>
T max(T &arg1, T &arg2) { // comparison between 2 numbers [good practice to use references]
    if (arg1 > arg2) {
        return arg1;
    } else {
        return arg2;
    }
}

int main() {

    const int size = 10;
    int numbers[size];
    for (int i = 0; i < size; i++) {
        numbers[i] = i+1;
    }
    display(numbers, size);
    string names[] = {"Jim", "Fred", "Jane", "Bob", "Mary", "Mike", "Nate", "Teg", "Terri", "Allison"};
    display(names, size);
    
    int a = 12;
    int b = 24;
    cout << max(a, b) << endl;
    double x = 2.25;
    double y = 2.13;
    cout << max(x, y) << endl;
    string w1 = "apple";
    string w2 = "orange";
    cout << max(w1, w2) << endl;
    return 0;


}