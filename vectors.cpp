#include <iostream>
#include <vector>
#include <list>
using namespace std;

void display(list<string> l) {
    list<string>::iterator iter = l.begin(); // Works as a pointer index
    while (iter != l.end()) {
        cout << *iter << endl; // *iter is a dereference to provide the value pointed to by the iterator object
        ++iter;
    }
}

int main() {

    // VECTORS
    vector<int> numbers;
    for (int i = 0; i < 11; i++) {
        numbers.push_back(i);
    }

    int sum = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        sum += numbers[i];
    }
    cout << "The sum is: " << sum << endl;
    
    // LISTS
    list<string> names;
    names.push_back("Tegveer");
    names.push_back("Kaitlyn");
    names.push_back("Devaansh");
    names.push_back("Emily");
    // Move the iterator or set the iterator to be at the beginning of the list
    list<string>::iterator iter = names.begin();
    while (iter != names.end())
    {
        cout << &iter << endl;
        iter++;
    }
    cout << "First Item: " << names.front() << endl;
    cout << "Last item: " << names.back() << endl;

    cout << "The reverse list is: " << endl;
    names.reverse();
    list<string>::iterator riter = names.begin();
    while (riter != names.end())
    {
        cout << *riter << endl;
        riter++;
    }

    cout << "The sorted List is: " << endl;
    names.sort();
    display(names);
    names.push_front("Nate Grobe"); // Add to the front of the list
    display(names);

    names.remove("Devaansh");
    display(names);
    names.pop_front();
    display(names);
    names.pop_back();
    display(names);
    names.clear();
    if (names.empty()) {
        cout << "List Empty" << endl;
    } else {
        cout << "List not Empty" << endl;
    }
    return 0;
}