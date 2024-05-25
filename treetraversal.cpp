#include <iostream>
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

    // Helper function for pre-order traversal
    void preOrderUtil(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->key << " ";
        preOrderUtil(node->left);
        preOrderUtil(node->right);
    }

    // Helper function for in-order traversal
    void inOrderUtil(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        inOrderUtil(node->left);
        cout << node->key << " ";
        inOrderUtil(node->right);
    }

    // Helper function for post-order traversal
    void postOrderUtil(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        postOrderUtil(node->left);
        postOrderUtil(node->right);
        cout << node->key << " ";
    }

public:
    BinaryTree() : root(nullptr) {}

    // Function to perform pre-order traversal
    void preOrder() {
        cout << "Pre-order traversal: ";
        preOrderUtil(root);
        cout << endl;
    }

    // Function to perform in-order traversal
    void inOrder() {
        cout << "In-order traversal: ";
        inOrderUtil(root);
        cout << endl;
    }

    // Function to perform post-order traversal
    void postOrder() {
        cout << "Post-order traversal: ";
        postOrderUtil(root);
        cout << endl;
    }

    // Function to set the root of the binary tree
    void setRoot(TreeNode* node) {
        root = node;
    }
};

int main() {
    // Constructing a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    BinaryTree binaryTree;
    binaryTree.setRoot(root);

    // Perform tree traversals
    binaryTree.preOrder();
    binaryTree.inOrder();
    binaryTree.postOrder();

    return 0;
}
