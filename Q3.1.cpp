#include <iostream>
using namespace std;

const int MAX_CHILDREN = 10;

class TreeNode {
public:
    int key;
    TreeNode* children[MAX_CHILDREN];

    TreeNode(int value) : key(value) {
        for (int i = 0; i < MAX_CHILDREN; ++i) {
            children[i] = nullptr;
        }
    }
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
            for (int i = 0; i < MAX_CHILDREN; ++i) {
                if (parentNode->children[i] == nullptr) {
                    parentNode->children[i] = newNode;
                    return;
                }
            }
            cout << "Parent has reached maximum children capacity. Insertion failed." << endl;
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

        for (int i = 0; i < MAX_CHILDREN; ++i) {
            TreeNode* result = searchUtil(node->children[i], key);
            if (result != nullptr) {
                return result;
            }
        }

        return nullptr;
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
