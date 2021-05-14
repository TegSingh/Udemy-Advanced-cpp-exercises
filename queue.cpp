#include <iostream>

using namespace std;

class Queue {
    private: 
        string datastore[100];
        int back;
        const static int front = 0; // Front does not change
        void shift() {
            for (int i = front; i <= back; i++)
                datastore[i] = datastore[i+1]; // since the leftmost element was removed, shift all elements by one towards the left
            back--;
        }

    public:
        Queue() {
            back = -1; // similar function as top
        }
        void in(string value) { // Push
            ++back;
            datastore[back] = value;
        }
        string out() { // Pop
            string returnValue = datastore[front]; // Removed from the front because FIFO
            shift(); // Move every element one unit in the queue to adjust the values
            return returnValue;
        }
        // Display the methods of the queue
        void show() {
            for (int i = front; i <= back; i++){
                cout << datastore[i] << " ";
            }
            cout << endl;
        }
        int count() {
            return back+1;
        }
        // Methods to return first and last elements of the queue
        string qfront() {
            return datastore[front];
        }
        string qback() {
            return datastore[back];
        }
        bool isEmpty() {
            if (back == -1)
                return true;
            else
                return false;
        }
        void clear() {
            for (int i = front; i <= back; i++) 
                datastore[i] = "";
            back = -1;
        }
};
int main() {

    Queue q;
    q.in("A");
    q.in("B");
    q.in("C");
    q.show();
    q.out();
    q.in("D");
    q.in("E");
    cout << q.isEmpty() << endl;
    q.show();
    cout << "Front: " << q.qfront() << endl;
    cout << "Back: " << q.qback() << endl;
    cout << "Count: " << q.count() << endl;
    q.out();
    q.clear();
    cout << q.isEmpty() << endl;
    q.show();


    return 0;
}