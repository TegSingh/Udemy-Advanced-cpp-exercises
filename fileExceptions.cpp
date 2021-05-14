#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file;
    // Add a bitmask to signal to the compiler what possible errors can exist
    file.exceptions(ifstream::failbit | ifstream::badbit);
    try {
        file.open("file.txt");
        while(!file.eof()) {
            cout << file.get();
        }
    }
    catch (ifstream::failure e) {
        cout << e.what() << endl; // tells what caused the failure
        cout << "Error opening file" << endl;
        // End the program if that happens
        return 1;
    }
    file.close();
    return 0;
}