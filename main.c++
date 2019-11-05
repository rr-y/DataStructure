#include<iostream>
#include "rry_header.h"
using namespace std;

int main()
{
    int a[] = {4,3,2,1,6,8,9};
    heapUtility* h = new heapUtility(a,7);
    h->buildHeap();
    h->printHeap();
    h->incKey(11,6);
    h->printHeap();
    h->decKey(1,1);
    h->printHeap();
    h->heapSort();
    return 0;
    
}