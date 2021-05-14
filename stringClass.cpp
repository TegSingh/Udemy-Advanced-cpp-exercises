#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    string str0; // This calls the default constructor for the string class
    string str1 = "";
    string str2(str1); // This uses a COPY CONSTRUCTOR [copy value of str1 to the newly created str2 object]
    string str3("A string"); 
    string str4(10, 'T'); // Shows that the string contains 10 consecutive Ts
    string str5 = "Hello";
    string str6 = "World";
    // Note: We cannot literals 2 literals together, therefore, we should make sure
    string str7 = str5 + " " + str6; // string concatenation
    cout << str7 << endl;

    string s1 = "Tegveer";
    string s2 = "Kaitlyn";
    if (s1 > s2) 
        cout << s1 << " is greater than " << s2 << endl;
    else 
        cout << s2 << " is greater than " << s1 << endl;
    int compare = s1.compare(s2); // -1 s1 < s2, 1 s1 > s2, 0 s1 = s2
    cout << compare << endl;
    
    string s3 = "My name is Tegveer Singh";
    int position = s3.find("Tegveer");
    if (position >= 0)
        cout << "Found at " << position << "!" << endl;
    else 
        cout << "Not found!" << endl;
    string numbers = "0123456789";
    string identifier = "name1";
    position = identifier.find_first_of(numbers);
    if(position >= 0) {
        cout << "Illegal identifier" << endl;
    } else {
        cout << "Legal identifier" << endl;
    }
    position = s3.find("Tegveer");
    string s4 = s3.substr(position + s1.length() + 1);
    s3.replace(position, s1.length(), "Jagjit");
    cout << s4 << endl << s3 << endl;

    char c1[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char c2[] = "World!";
    cout << c1 << " " << c2 << endl;
    int value = strcmp(c1, c2);
    cout << value << endl;
    strcat(c1, c2); // add second to the first
    cout << c1 << endl;
    return 0;
}