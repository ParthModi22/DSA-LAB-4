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
class BST{
    private:
    node *r;

    void preorder(node* root){
        if(root == nullptr){
            return;
        }
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    void inorder(node* root){
        if(root == nullptr){
            return;
        }
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
    void postorder(node* root){
        if(root == nullptr){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
    node* insert(node*root,int key){
        if(root ==nullptr){
            return new node(key);
        }
        if(key<root->key){
            root->left = insert(root->left,key);
        }
        else if(key>root->key){
            root->right = insert(root->right,key);
        }
        return root;
    }
    public:
    BST(){
        r = nullptr;
    }
    void preorder(){
        cout<<"preorder"<<" ";
        preorder(r);
        cout<<endl;
    }
    void inorder(){
        cout<<"inorder"<<" ";
        inorder(r);
        cout<<endl;
    }
    void postorder(){
        cout<<"postorder"<<" ";
        postorder(r);
        cout<<endl;
    }
    void insert(int key){
        r = insert(r,key);
    }


};




int main()
{
   BST p;
   p.insert(10);
   p.insert(1);
   p.insert(11);
   p.insert(13);
   p.insert(15);
   p.insert(11);

   p.preorder();
   p.inorder();
   p.postorder();
   return 0;
}