#include <iostream>
using namespace std;

class TreeNode; // Forward declaration

class ListNode {
public:
    TreeNode* child;
    ListNode* next;

    ListNode(TreeNode* node) : child(node), next(nullptr) {}
};

class TreeNode {
public:
    int data;
    TreeNode* nextSibling;  // For linked list implementation
    ListNode* firstChild;   // For linked list implementation
    TreeNode** children;    // For array implementation
    int numChildren;        // For array implementation

    TreeNode(int value) : data(value), nextSibling(nullptr), firstChild(nullptr), children(nullptr), numChildren(0) {}

    // Function to add a child to a given parent node (linked list implementation)
    void addChildLinkedList(int value) {
        TreeNode* newNode = new TreeNode(value);
        ListNode* newNodeWrapper = new ListNode(newNode);

        if (firstChild == nullptr) {
            firstChild = newNodeWrapper;
        } else {
            ListNode* current = firstChild;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNodeWrapper;
        }
    }

    // Function to add a child to a given parent node (array implementation)
    void addChildArray(int value) {
        if (children == nullptr) {
            children = new TreeNode*[1];
        } else {
            TreeNode** temp = new TreeNode*[numChildren + 1];
            for (int i = 0; i < numChildren; ++i) {
                temp[i] = children[i];
            }
            delete[] children;
            children = temp;
        }

        children[numChildren] = new TreeNode(value);
        ++numChildren;
    }
};

class UnboundedBranchTree {
public:
    TreeNode* root;

    UnboundedBranchTree(int value) {
        root = new TreeNode(value);
    }

    // Function to add a child to a given parent node (linked list implementation)
    void addChildLinkedList(TreeNode* parent, int value) {
        parent->addChildLinkedList(value);
    }

    // Function to add a child to a given parent node (array implementation)
    void addChildArray(TreeNode* parent, int value) {
        parent->addChildArray(value);
    }
};

int main() {
    UnboundedBranchTree tree(1);

    // Adding children using linked list implementation
    TreeNode* parentLinkedList = tree.root;
    tree.addChildLinkedList(parentLinkedList, 2);
    tree.addChildLinkedList(parentLinkedList, 3);
    tree.addChildLinkedList(parentLinkedList, 4);

    // Adding children using array implementation
    TreeNode* parentArray = tree.root;
    tree.addChildArray(parentArray, 5);
    tree.addChildArray(parentArray, 6);
    tree.addChildArray(parentArray, 7);

    return 0;
}
