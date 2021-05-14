#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Person {
    private:
        string first, middle, last;
        int age;
    public:     
        Person(string f, string m, string l, int a) {
            first = f;
            middle = m;
            last = l;
            age = a;
        }
        string toString() {
            stringstream stm;
            stm << first << " " << middle << " " << last << ": " << age;
            return stm.str();
        }
};

// A stream is just a sequence of bytes [iostream(cout, cin, cerr) and fstream(ifstream, ofstream) are steam objects]
int main() {

    Person aPerson("George", "Fred", "Jones", 20);
    cout << aPerson.toString() << endl;

    // COUT
    cout << "Hello world" << endl;
    cout.put('H');
    cout.put('e');
    cout.put('l');
    cout.put('l');
    cout.put('o').put('\n');
    cout << "Hello World!" << endl << flush;

    // File streams
    ifstream gradeFile;
    gradeFile.open("Files/grades.txt");
    stringstream grades;
    string line;
    while(!gradeFile.eof()) {
        getline(gradeFile, line);
        grades << line << "\n";
    }
    cout << grades.str() << endl;
    gradeFile.close();

    // CIN
    string name1, name2;
    cout << "Enter your name: " << endl;
    // cin would only work with an input without " "
    getline(cin, name2);
    // getline(object, variable) - Can be used for file objects
    cout << "Your name is: " << name1 << " " << name2 << endl;
    
    char c;
    c = cin.get(); // To retrieve a single character for input
    do {
        cout.put(c);
        c = cin.get();
    } while (!cin.eof());

    return 0;
}