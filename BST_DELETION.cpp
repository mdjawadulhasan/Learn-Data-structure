#include <iostream>
using namespace std;

class bnode
{
public:
    int info;
    bnode *left, *right;
};

class bst
{
public:
    bnode *root;
    bst()
    {
        root = NULL;
    }
    void insertall(int a[], int aSize);

    void create(int element)
    {
        if (root == NULL)
        {
            root = new bnode;
            root->info = element;
            root->left = root->right = NULL;
            return;
        }

        bnode *temp, *r;
        temp = new bnode;
        temp->info = element;
        temp->left = temp->right = NULL;
        r = root;
        while (r != NULL)
        {
            if (element < r->info)
            {
                if (r->left == NULL)
                {
                    r->left = temp;
                    break;
                }
                else
                {
                    r = r->left;
                }
            }
            else if (element > r->info)
            {
                if (r->right == NULL)
                {
                    r->right = temp;
                    break;
                }
                else
                {
                    r = r->right;
                }
            }
        }
    }

    bnode *find_min(bnode *node)
    {
        bnode *current = node;
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    bnode *deleteNode(bnode *r, int v)
    {
       
        if (r == NULL)
        {
            return NULL;
        }
        else if (v < r->info)
        {
            r->left = deleteNode(r->left, v);
        }
        else if (v > r->info)
        {
            r->right = deleteNode(r->right, v);
        }
        else
        {
            
            if (r->left == NULL)
            {
                bnode *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                bnode *temp = r->left;
                delete r;
                return temp;
            }
            else
            {   
                bnode *temp = find_min(r->right);
                r->info = temp->info;
                r->right = deleteNode(r->right, temp->info);
            }
        }
        return r;
    }
    void printPreorder(bnode * r) 
  {
    if (r == NULL)
      return;
   
    cout << r ->info << " ";
    
    printPreorder(r->left);
   
    printPreorder(r ->right);
  }
};

void bst::insertall(int a[], int aSize)
{
    for (int i = 0; i < aSize; i++)
    {
        create(a[i]);
    }
}

int main()
{

    bst b;
    int a[] = {35, 37, 52, 92, 3, 60, 40, 30, 25, 2};
    int N = sizeof(a) / sizeof(a[0]);
    b.insertall(a, N);
    b.printPreorder(b.root);
    b.deleteNode(b.root, 37);
    cout<<endl;
    b.printPreorder(b.root);
}