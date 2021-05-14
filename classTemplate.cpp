#include <iostream>
using namespace std;

template <typename T>
class Stack { // LIFO
    private:
        T datastore[100];
        int top; // index for the top of the stack

    public: 
        Stack() {
            top = -1;
        }
        void push(T num) {
            ++top;
            datastore[top] = num;
        }
        T pop() {
            int val = datastore[top];
            datastore[top] = 0;
            --top;
            return val;
        } 
        T peek() {
            return datastore[top];
        }
}; 

// Specialization template
template<> // Enclose in brackets the data type you need to specialize the class in
class Stack<string> {
private:
        string datastore[100];
        int top; 

    public: 
        Stack() {
            top = -1;
        }
        void push(string val) {
            ++top;
            datastore[top] = val;
        }
        string pop() {
            string val = datastore[top];
            datastore[top] = "";
            --top;
            return val;
        } 
        string peek() {
            return datastore[top];
        }
};

int main() {

    Stack<double> numbers;
    numbers.push(12);
    numbers.push(10);    
    numbers.push(32);
    cout << numbers.peek() << endl;
    int value = numbers.pop();
    cout << numbers.peek() << endl;

    Stack<string> names;
    names.push("Tegveer");
    names.push("Nate");
    cout << names.peek() << endl;
    string name = names.pop();
    cout << names.peek() << endl;
    return 0;
}