#include <iostream>

using namespace std; // define scope and generally declared globally

// First scope is firstNums
namespace firstNums {
    int num1 = 10;
    int num2 = 12;
}

// Second scope is secondNums [no conflict with same name variables because of different namespaces[scopes]]
namespace secondNums {
    int num1 = 1;
    int num2 = 2;
}

namespace minMax {
    int min (int num1, int num2) {
        if (num1 < num2)
            return num1;
        else 
            return num2;
    }

    int max(int num1, int num2) {
        if (num1 > num2)
            return num1;
        else 
            return num2;
    }
}

namespace People {
    class Person {
        private:
            string name;
            string sex; 
        public: 
            Person (string n, string s) {
                name = n;
                sex = s;
            }
            string get() {
                return name + ", " + sex;
            }
    };
}
int main() {

    // using statement removes the need for using the scope resolution operator
    using namespace minMax;
    using namespace People;
    int a, b;
    cout << "Enter a number: ";
    cin >> a;
    cout << "Enter another number: ";
    cin >> b;
    cout << "Min: " << min(a, b) << endl;
    cout << "Max: " << max(a, b) << endl;
    Person P("Tegveer Singh", "M");
    cout << P.get() << endl;

    cout << "num1 in firstNums: " << firstNums::num1 << endl;
    cout << "num1 in secondNums: " << secondNums::num1 << endl;
    cout << "num2 in firstNums: " << firstNums::num2 << endl;
    cout << "num2 in firstNums: " << secondNums::num2 << endl;
    // Define a block of code inheriting firstNums scope
    {
        using namespace firstNums;
        cout << "num1 in firstNums: " << num1 << endl;
        cout << "num2 in firstNums: " << num2 << endl;
    }
    // Define a block of code inheriting secondNums scope
    {
        using namespace secondNums;
        cout << "num1 in secondNums: " << num1 << endl;
        cout << "num2 in secondNums: " << num2 << endl;
    }
}