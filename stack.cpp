#include <iostream>
#include <string>

using namespace std;

class Stack {
    private:
        string datastore[100];
        int top; // holds the index of the top element
    public:
        Stack() {
            top = -1; // incremented everytime an element is added
        }
        // Add an element to the stack
        void push (string value) {
            top++;
            datastore[top] = value;
        }
        // Removes top element based on LIFO and returns it
        string pop() {
            string returnValue = datastore[top];
            top--;
            return returnValue; 
        }
        // Returns the top element of the stack
        string peek() {
            return datastore[top];
        }
        // Returns the numbers of elements in the stack
        int count() {
            return top+1;
        }
        // Empty the stack
        void clear() {
            for (int i = 0; i < top-1; i++) {
                datastore[i] = "";
            }
            top = -1;
            cout << "Stack cleared" << endl;
        }
        // Check if the stack is empty [candidate to be a private member function]
        bool isEmpty() {
            if (top == -1)
                return true;
            else
                return false;
        }
};

int main() {

    Stack names;
    string name;
    names.push("Tegveer");
    names.push("Nate");
    names.push("Rayhan");
    names.push("Devaansh");
    cout << "Number of items: " << names.count() << endl;
    if (!names.isEmpty()) {
        name = names.pop(); // This will remove the most recent element
    }
    cout << name << " popped" << endl;
    cout << "Number of items: " << names.count() << endl;
    names.clear();
    cout << "Number of items: " << names.count() << endl;

    return 0;
}