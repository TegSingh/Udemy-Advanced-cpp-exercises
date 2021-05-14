#include <iostream>
#include <deque>

using namespace std;

int find(deque<string> d, string value) {
    for (int i = 0; i < d.size(); i++){
        if(d.at(i) == value) {
            return i;
        }
    }
    return -1;
    
}

// deque is double ended queue [Enhanced queue] pronounced deck
int main() {

    deque<string> line;
    line.push_back("Tegveer Singh");
    line.push_front("Kaitlyn Harford");
    line.push_back("Devaansh Khanna");
    line.push_back("Nate Grobe");
    line.push_back("Emily Harford");

    for (int i = 0; i < line.size(); i++) {
        cout << line[i] << endl;
    }
    
    for (int i = 0; i < line.size(); i++) {
        cout << line[i] << endl;
    }
    cout << "The size of our line is: " << line.size() << endl;
    
    string name;
    cout << "Enter name to find: " << endl;
    getline(cin, name);
    int pos = find(line, name);
    (pos > -1) ? cout << "Name found at: " << pos+1 << endl : cout << "Name not found" << endl;

    deque<string>::iterator iter = line.begin();
    ++iter;
    ++iter;
    line.insert(iter, "Nishchal Bhardwaj");  // Insert name at the location index iterator is pointing to
    for (iter = line.begin(); iter < line.end(); iter++) {
        cout << *iter << endl;
    }
    
    return 0;
}