#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getMin(vector<int>& A){
	return A[0];
}

void heapify(vector<int> &A, int i){
	int leftC = 2*i+1;
	int rightC = 2*i+2;
	int small = i;
	if(leftC < A.size() and A[small] > A[leftC]){
		small = leftC;
	}
	if(rightC < A.size() and A[small] > A[rightC]){
		small = rightC;
	}
	if(small != i){
		swap(A[i], A[small]);
		heapify(A, small);
	}
}

void deleteMin(vector<int> &A){
	swap(A[0], A[A.size()-1]);
	A.pop_back();
	heapify(A, 0);
}

void insert(vector<int> &A, int val){
	A.push_back(val);
	int index = A.size()-1;
	while(index){
		int parent = index/2;
		if(A[index] < A[parent]){
			swap(A[index], A[parent]);
		}
		index = parent;
	}
}

void buildHeap(vector<int> &A){
	for(int i=A.size()/2-1; i>=0; i--){
		heapify(A, i);
	}
}

int main(){
	vector<int> A = {7,5,3,0,8,9};
	buildHeap(A);
	cout<<getMin(A)<<endl;
	deleteMin(A);
	cout<<getMin(A)<<endl;
	insert(A,-40);
	cout<<getMin(A)<<endl;
}
