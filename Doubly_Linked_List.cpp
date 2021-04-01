#include <iostream>
using namespace std;

class node
{
public:
    int data, position_count;
    node *next, *previous;
};

class list
{

public:
    int count = 0;
    node *start, *end;
    list()
    {
        start = NULL;
    }

    void create_end(int el)
    {

        node *current;

        if (start == NULL)
        {
            ++count;
            start = new node;
            start->data = el;
            start->next = NULL;
            start->previous = NULL;
            end = start;
            start->position_count = count;
        }
        else
        {
            ++count;
            current = new node;
            current->data = el;
            current->next = NULL;
            current->previous = end;
            end->next = current;
            end = current;
            current->position_count = count;
        }
    }
    node *postion_check(int p)
    {
        node *tempcurrent = start;
        while (tempcurrent != NULL)
        {
            if (tempcurrent->position_count == p)
            {
                return tempcurrent;
            }
            tempcurrent = tempcurrent->next;
        }

        
    }
    void insert_new_node(int nl, int pos)
    {
        node *current;
        current = new node;
        current->data = nl;
        node *old_node;
        if(pos!=0)
        {
            old_node = postion_check(pos);
        }

        if (old_node->next == NULL) // end
        {
            current->next = NULL;
            current->previous = old_node;
            old_node->next = current;
            current->position_count = ++pos;
            end=current;
            cout << "Node Inserted at position : " << pos << endl;
        }
        else
        {
            if (pos == 0) //beginning
            {

                start->previous = current;
                current->next = start;
                current->previous = NULL;
                current->position_count = ++pos;
                start = current;
                cout << "Node Inserted at position : " << current->position_count << endl;
            }
            else // between
            {

                current->position_count = ++pos;
                old_node->next->previous = current;
                current->next = old_node->next;
                current->previous = old_node;
                old_node->next = current;
                cout << "Node Inserted at position : " << current->position_count << endl;
            }

            while (current->next != NULL)
            {
                current->next->position_count++;
                current = current->next;
            }
        }
    }
    void deleteNode(int k)
    {

        if (start->position_count == k) //beginning
        {
            start = start->next;
            start->previous = NULL;

            cout << "Node deleted at position : " << k << endl;
            node *tempstart;
            tempstart = start;
            while (tempstart->next != NULL)
            {
                tempstart->next->position_count--;
                tempstart = tempstart->next;
            }
        }
        else
        {

            node *delete_node;
            delete_node = postion_check(k);

            if (delete_node->next == NULL) //end
            {
                delete_node->previous->next = NULL;
                end=delete_node->previous;
                cout << "Node deleted at position : " << k << endl;
            }
            else
            {
                //between
                delete_node->next->previous = delete_node->previous;
                delete_node->previous->next = delete_node->next;
                cout << "Node deleted at position : " << k << endl;
                while (delete_node->next != NULL)
                {
                    delete_node->next->position_count--;
                    delete_node = delete_node->next;
                   
                }
            }
        }
    }
    void display()
    {
        node *current;
        current = start;
        cout << "Linked List :" << endl;

        while (current != NULL)
        {
            cout << current->data << "->";
            current = current->next;
        }

        cout << endl;
    }
    void displayreverse()
    {
        node *current;
        current = end;
        cout << "Linked List :" << endl;

        while (current != NULL)
        {
            cout << current->data << "->";
            current = current->previous;
        }

        cout << endl;
    }

};
int main()
{
    list b;
    b.create_end(10);
    b.display();
    b.create_end(20);
    b.create_end(30);
    b.create_end(67);
    cout << endl;
    b.display();
    cout << endl;
    b.insert_new_node(52, 4); //Inserting at end
    b.display();
    b.insert_new_node(99, 2); //Inserting between two node
    b.display();
    b.insert_new_node(23, 0); //Inserting at the beginning
    b.display();

    b.deleteNode(7);  //Deleting at the end
    b.display();
    b.deleteNode(3);  //Deleting between two node
    b.display();
    b.deleteNode(1);  //between at the beginning
    b.display();      //displaying with next node
    cout<<endl;
    b.displayreverse();  //Displaying with previous node
}