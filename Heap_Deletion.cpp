#include <iostream>
using namespace std;

void heapify(int heap[], int size, int i)
{
    int l, r, largest, temp;
    l = (2 * i) + 1;
    r = (2 * i) + 2;

    if (l <= size && heap[l] > heap[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if (r <= size && heap[r] > heap[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        heapify(heap,size,largest);
    }
}

void create_heap(int heap[],int size)
{
    int i,temp=(size/2)-1;
    for(i=temp;i>=0;i--)
    {
        heapify(heap,size,i);
    }
}

void delete_heap_element(int heap[],int size)
{
    int temp;
    temp=heap[0];
    heap[0]=heap[size];
    heap[size]=temp;
    --size;
    heapify(heap,size,0);

    

}

void print_heap(int heap[],int size)
{

    for(int i=0;i<=size;i++)
    {
        cout<<heap[i]<<endl;
    }
}

int main()
{
    int heap[]={20,15,7,6,9,2,6,5,1,7,8};
    int size=10;
    create_heap(heap,size);
    print_heap(heap,size);
    cout<<endl;
    delete_heap_element(heap,size);
    print_heap(heap,--size);
}