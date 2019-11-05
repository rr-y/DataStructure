#include<iostream>
#include "rry_header.h"
using namespace std;

heapUtility::heapUtility(int* a, int n)
{
    heap = new int[n];
    for(int i=0;i<n;i++)
        heap[i] = a[i];
    size = n;
}
void heapUtility::swap(int i, int j)
{
    int temp;
    temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void heapUtility::heapify(int i)
{

    int left, right, large;
    left = 2*i + 1;
    right = 2*i + 2;
    large = i;
    if(left < size && heap[i] < heap[left])
    {
        large = left;
    }
    
    if (right < size && heap[large] < heap[right])
    {
        large = right;
    }

    if(large != i)
    {  
        swap(i, large);
        heapify(large);
    }

}

void heapUtility::buildHeap()
{
    for(int i = size/2-1; i>=0;i--)
    {
        heapify(i);
    }
}

void heapUtility::printHeap()
{
    for(int i=0;i<size;i++)
        cout<<heap[i]<<" ";
    cout<<"\n";
}

int heapUtility::popHeap()
{
    int max_val = heap[0];
    swap(0,size-1);
    size -= 1;
    heapify(0);
    return max_val;
}

int heapUtility::isPresent(int val)
{
    for(int i=0; i<size; i++)
    {
        if(heap[i] == val)
            return 1;
    }
    return 0;
}

int heapUtility::isEmpty()
{
    if(size == 0)
        return 1;
    return 0;
}

void heapUtility::decKey(int val, int loc)
{
    heap[loc] = val;
    heapify(loc);
}

void heapUtility::incKey(int val, int loc)
{
    int current, parent;
    heap[loc] = val;
    current = loc;
    parent = current/2;
    while(heap[parent] < heap[current] && current != parent)
    {
        swap(current,parent);
        current = parent;
        parent = current/2;
    }
}

void heapUtility::heapSort()
{
    int n = size;
    while(size != 0)
    {
        swap(0,size-1);
        size -= 1;
        heapify(0);

    }
    for(int i=0;i<n;i++)
        cout<<heap[i]<<" ";
    cout<<"\n";
    size = n;
}


// int main()
// {
//     int a[] = {4,3,2,1,6,8,9};
//     heapUtility* h = new heapUtility(a,7);
//     h->buildHeap();
//     h->printHeap();
//     h->incKey(11,6);
//     h->printHeap();
//     h->decKey(1,1);
//     h->printHeap();
//     h->heapSort();
//     return 0;
// }