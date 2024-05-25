#include <iostream>
#include <vector>

using namespace std;

// Node structure for linked list
struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int val) : data(val), next(nullptr) {}
};

// Node structure for the tree
struct TreeNode
{
    int data;
    TreeNode *nextSibling;
    TreeNode *firstChild;
    TreeNode(int val) : data(val), nextSibling(nullptr), firstChild(nullptr) {}
};

// Tree class with array for storing children
class ArrayTree
{
private:
    vector<TreeNode *> children;
    TreeNode *root;

public:
    ArrayTree(int rootData)
    {
        root = new TreeNode(rootData);
        children.push_back(root);
    }

    void addChild(int parentData, int childData)
    {
        TreeNode *parentNode = nullptr;
        for (TreeNode *node : children)
        {
            if (node->data == parentData)
            {
                parentNode = node;
                break;
            }
        }

        if (parentNode != nullptr)
        {
            TreeNode *newNode = new TreeNode(childData);
            parentNode->firstChild = newNode;
            children.push_back(newNode);
        }
        else
        {
            cout << "Parent not found" << endl;
        }
    }
};

// Tree class with linked list for storing children
class LinkedListTree
{
private:
    TreeNode *root;

public:
    LinkedListTree(int rootData)
    {
        root = new TreeNode(rootData);
    }

    void addChild(int parentData, int childData)
    {
        TreeNode *parentNode = findNode(root, parentData);
        if (parentNode != nullptr)
        {
            ListNode *newNode = new ListNode(childData);
            ListNode *current = parentNode->firstChild;
            if (current == nullptr)
            {
                parentNode->firstChild = newNode;
            }
            else
            {
                while (current->next != nullptr)
                {
                    current = current->next;
                }
                current->next = newNode;
            }
        }
        else
        {
            cout << "Parent not found" << endl;
        }
    }

    TreeNode *findNode(TreeNode *node, int data)
    {
        if (node == nullptr)
            return nullptr;
        if (node->data == data)
            return node;

        TreeNode *foundNode = nullptr;
        if (node->firstChild != nullptr)
        {
            foundNode = findNode(node->firstChild, data);
        }
        if (foundNode == nullptr && node->nextSibling != nullptr)
        {
            foundNode = findNode(node->nextSibling, data);
        }
        return foundNode;
    }
};

int main()
{
    // Example usage of ArrayTree
    ArrayTree arrayTree(1);
    arrayTree.addChild(1, 2);
    arrayTree.addChild(1, 3);
    arrayTree.addChild(2, 4);
    arrayTree.addChild(2, 5);

    // Example usage of LinkedListTree
    LinkedListTree linkedListTree(1);
    linkedListTree.addChild(1, 2);
    linkedListTree.addChild(1, 3);
    linkedListTree.addChild(2, 4);
    linkedListTree.addChild(2, 5);

    return 0;
}
