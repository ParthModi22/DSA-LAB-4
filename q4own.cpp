#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node* left;
    node* right;

    node(int val){
        this->val=val;
        this->left=nullptr;
        this->right=nullptr;
    }
};

class BST{
    private:
    node* root;

    //function to insert a key in bst
    node* insert(node* root,int key,int &comp){
        if(root ==  nullptr){
            return new node(key);
        }
        if(key<root->val){
            comp++;
            root->left = insert(root->left,key,comp);
        }
        else if(key>root->val){
            comp++;
            root->right=insert(root->right,key,comp);
        } 
        return root;
    }
    //function to find min of subtree
    node* findmin(node* root){
        node* curr = root;
        while(curr->left != nullptr){
            curr = curr->left;
        }
        return curr;
    }

    //function to search in bst
    bool search(node* root,int key,int &comp){
        while(root != nullptr){
            comp++;
            if(root->val == key){
                return true;
            }
            else if(key< root->val){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return false;
    }
    //function to delete in bst
    node* remove(node* root,int key,int &comp){
        if(root == nullptr){
            return nullptr;
        }
        if(key <root->val){
            comp++;
            root->left = remove(root->left,key,comp);
        }
        else if (key>root->val){
            comp++;
            root->right = remove(root->right,key,comp);
        }else{
            //node with one or no child
            if(root->left==nullptr){
                node* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right==nullptr){
                node* temp = root->left;
                delete root;
                return temp;
            }
            // with 2 child get the in order successor (smallest in right subtree)
            node* temp = findmin(root->right);
            //copy it to this node
            root->val = temp->val;
            //delete the inorder successor
            root->right = remove(root->right,temp->val,comp);
        }
        return root;
    }
    public:
    BST(){
        root = nullptr;
    }
    //function to insert
    void insert(int key){
        int comp = 0;
        root = insert(root,key,comp);
        cout<<"insertion comparision for key "<< key<<" is "<<comp<<endl;
    }
    //function to delete
    void remove(int key){
        int comp = 0;
        root = remove(root,key,comp);
        cout<<"deletion comparision for key "<<key<< " is "<<comp<<endl;
    }
    //function to search
    bool search(int key){
        int comp =0;
        bool found = search(root, key,comp);
        if(found){
            cout<<" key "<<key<<" found with comparision "<<comp<<endl;
        }
        else{
            cout<<" key "<<key<<" not found with comparision "<<comp<<endl;
        }
        return found;
    }
};
int main()
{
    BST p;

    p.insert(5);
    p.insert(3);
    p.insert(6);
    p.insert(10);
    p.insert(11);
    p.insert(9);

    p.search(11);
    p.search(6);
    p.search(100);

    p.remove(10);
   return 0;
}