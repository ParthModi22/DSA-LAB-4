#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX_SIZE 100

class BinaryTree {
private:
    int tree[MAX_SIZE];
    int size;

public:
    BinaryTree() {
        size = 0;
    }

    void insert(int key) {
        if (size == MAX_SIZE) {
            cout << "Tree is full!" << endl;
            return;
        }
        tree[size++] = key;
    }

    bool search(int key) {
        for (int i = 0; i < size; ++i) {
            if (tree[i] == key)
                return true;
        }
        return false;
    }

    void remove(int key) {
        int i;
        for (i = 0; i < size; ++i) {
            if (tree[i] == key)
                break;
        }
        if (i == size) {
            cout << "Key not found in tree!" << endl;
            return;
        }
        for (int j = i; j < size - 1; ++j) {
            tree[j] = tree[j + 1];
        }
        size--;
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << tree[i] << " ";
        }
        cout << endl;
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

    // Deleting elements
    tree.remove(20);
    cout << "Binary Tree after deletion of 20: ";
    tree.display();

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
