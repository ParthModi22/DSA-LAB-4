#include <iostream>
using namespace std;

class TreeNode {
public:
    int key;
    TreeNode* next;
    TreeNode* child;

    TreeNode(int value) : key(value), next(nullptr), child(nullptr) {}
};

class UnboundedBranchTree {
private:
    TreeNode* root;

public:
    UnboundedBranchTree() : root(nullptr) {}

    // Function to insert a key into the unbounded branch tree
    void insert(int parentKey, int key) {
        TreeNode* newNode = new TreeNode(key);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        TreeNode* parentNode = searchUtil(root, parentKey);
        if (parentNode != nullptr) {
            if (parentNode->child == nullptr) {
                parentNode->child = newNode;
            } else {
                TreeNode* current = parentNode->child;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }
        } else {
            cout << "Parent not found. Insertion failed." << endl;
        }
    }

    // Function to search for a key in the unbounded branch tree
    TreeNode* search(int key) {
        return searchUtil(root, key);
    }

private:
    // Helper function to recursively search for a key in the unbounded branch tree
    TreeNode* searchUtil(TreeNode* node, int key) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->key == key) {
            return node;
        }

        TreeNode* childNode = searchUtil(node->child, key);
        if (childNode != nullptr) {
            return childNode;
        }

        return searchUtil(node->next, key);
    }
};

int main() {
    UnboundedBranchTree tree;

    // Insert some keys into the unbounded branch tree
    tree.insert(0, 1);
    tree.insert(0, 2);
    tree.insert(1, 3);
    tree.insert(1, 4);
    tree.insert(2, 5);
    tree.insert(2, 6);

    // Search for keys in the unbounded branch tree
    TreeNode* node1 = tree.search(1);
    TreeNode* node7 = tree.search(7);

    if (node1 != nullptr) {
        cout << "Node with key 1 found." << endl;
    } else {
        cout << "Node with key 1 not found." << endl;
    }

    if (node7 != nullptr) {
        cout << "Node with key 7 found." << endl;
    } else {
        cout << "Node with key 7 not found." << endl;
    }

    return 0;
}
