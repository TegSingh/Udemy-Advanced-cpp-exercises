#include <iostream>

using namespace std;

class Node {
    public: 
        string data;
        Node* left;
        Node* right;
        Node(string d) {
            data = d; // Each node has data
            left = NULL; // Left part left blank for other functions to determine location
            right = NULL; // Right part left blank for other functions to determine location
        }
};

// Avoid having oo many function definitions in the class
class BST{ 
    private: 
        Node* root; // should be NULL in an empty tree
        void Insert(string data, Node* anode);
        Node* Search(string data, Node* anode);
        void preOrder(Node* anode);
        void inOrder(Node* anode);
        void postOrder(Node* anode);
    public: 
        BST();
        void Insert(string data);
        Node* Search(string data);
        void preOrder();
        void inOrder();
        void postOrder();
};

// :: is the scope resolution operator
BST::BST() {
    root = NULL;
}

// This is the private method definition
void BST::Insert(string data, Node* anode) {
    // Check if anode needs to be part of the left subtree of the root anode
    if (data < anode->data) {
        // Check if we need to go further down the tree or we are already at the furthest child
        if (anode->left != NULL) 
            Insert(data, anode->left);
        else { // Final child
            anode->left = new Node(data);
            anode->left->right = NULL;
            anode->left->left = NULL;
        }
    }
    // Check if anode needs to be in the right subtree of the root anode
    else {
        if (anode->right != NULL) 
            Insert(data, anode->right);
        else {
            anode->right = new Node(data);
            anode->right->right = NULL;
            anode->right->left = NULL;
        }
    }
}

// This is the public insert method
void BST::Insert(string data) {
    // If its a normal insertion
    if (root != NULL) {
        Insert(data, root);
    }
    // If its the first node in the tree
    else {
        root = new Node(data);
        root->left = NULL;
        root->right = NULL;
    }
}

// This is the private search method
Node* BST::Search(string data, Node* anode) {
    // Since this is a recursive function, a future call to this function might have a NULL value for anode
    if (anode != NULL) {
        if (data == anode->data) 
            return anode;
        if (data < anode->data) 
            return Search(data, anode->left); // Different function signature for the private and public
        else 
            return Search(data, anode->right);
    }
}

// This is the public search method
Node* BST::Search(string data) {
    return Search(data, root); // Public method is used and does not take the root as the argument. We dont want the user to specify the information for the root
}

// Public
void BST::preOrder() {
    cout << "Pre order Tree traversal: " << endl;
    preOrder(root);
    cout << endl;
}
// Private
void BST::preOrder(Node* anode) {
    if (anode != NULL) {
        cout << anode->data << " ";
        preOrder(anode->left);
        preOrder(anode->right);
    }
}

// Public
void BST::postOrder() {
    cout << "Post order Tree traversal: " << endl;
    postOrder(root);
    cout << endl;
}
// Private
void BST::postOrder(Node* anode) {
    if (anode != NULL) {
        postOrder(anode->left);
        postOrder(anode->right);
        cout << anode->data << " ";
    }
}

// Public
void BST::inOrder() {
    cout << "In order Tree traveral: " << endl;
    inOrder(root);
    cout << endl;
}
// Private
void BST::inOrder(Node* anode) {
    if (anode != NULL) {
        inOrder(anode->left);
        cout << anode->data << " ";
        inOrder(anode->right);
    }
}

int main() {
    
    BST *btree = new BST;
    btree->Insert("Tegveer");
    btree->Insert("Nate");
    btree->Insert("Kaitlyn");
    btree->Insert("Tushar");
    btree->Insert("Devaansh");
    btree->Insert("Pranav");
    btree->Insert("Emily");
    btree->Insert("Rayhan");
    btree->Insert("Vaibhav");
    btree->inOrder();
    btree->preOrder();
    btree->postOrder();
    return 0;
}