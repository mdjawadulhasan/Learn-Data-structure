#include <iostream>
using namespace std;

class node
{
public:
  int position_count;
  int data;
  node *next;
};

class Circuler
{
public:
  node *start;
  int count = 0;

  Circuler()
  {
    start = NULL;
  }

  void createNode(int val)
  {
    node *current;
    current = new node;

    if (start == NULL)
    {
      start = current;
      current->next = start;
      current->position_count = ++count;
      current->data = val;
    }
    else
    {
      node *temp = start;
      while (temp->next != start)
      {
        temp = temp->next;
      }
      temp->next = current;
      current->next = start;
      current->position_count = ++count;
      current->data = val;
    }
  }
  node *postion_check(int p)
  {
    node *tempcurrent = start;

    do
    {
      if (tempcurrent->position_count == p)
      {
        return tempcurrent;
      }
      tempcurrent = tempcurrent->next;
    } while (tempcurrent != start);
  }
  void insert_atbegin(int val)
  {

    node *ptr = start;
    node *current = new node;
    while (ptr->next != start)
    {
      ptr = ptr->next;
    }
    current->data = val;
    current->position_count = 1;
    ptr->next = current;
    current->next = start;
    start = current;
    cout << "Node Inserted at beginning" << endl;

    node *tempstart;
    tempstart = current;

    do
    {
      tempstart->next->position_count++;
      tempstart = tempstart->next;
    } while (tempstart->next != start);
  }

  void insertNodeAfter(int vl, int pos)
  {
    node *current;
    current = new node;
    node *ptr = postion_check(pos);
    if (ptr->next == start) //end
    {
      current->next = start;
      ptr->next = current;
      current->data = vl;
      current->position_count = ++pos;
      cout << "Node Inserted at the End" << endl;
    }
    else //between
    {
      current->next = ptr->next;
      ptr->next = current;
      current->data = vl;
      current->position_count = ++pos;
      cout << "Node Inserted in position :" << current->position_count << endl;

      node *tempstart;
      tempstart = current;

      do
      {
        tempstart->next->position_count++;
        tempstart = tempstart->next;
      } while (tempstart->next != start);
    }
  }

  void deleteNode(int k)
  {

    if (start->position_count == k) //beginning
    {
      node *temp = start;
      while (temp->next != start)
      {
        temp = temp->next;
      }
      start = start->next;
      temp->next = start;
      cout << "Node deleted from the beginning : " << endl;
      node *tempstart;
      tempstart = start;

      do
      {
        tempstart->next->position_count--;
        tempstart = tempstart->next;
      } while (tempstart->next != start);
    }
    else //between and end
    {

      node *delete_node, *prev_node;
      delete_node = postion_check(k);
      prev_node = postion_check(k - 1);

      prev_node->next = delete_node->next;
      cout << "Node deleted at position : " << k << endl;
      node *tempstart;
      tempstart = delete_node;

      do
      {
        tempstart->next->position_count--;
        tempstart = tempstart->next;
      } while (tempstart->next != start);
    }
  }

  void printList()
  {
    node *temp = start;

    do
    {
      cout << temp->data << " --> ";
      temp = temp->next;
    } while (temp != start);

    cout << endl;
  }
};

int main()
{

  Circuler b;
  cout << "Elements of the Circular linked list are :" << endl;
  b.createNode(10);
  b.createNode(15);
  b.createNode(42);
  b.printList();
  cout << endl;

  b.insertNodeAfter(20, 3); //Inserting at the end
  b.printList();
  b.insert_atbegin(34); //Inserting at the beginning
  b.printList();
  b.insertNodeAfter(52, 4); //Inserting between
  b.printList();

  b.deleteNode(2); //Deleting between
  b.printList();
  b.deleteNode(5); //Deleting at the end
  b.printList();
  b.deleteNode(0); //Deleting at the beginning
  b.printList();
}
