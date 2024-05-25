#include <iostream>
#include <queue>
using namespace std;

// Structure for a node in the binary tree
struct Node {
    int key;
    Node* left;
    Node* right;
};

// Binary Tree class
class BinaryTree {
private:
    Node* root;

public:
    // Constructor
    BinaryTree() {
        root = nullptr;
    }

    // Function to create a new node
    Node* createNode(int key) {
        Node* newNode = new Node();
        newNode->key = key;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    // Function to insert a new key into the binary tree
    void insert(int key) {
        root = insertRecursive(root, key);
    }

    // Recursive function to insert a new key into the binary tree
    Node* insertRecursive(Node* root, int key) {
        if (root == nullptr)
            return createNode(key);
        if (key < root->key)
            root->left = insertRecursive(root->left, key);
        else if (key > root->key)
            root->right = insertRecursive(root->right, key);
        return root;
    }

    // Function to search for a key in the binary tree
    bool search(int key) {
        return searchRecursive(root, key);
    }

    // Recursive function to search for a key in the binary tree
    bool searchRecursive(Node* root, int key) {
        if (root == nullptr)
            return false;
        if (root->key == key)
            return true;
        else if (root->key > key)
            return searchRecursive(root->left, key);
        else
            return searchRecursive(root->right, key);
    }

    // Function to delete a key from the binary tree
    void remove(int key) {
        root = removeRecursive(root, key);
    }

    // Recursive function to delete a key from the binary tree
    Node* removeRecursive(Node* root, int key) {
        if (root == nullptr)
            return root;
        if (key < root->key)
            root->left = removeRecursive(root->left, key);
        else if (key > root->key)
            root->right = removeRecursive(root->right, key);
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = removeRecursive(root->right, temp->key);
        }
        return root;
    }

    // Function to find the node with minimum value in a subtree
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    // Function to display the binary tree (Inorder traversal)
    void display() {
        inorderTraversal(root);
    }

    // Recursive function to perform inorder traversal
    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->key << " ";
            inorderTraversal(root->right);
        }
    }
};

int main() {
    BinaryTree tree;

    // Inserting elements
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "Binary Tree after insertion: ";
    tree.display();
    cout << endl;

    // Deleting elements
    tree.remove(20);
    cout << "Binary Tree after deletion of 20: ";
    tree.display();
    cout << endl;

    // Searching for elements
    cout << "Searching for 40: ";
    if (tree.search(40))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    cout << "Searching for 100: ";
    if (tree.search(100))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}
