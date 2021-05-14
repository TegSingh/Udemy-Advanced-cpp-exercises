#include <iostream>
#include <string>
using namespace std;

class Node {
    public: 
        string data;
        Node* next;
        Node(string adata, Node* anext) {
            data = adata;
            next = anext;
        }
        string getData() {
            return data;
        }
        Node* Next() {
            return next;
        }
        void setNext(Node* anext) {
            next = anext;
        }
};

class Llist {
    public: 
        Node* head; // First node on the list
        Llist() {
            head = NULL;
        }
        // Method to add a node at the end of the list
        void Append(string data) {
            Node* newNode = new Node(data, NULL);
            Node *temp = head; // Create a temporary node to point to the first node in the list
            if (temp != NULL) {
                // The following loops stops at the end of the list
                while (temp -> Next() != NULL) {
                    temp = temp->Next();
                }
                temp->setNext(newNode);
            } else {
                // The list is empty so the element to be added is the first element and will be the head
                head = newNode;
            }
        }
        // Method to delete a node from the list
        void Delete(string data) {
            Node* temp = head;
            // List is empty 
            if (temp == NULL)
                return; // End the function without returning something
            if (temp->Next() == NULL) {
                delete temp;
                head = NULL;
            }
            else {
                Node* prev = head; 
                while (temp != NULL) {
                    if (temp->getData() == data) 
                        break;
                    prev = temp; // When the iteration reaches here prev is storing the previous element since the temp hasnt been updated yet
                    temp = temp->Next();
                }
                prev->setNext(temp->Next());
                delete temp;           
            }
        }
        void Print() {
            Node* temp = head;
            if (temp == NULL) {
                cout << "List: ";
                return;
            } 
            while(temp != NULL) {
                cout << temp->getData() << " --> ";
                temp = temp->Next();
            }
            cout << "NULL" << endl;
        }
};

int main() {

    Llist names;
    names.Append("Tegveer");
    names.Print();
    names.Append("Tanvi");
    names.Print();
    names.Append("Apohan");
    names.Print();
    names.Append("Devaansh");
    names.Print();
    names.Delete("Apohan");
    names.Print();
    names.Delete("Devaansh");
    return 0;
}