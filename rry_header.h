#ifndef RRY_HEADER    // To make sure you don't declare the function more than once by including the header multiple times.
#define RRY_HEADER

class heapUtility
{
     private:
        int* heap;
        int size;
    
    public:
        heapUtility(int* a, int n);
        void swap(int i, int j);
        void heapify(int i);
        void buildHeap();
        void printHeap();
        int popHeap();
        int isPresent(int val);
        int isEmpty();
        void decKey(int val, int loc);
        void incKey(int val, int loc);
        void heapSort();
};
#endif