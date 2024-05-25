#include <iostream>

using namespace std;

const int MAX_LEVEL = 10;

class node
{
public:
    int val;
    node *next[MAX_LEVEL];

    node(int data, int CurrMaxLevel)
    {
        val = data;
        for (int i = 0; i < CurrMaxLevel; i++)
        {
            next[i] = nullptr;
        }
    }
};

class skipList
{
private:
    node *head;       // This node is just for starting, doesn't hold any value
    int CurrMaxLevel; // max current CurrMaxLevel
    float p;          // prob threshold
public:
    skipList()
    {
        p = 0.5;
        CurrMaxLevel = 1;
        head = new node(INT16_MIN, MAX_LEVEL);
    }

    int randomLevel()
    {
        int lvl = 1;
        while (((float)rand() / RAND_MAX) > p && lvl < MAX_LEVEL)
        {
            lvl++;
        }
        return lvl;
    }

    void insert(int value)
    {
        node *update[MAX_LEVEL]; // Update stores the node at each CurrMaxLevel, after which insertion would take place
        node *current = head;

        for (int i = CurrMaxLevel - 1; i >= 0; i--)
        {
            while (current->next[i] != nullptr && current->next[i]->val < value)
            {
                current = current->next[i];
            }
            update[i] = current;
        }

        // current = current->next[0]; // Imp step

        int newLevel = randomLevel();
        cout<<"level for "<<value<<" is "<<newLevel<<endl;
        if (newLevel > CurrMaxLevel)
        {
            for (int i = CurrMaxLevel; i < newLevel; i++)
            {
                update[i] = head; // As top CurrMaxLevels were empty, so update would store head
            }
            CurrMaxLevel = newLevel; // Imp step
        }

        node *newNode = new node(value, newLevel); // make the new node wlith newLevel

        for (int i = 0; i < newLevel; i++)
        {
            newNode->next[i] = update[i]->next[i]; // Adjust next for new node
            update[i]->next[i] = newNode;
        }
        return;
    }

   bool search(int value, int &comp)
    {
        node *curr = head;
        comp = 0;
        for (int i = CurrMaxLevel - 1; i >= 0; i--)
        {
            while (curr->next[i] != nullptr && curr->next[i]->val < value)
            {
                curr = curr->next[i];
                comp++;
            }
            if (curr->next[i] != nullptr)
            {
                comp++;
            }
            if (curr->next[i] != nullptr && curr->next[i]->val == value)
            {
                comp++;
                // return {true, comp};
                return true;

            }
        }
        // return {false, comp};
        return false;
    }

    void iter(){
        node *curr = head;

        while (curr->next[0] != nullptr)
        {
        cout<<curr->next[0]->val<<" ";
                curr = curr->next[0];
        
        }
        
    }
};

int main()
{
    cout << endl;
    srand(time(NULL)); // Very important

    // srand(1); // Very important

    skipList abc;

    // Inserting some values into the skip list
    // skipList.insert(3);
    // skipList.insert(6);
    // skipList.insert(9);
    // skipList.insert(12);
    // skipList.insert(15);
    // skipList.insert(18);
    // skipList.insert(21);

    abc.insert(3);
    abc.insert(6);
    abc.insert(9);
    abc.insert(12);
    abc.insert(1);
    abc.insert(21);
    abc.insert(15);

    int searchKey = 15;
    int comp = 0;
    bool found = abc.search(searchKey,comp);

    if (found)
        cout << "Key " << searchKey << " found in Skip List with " <<comp<< endl;

    else
        cout << "Key " << searchKey << " not found in Skip List with " <<comp<<  endl;

    abc.iter();
    cout << endl;

    return 0;
}
