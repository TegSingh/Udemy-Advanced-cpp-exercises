#include <iostream>
#include <fstream>
#include <deque>
#include <string>

using namespace std;

int main() {
    deque<string> names;
    ifstream nameList;
    nameList.open("Files/names.txt");
    string line;
    while(!nameList.eof()) {
        getline(nameList, line);
        
        size_t position = line.find(" "); // size_t is the data type for string function to represent an unsigned integer
        string name = line.substr(0, position);
        
        // Move the iterator to the last character instead of the NULL character by --it
        string::iterator it = line.end();
        --it;

        if (*it == 'I') {
            names.push_front(name);
        } else {
            names.push_back(name);
        }
    }
    for(deque<string>::iterator it = names.begin(); it < names.end(); it++) {
        cout << *it << endl;
    }
    nameList.close();

    return 0;
}