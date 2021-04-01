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
	void create(int);
	void insertall(int a[], int aSize);
	void traverse();
	void pre_order(bnode *root);
	void in_order(bnode *root);
	void post_order(bnode *root);
	bnode *search(int v)
	{
		bnode *tempnode = root;
		while (tempnode!= NULL)
		{
			if (v == tempnode->info)
			{
				return tempnode;
				break;
			}
			else if (v < tempnode->info)
			{
				tempnode = tempnode->left;
			}
			else
			{
				tempnode = tempnode->right;
			}
			
		}
		return NULL;
	}
};

void bst::create(int element)
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

void bst::insertall(int a[], int aSize)
{
	for (int i = 0; i < aSize; i++)
	{
		create(a[i]);
	}
}

int main()
{
	int element;
	cout<<"Enter the element you want to search :";
	cin>>element;
	bst b;
	int a[] = {35, 37, 49, 65, 80, 60, 40, 30, 25, 2};
	int N = sizeof(a) / sizeof(a[0]);
	b.insertall(a, N);


	if(b.search(element)==NULL)
	{
		cout<<"Element Not Found"<<endl;
	}
	else
	{
		cout<<b.search(element)<<endl;
	}
	
}