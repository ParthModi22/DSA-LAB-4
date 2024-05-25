#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class BinaryTree {
private:
    int tree[MAX_SIZE];
    int size;

    // Helper function to recursively search for a key in the binary tree
    bool searchUtil(int index, int key) {
        if (index >= size || tree[index] == -1) {
            return false;
        }

        if (tree[index] == key) {
            return true;
        }

        // Recursively search in the left and right subtrees
        return searchUtil(2 * index + 1, key) || searchUtil(2 * index + 2, key);
    }

    // Helper function to recursively perform insertion in the binary tree
    void insertUtil(int index, int key) {
        if (index >= MAX_SIZE) {
            cout << "Binary Tree is full! Cannot insert more nodes." << endl;
            return;
        }

        if (tree[index] == -1) {
            tree[index] = key;
            size = max(size, index + 1);
            return;
        }

        // If left child is empty, insert the key there
        if (tree[2 * index + 1] == -1) {
            insertUtil(2 * index + 1, key);
        }
        // If right child is empty, insert the key there
        else if (tree[2 * index + 2] == -1) {
            insertUtil(2 * index + 2, key);
        }
        // If both children are occupied, recursively insert in the left subtree
        else {
            insertUtil(2 * index + 1, key);
        }
    }

    // Helper function to recursively delete a key from the binary tree
    bool deleteUtil(int index, int key) {
        if (index >= size || tree[index] == -1) {
            return false;
        }

        if (tree[index] == key) {
            // If the node to delete is a leaf node
            if (tree[2 * index + 1] == -1 && tree[2 * index + 2] == -1) {
                tree[index] = -1;
            }
            // If the node to delete has only left child
            else if (tree[2 * index + 1] != -1 && tree[2 * index + 2] == -1) {
                tree[index] = tree[2 * index + 1];
                deleteUtil(2 * index + 1, tree[2 * index + 1]);
            }
            // If the node to delete has only right child
            else if (tree[2 * index + 1] == -1 && tree[2 * index + 2] != -1) {
                tree[index] = tree[2 * index + 2];
                deleteUtil(2 * index + 2, tree[2 * index + 2]);
            }
            // If the node to delete has both left and right children
            else {
                // Find the smallest node in the right subtree
                int minRight = findMinRight(2 * index + 2);
                tree[index] = minRight;
                // Delete the node containing minRight from the right subtree
                deleteUtil(2 * index + 2, minRight);
            }
            return true;
        }

        // Recursively search in the left and right subtrees
        return deleteUtil(2 * index + 1, key) || deleteUtil(2 * index + 2, key);
    }

    // Helper function to find the smallest node in the right subtree
    int findMinRight(int index) {
        while (tree[2 * index + 1] != -1) {
            index = 2 * index + 1;
        }
        return tree[index];
    }

public:
    BinaryTree() {
        for (int i = 0; i < MAX_SIZE; ++i) {
            tree[i] = -1;
        }
        size = 0;
    }

    // Function to insert a key into the binary tree
    void insert(int key) {
        insertUtil(0, key);
    }

    // Function to delete a key from the binary tree
    bool remove(int key) {
        return deleteUtil(0, key);
    }

    // Function to search for a key in the binary tree
    bool search(int key) {
        return searchUtil(0, key);
    }
};

int main() {
    BinaryTree binaryTree;

    // Insert some keys into the binary tree
    binaryTree.insert(10);
    binaryTree.insert(5);
    binaryTree.insert(15);
    binaryTree.insert(3);
    binaryTree.insert(7);
    binaryTree.insert(12);
    binaryTree.insert(18);

    // Perform search operations
    cout << "Search 12: " << (binaryTree.search(12) ? "Found" : "Not Found") << endl;
    cout << "Search 20: " << (binaryTree.search(20) ? "Found" : "Not Found") << endl;

    // Perform deletion operations
    cout << "Delete 15: " << (binaryTree.remove(15) ? "Success" : "Failed") << endl;
    cout << "Delete 8: " << (binaryTree.remove(8) ? "Success" : "Failed") << endl;

    return 0;
}
