#include<bits/stdc++.h>
using namespace std;

class Heap{
    vector<int> heapArr;
    int size;
    public:
        Heap(vector<int> v){
            heapArr = v;
            size = v.size();
            buildHeap();
        }
    
        int length();
        int top();
        void push(int );
        void pop();
        void heapify(int );
        void buildHeap();
};

int Heap::length(){
    return size;
}

int Heap::top(){
    return heapArr[0];
}

void Heap::push(int val){
    heapArr.push_back(val);
    size++;
    int child = size-1;
    int parent = (int)ceil(child/2)-1;
    while(parent >= 0 && heapArr[parent] > heapArr[child]){
        swap(heapArr[parent], heapArr[child]);
        child = parent;
        parent = (int)ceil(child/2)-1;
    }
}

void Heap::pop(){
    swap(heapArr[0], heapArr[size-1]);
    size--;
    heapArr.erase(heapArr.end()-1);
    heapify(0);
}


void Heap::heapify(int idx){
    int left = 2*idx+1;
    int right = 2*idx+2;
    int minIdx = idx;
    if(left < size && heapArr[left] < heapArr[minIdx])
        minIdx = left;
    if(right < size && heapArr[right] < heapArr[minIdx])
        minIdx = right;
    
    if(minIdx != idx){
        swap(heapArr[idx], heapArr[minIdx]);
        heapify(minIdx);
    }
}


void Heap::buildHeap(){
    for(int i=size/2;i>=0;i--){
        heapify(i);
    }
}




int main(){

    vector<int> arr = {8, 1, 5, 4, 3, 2, 6, 7, -100};
    Heap h(arr);
    cout<<"LENGTH::"<<h.length()<<endl;
    cout<<"TOP::"<<h.top()<<endl;
    h.pop();
    h.pop();
    h.pop();
    h.pop();
    cout<<"LENGTH::"<<h.length()<<endl;
    cout<<"TOP::"<<h.top()<<endl;
    h.push(-200);
    h.push(-300);
    h.push(50);
    cout<<"LENGTH::"<<h.length()<<endl;
    cout<<"TOP::"<<h.top()<<endl;

    return 0;
}
