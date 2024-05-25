#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    // Helper function to recursively search for a key in the binary tree
    bool searchUtil(TreeNode* node, int key) {
        if (node == nullptr) {
            return false;
        }

        if (node->key == key) {
            return true;
        }

        return searchUtil(node->left, key) || searchUtil(node->right, key);
    }

    // Helper function to find the node with the minimum key in the subtree rooted at a given node
    TreeNode* findMinNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Helper function to recursively perform insertion in the binary tree
    TreeNode* insertUtil(TreeNode* node, int key) {
        if (node == nullptr) {
            return new TreeNode(key);
        }

        if (key < node->key) {
            node->left = insertUtil(node->left, key);
        } else {
            node->right = insertUtil(node->right, key);
        }

        return node;
    }

    // Helper function to recursively perform deletion in the binary tree
    TreeNode* deleteUtil(TreeNode* node, int key) {
        if (node == nullptr) {
            return node;
        }

        if (key < node->key) {
            node->left = deleteUtil(node->left, key);
        } else if (key > node->key) {
            node->right = deleteUtil(node->right, key);
        } else {
            // Node to delete found

            // Node with only one child or no child
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            TreeNode* temp = findMinNode(node->right);

            // Copy the inorder successor's content to this node
            node->key = temp->key;

            // Delete the inorder successor
            node->right = deleteUtil(node->right, temp->key);
        }
        return node;
    }

public:
    BinaryTree() : root(nullptr) {}

    // Function to insert a key into the binary tree
    void insert(int key) {
        root = insertUtil(root, key);
    }

    // Function to delete a key from the binary tree
    void remove(int key) {
        root = deleteUtil(root, key);
    }

    // Function to search for a key in the binary tree
    bool search(int key) {
        return searchUtil(root, key);
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
    binaryTree.remove(15);
    cout << "Deleted 15" << endl;
    binaryTree.remove(8);
    cout << "Deleted 8" << endl;

    return 0;
}
