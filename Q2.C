
#include <iostream>

using namespace std;

class BST
{
private:
    int *arr;

public:
    BST()
    {
        arr = new int[30];
        for (int i = 0; i < 30; i++)
        {
            arr[i] = INT16_MIN; 
        }
    }

    void inorder(int index)
    {
        if (arr[index] != INT16_MIN)
        {
            inorder(2 * index + 1);
            cout << arr[index] << " ";
            // cout<<endl<<index<<endl;
            inorder(2 * index + 2);
        }
        return;
    }

    void insert(int n)
    {
        int i = 0;
        // int val = arr[i];
        while (arr[i] != INT16_MIN)
        {
            if (n < arr[i])
            {
                i = i * 2 + 1;
                // val = arr[i];
            }
            else
            {
                i = i * 2 + 2;
                // val = arr[i];
            }
        }
        arr[i] = n;
    }

    int search(int n)
    {
        int i = 0;
        // int val = arr[i];
        while (arr[i] != INT16_MIN)
        {
            if (arr[i] == n)
            {
                return i;
            }

            else if (n < arr[i])
            {
                i = i * 2 + 1;
                // val = arr[i];
            }
            else
            {
                i = i * 2 + 2;
                // val = arr[i];
            }
        }
        return INT16_MIN; // if not found
    }
    int pre(int index)
    {
        int i = index * 2 + 1; // leftSubtree
        while (arr[i * 2 + 2] != INT16_MIN)
        {
            i = i * 2 + 2;
        }
        return i;
    }

    int suc(int index)
    {
        int i = index * 2 + 2; // Right subtree
        while (arr[i * 2 + 1] != INT16_MIN)
        {
            i = i * 2 + 1;
        }
        return i;
    }

    void deletion(int n, int index)
    {
        int a = search(n);
        // cout << "\ntest " << a << " " << index << " " << n << endl;
        if (a == INT16_MIN)
        {
            cout << "\ndeletion not possible\n";
            return;
        }

        a = index;
        while (arr[a] != INT16_MIN)
        {
            int &value = arr[a];
            int r = 2 * a + 2;
            int l = 2 * a + 1;
            int &LeftVal = arr[l];
            int &RightVal = arr[r];
            if (LeftVal == INT16_MIN && RightVal == INT16_MIN) // Leaf node
            {
                value = INT16_MIN;
                return;
            }

            if (n < value)
            {
                a = l;
                continue;
            }
            else if (n > value)
            {
                a = r;
                continue;
            }

            if (LeftVal == INT16_MIN)
            {
                value = arr[suc(a)];
                a = r;
                deletion(value, a);
                return;
            }
            else
            {
                value = arr[pre(a)];
                // cout << "test3 " << pre(a) << endl;
                // cout << "test2 " << value << endl;
                a = l;
                deletion(value, a);
                return;
            }
        }
        return;
    }

    void print()
    {
        for (int i = 0; i < 30; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    cout << endl;
    BST alpha;
    alpha.insert(5);
    alpha.insert(6);
    alpha.insert(9);
    alpha.insert(4);
    alpha.insert(1);

    // if (alpha.search(5) == INT16_MIN)
    //     cout << "\n not found \n";

    // else
    // {
    //     cout << "\n found at " << alpha.search(5) << endl;
    // }

    // if (alpha.search(11) == INT16_MIN)
    //     cout << "\n not found \n";

    // else
    // {
    //     cout << "\n found at " << alpha.search(11) << endl;
    // }

    alpha.inorder(0);
    cout << endl;
    // alpha.print();

    alpha.deletion(5, 0);
    // alpha.print();
    alpha.inorder(0);
    alpha.deletion(4, 0);
    cout<<endl;
    alpha.inorder(0);

    alpha.deletion(1, 0);
    cout<<endl;
    alpha.inorder(0);

    cout << endl
         << endl;
    return 0;
}