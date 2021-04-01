#include <iostream>
using namespace std;

class bnode
{
public:
  int height;
  int age, NID;
  string name;
  bnode *left, *right;
};

class bst
{
public:
  bnode *root;
  int count=0,sum=0;
  bst()
  {
    root = NULL;
  }
  void create(int element, int age, int NID, string name);
  void insertall(int a[], int age[], int NID[], string name[], int Size);
  void printabove(bnode *rp);
  void printavg(bnode *r);

};

void bst::create(int element, int ag, int ND, string nme)
{
  if (root == NULL)
  {
    root = new bnode;
    root->height = element;
    root->age = ag;
    root->NID = ND;
    root->name = nme;
    root->left = root->right = NULL;
    return;
  }

  bnode *temp, *r;
  temp = new bnode;
  temp->height = element;
  temp->age = ag;
  temp->NID = ND;
  temp->name = nme;
  temp->left = temp->right = NULL;
  r = root;
  while (r != NULL)
  {
    if (element < r->height)
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
    else if (element > r->height)
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

void bst::insertall(int a[], int age[], int NID[], string name[], int Size)
{
  for (int i = 0; i < Size; i++)
  {

    create(a[i], age[i], NID[i], name[i]);
  }
}
void bst::printabove(bnode *rp)
{
  if (rp == NULL)
    return;

  if ((rp->height) > 140)
  {
    double h=rp->height;
    cout << "Height :" << h/100<< " m" << endl;
    cout << "Name :" << rp->name << endl;
    cout << "Age :" << rp->name << endl;
    cout << "NID :" << rp->NID << endl;
    cout << endl;
  }

  printabove(rp->left);

  printabove(rp->right);
}

void bst::printavg(bnode *r)
{
  
  if (r == NULL)
  {
     return ;
  }

  if ((r->height) < 140)
  {
  count++;
  sum=sum+(r->height);
  }

  printavg(r->left);

 printavg(r->right);
  

}

int main()
{

  bst b;
  
  float height[] = {1.19,1.66,1.35,1.58,1.65,1.48,1.87,1.40,1.64,1.10};
  int heightin_cm[10];
  for(int i=0;i<10;i++)
  {
    
    heightin_cm[i]=(height[i]*100);
  }



  int ag[] = {23, 25, 27, 20, 30, 40, 45, 32, 37, 19};
  string nme[] = {"Sihan", "Rubel", "Karim", "Ratul", "Ishan", "Zishan", "Rakib", "Rana", "Ahmed", "Rasel"};
  int nd[] = {1212, 3221, 1642, 9020, 2311, 1219, 5422, 9011, 3421, 8920};

  b.insertall(heightin_cm, ag, nd, nme, 10);
  b.printabove(b.root);
  b.printavg(b.root);
  float avgheight=b.sum/b.count;
  cout<<"Average age of people whose  age is less than 1.4m is  :"<<avgheight/100<<"m"<<endl;
}
