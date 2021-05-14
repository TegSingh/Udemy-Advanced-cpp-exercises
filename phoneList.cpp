#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <utility>

using namespace std;

void showMenu() {
    cout << "1. Get number" << endl;
    cout << "2. quit" << endl;
    cout << "Enter a choice: ";
}

void showNumber(map<string, string> phonelist) {
    string name;
    cout << "Enter a name: ";
    cin >> name;
    cout << "The number is: " << phonelist[name] << endl;
}

string getName(string line) {
    int pos = line.find(",");
    return line.substr(0, pos); // Return the substring up to the comma 
}

string getNumber(string line) {
    int pos = line.find(" ");
    return line.substr(pos+1); // We dont need to provide the end
}

int main() {

    map<string, string> phonelist;
    ifstream file("Files/phonelist.txt");
    string line, name, number;
    while (!file.eof()) {
        getline(file, line);
        name = getName(line);
        number = getNumber(line);
        phonelist[name] = number;
    }
    file.close();
    int choice = 1;
    while (choice != 2) {
        showMenu();
        cin >> choice;
        if (choice == 1) {
            showNumber(phonelist);
        }
    }
    return 0;
}