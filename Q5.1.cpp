#include<iostream>
using namespace std;
class node{
    public:
    int key;
    node* left;
    node* right;

    node(int val){
        this->key= val;
        this->left=nullptr;
        this->right=nullptr;
    }
};
class BT{
    private:
    node* root;
    //helper code of pre-order
    void preorder(node* root){
        if(root == nullptr){
            return;
        }
        cout<<root->key<<' ';
        preorder(root->left);
        preorder(root->right);
    }
    //helper code in-order
    void inorder(node* root){
        if(root==nullptr){
            return;
        }
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
    //helper code post-order
    void postorder(node* root){
        if(root==nullptr){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
     node* constructUtil() {
        int key;
        cout << "Enter the value for the node (-1 to terminate): ";
        cin >> key;
        if (key == -1) {
            return nullptr;
        }

        node* newNode = new node(key);
        cout << "Enter left child of " << key << ":\n";
        newNode->left = constructUtil();
        cout << "Enter right child of " << key << ":\n";
        newNode->right = constructUtil();
        return newNode;
    }
    public:
    BT(){
        root = nullptr;
    }

    //preorder
    void preorder(){
        cout<<"pre_order "<<endl;
        preorder(root);
        cout<<endl;
    }
    //inorder
    void inorder(){
        cout<<"in_order "<<endl;
        inorder(root);
        cout<<endl;
    }
    //postorder
    void postorder(){
        cout<<"pre_order "<<endl;
        postorder(root);
        cout<<endl;
    }
    //set root
    void setroot(node* root){
        this->root = root;
    }
    void maketree(){
        root = constructUtil();
    }
};
int main()
{
    BT p;
    p.maketree();
    // perform
    p.preorder();
    p.inorder();
    p.postorder();
   return 0;
}