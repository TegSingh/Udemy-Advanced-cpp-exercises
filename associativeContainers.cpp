#include <iostream>
#include <utility> // For pairs
#include <map> // Fopr maps
#include <set> // For sets

using namespace std;

int main() {

    // Pair is a type of associative container
    pair<string, string> number1("Tegveer", "123"); // This is a key value pair
    cout << number1.first << ": " << number1.second << endl;
    
    pair<string, int> student1("Kaitlyn", 95);
    cout << student1.first << ": " << student1.second << endl;
    
    // Map is another type of associative container
    map<string, string> numbers;
    numbers["Tegveer"] = "123";
    numbers["Kaitlyn"] = "234";
    numbers["Devaansh"] = "345";
    cout << "Tegveer: " << numbers["Tegveer"] << endl;
    cout << "Size of Numbers: " << numbers.size() << endl;
    numbers.erase("Kaitlyn");
    cout << "Size of Numbers: " << numbers.size() << endl;
 

    map<string, int> grades; // Maps have the pair attributes of first and second too
    grades["Tegveer"] = 90;
    grades["Nate"] = 92;
    grades["Emily"] = 89;
    cout << "Enter a name to find: ";
    string name;
    cin >> name;
    if (grades.find(name) != grades.end()) {
        cout << name << ": " << grades[name] << endl;
    } else {
        cout << name << " not found" << endl;
    }

    double average = 0.0;
    int sum = 0;
    map<string, int>::iterator it = grades.begin();
    while (it != grades.end()) {
        cout << it->second << endl;
        sum += it->second; // Use this since it is a pointer
        ++it;
    }
    average = (double) sum / grades.size(); 
    cout << "The average grade is: " << average << endl;

    // Set is another type of associative container
    set<string> words;
    string word = "";
    do {
        cout << "Enter a word[quit to quit]: ";
        cin >> word;
        words.insert(word);
    } while(word != "quit");
    set<string>::iterator iter = words.begin();
    while (iter != words.end()) {
        cout << *iter << " ";
        iter++;
    }

    // Multimaps [allows to put duplicate keys into a data structure]
    multimap<string, string> numbers1;
    numbers1.insert(pair<string, string>("Eminem", "69420"));
    numbers1.insert(pair<string, string>("NF", "87674"));
    numbers1.insert(pair<string, string>("Juicewrld", "43232"));
    numbers1.insert(pair<string, string>("Eminem", "10932"));  
    numbers1.insert(pair<string, string>("Geazy", "43214"));
    numbers1.insert(pair<string, string>("Eminem", "13332"));    
    string searchName = "Eminem";
    // Declare a iterator poitner of type multimap string string
    multimap<string, string>::iterator iterator = numbers1.find(searchName);
    multimap<string, string>::iterator last = numbers1.upper_bound(searchName); // The last occurence of Eminem in the search map
    // Loop through all occurances of the string Eminem in the multimap [also init can be omitted in for loop]
    for (; iterator != last; iterator++) {
        cout << iterator->first << ": " << iterator->second << endl;
    } 

    return 0;
}