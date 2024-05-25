#include <iostream>
using namespace std;

class node
{
    int val;
    node *left;
    node *right;
    int height;

public:
    node(int, node *, node *);
    friend void inOrder(node *);
    friend void preOrder(node *);
    friend void postOrder(node *);
    friend int getHeight(node *);
    friend node *rightRotate(node *);
    friend node *leftRotate(node *);
    friend node *insert(node *, int);
    friend int getBalanceFactor(node *);
};

node::node(int data, node *Left = NULL, node *Right = NULL)
{
    val = data;
    left = Left;
    right = Right;
    height = 1; // As per convention, we consider leaf node's height as 1
}

int getBalanceFactor(node *n)
{
    return getHeight(n->left) - getHeight(n->right);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

node *createNode(int data)
{
    node *root = new node(data);
    return root;
}

node *insert(node *node, int val) // This a type of tail recursion as no operation will be performed after recursive function is called;Function terminates as soon it is returned; Whenever function is returned, it is Tail recursion
{
    if (node == NULL)
        return createNode(val); // First line to run; No further operations are possible after return, so it is Tail Recursion

    // Below code is a standard insertion in a BST code
    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val); // Second line to run, this will recusively go to run "createNode()" if node->right is NULL

    // insertion happens via top-To-Bottom recursion
    // Height updation and consequent rotations happen via Bottom-To-Top recursion as recursion stack unwinds

    node->height = 1 + max(getHeight(node->left), getHeight(node->right)); // Height of single node is 1, so we added "1" as if both left and right node's height is zero, then also height of root node is 1

    // As function is recursive, so it will run height will first be updated for leaf nodes, not root node (make a flow chart if you have any confusion)

    int bf = getBalanceFactor(node); // bf is the Balance FActor

    // First, we do normal BST insertion
    // Second, we update the heights of inserted node(to get bf factor )
    // Third and lastly, we rotate the Tree accordingly wrt imbalanced node

    // Left Left Case
    if (bf > 1 && val < node->left->val) //-------> if bf>1, that means it is the first imbalance node and inserted node is on left as: bf = height(left node) - height(left node);
    // Then we check if value is on left or right again;  In this case that's how we get LL case
    {
        return rightRotate(node);
    }

    // Right Right Case
    else if (bf < -1 && val > node->right->val)
    {
        return leftRotate(node);
    }

    // Left Right Case
    else if (bf > 1 && val > node->left->val) // Triangle formation
    {
        node->left = leftRotate(node->left); // First rotation is done wrt child of FIB along inserted node(to make a line formation)
        return rightRotate(node);
    }

    // Right Left Case
    else if (bf < -1 && val < node->right->val) // Triangle formation
    {
        node->right = rightRotate(node->right); // First rotation is done wrt child of FIB along inserted node
        return leftRotate(node);
    }
    return node;
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}
void preOrder(node *root)
{
    if (root != NULL)
    {
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << " ";
    }
}

int main()
{
    node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    root = insert(root, 0);

    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    preOrder(root);

    return 0;
}

int getHeight(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

node *rightRotate(node *y) // See diagram to know how this is working
{
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x; // As in linked list, we returned head after every function, here we are returning the new root node "x"
    // As we took node as an input, we should also return an updated node
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return y;
}
