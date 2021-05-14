// Read write generic algorithms
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <deque>
#include <ctime>
#include <cstdlib>

using namespace std;

template<typename T>
void display(vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {

    vector<int> numbers;
    for (int i = 0; i <= 10; ++i) {
        numbers.push_back(i);
    }
    display(numbers);

    // Fill is a generic algorithm
    fill(numbers.begin(), numbers.end(), 0);
    display(numbers);

    vector<string> names;
    names.push_back("Tegveer");
    names.push_back("Nate");
    names.push_back("Emily");
    display(names);
    fill(names.begin(), names.end(), string("A")); // The last argument is the string class constructor
    display(names);

    // Replace is another read write generic algorithm
    numbers.clear();
    for (int i = 0; i <= 10; ++i) {
        numbers.push_back(i);
    }
    replace(numbers.begin(), numbers.end(), 5, 10); // Replace 5 with 10
    display(numbers);

    vector<string> names1;
    names1.push_back("Tegveer");
    names1.push_back("Nate");
    names1.push_back("Emily");
    display(names1);
    replace(names1.begin(), names1.end(), "Emily", "Devaa");
    display(names1);

    // Generic sorting algorithms
    const int size = 10;
    int arr[] = {10, 2, 3, 6, 1, 4, 9, 7, 8, 5};
    vector<int> nums(arr, arr + size);
    display(nums);
    sort(nums.begin(), nums.end());
    display(nums);

    // Following is an array of strings
    const int size1 = 11;
    string str[] = {"Now", "is", "the", "time", "for", "greatness", "to", "be", "acheived", "by", "Tegveer"}; // captial letters lower ASCII code
    vector<string> sentence(str, str + size1);
    display(sentence);
    sort(sentence.begin(), sentence.end());
    display(sentence);

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    vector<int> v2;
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);
    // append/copy
    copy(v2.begin(), v2.end(), back_inserter(v1)); // v1.end() for the 3rd argument would not have worked because the compiler cannot find the end of v1
    display(v1);

    deque<int> d1;
    d1.push_front(1);
    d1.push_front(2);
    d1.push_front(3);   
    copy(v2.begin(), v2.end(), front_inserter(d1)); // Front inserter inserts elements 654321
    cout << d1.front() << endl; // Front implies the first element 

    vector<int> vec;
    for (int i = 1; i <= 10; i++) {
        vec.push_back(i);
    }
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
    for (vector<int>::reverse_iterator iter = vec.rbegin(); iter != vec.rend(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}