#include<iostream>
using namespace std;

const int MAX_LEVEL = 6;

// node structure of a skiplist
struct node {
   int key;
   node **forward;
   node(int k,int level){
      key = k;
      forward = new node*[level+1] ;{}
   }
   ~node(){
      delete []forward;
   }
};

//skip list 
class skiplist{
   int level; 
   node *header;
   public:
   skiplist(){
      level=0;
      header= new node(INT_MIN,MAX_LEVEL);
   }
   ~skiplist(){
      delete header;
   }
   int randomlevel(){
      int lvl=0;
      while(rand()%2 && lvl<MAX_LEVEL){
         lvl++;
      }
      return lvl;
   }
   node *createnode(int key,int level){
      node *newnode = new node(key,level);
      return newnode;
   }
   void insert(int key){
      int newLevel = randomlevel();

    // Update the Skip List level if necessary
      if (newLevel > level) {
        level = newLevel;
      }

    // Create an array to store the update pointers
      node *update[level + 1];
      node *current = header;

    // Traverse through each level to find the insertion point
      for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
      }

    current = current->forward[0];

    // If the key is not present, insert it into the Skip List
    if (current == nullptr || current->key != key) {
        // Create a new node with the determined level
        node *newNode = createnode(key, newLevel);

        // Update the forward pointers to insert the new node
        for (int i = 0; i <= newLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
   }
   bool search(int key, int &comp){
      node *current = header;
      for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->key < key) {
            current = current->forward[i];
            comp++;
        }
      }
      current = current->forward[0];
      comp++;

      if (current != nullptr && current->key == key) {
        return true;
      } 

      return false;
   }
   void display(){
      cout << "Skip List:" << endl;

      for (int i = level; i >= 0; i--) {
        node *current = header->forward[i];
        cout << "Level " << i << ": ";
        while (current != nullptr) {
            cout << current->key << " ";
            current = current->forward[i];
        }
        cout << endl;
      }
   }

};
int main()
{
   skiplist list;
   list.insert(1);
   list.insert(2);
   list.insert(3);
   list.insert(4);
   list.insert(11);
   list.insert(16);
   list.insert(55);
   list.insert(103);

   list.display();
   int comp =0;
   int keytofind = 16;
   bool found = list.search(keytofind,comp);

   if(found){
      cout<<"key "<<keytofind<<" found with "<<comp<<" comparisions"<<endl;
   }
   else{
      cout<<"not found "<<endl;
   }
   return 0;
}
