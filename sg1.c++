#include<bits/stdc++.h>
using namespace std;

int merge(int a, int b){
	return a+b;
}

void buildTree(vector<int> &arr, vector<int> &tree, int treeIndex, int st, int ed){
	if(st == ed){
		tree[treeIndex] = arr[st];
		return;
	}
N
	int mid = st + (ed-st)/2;
	buildTree(arr, tree, 2*treeIndex+1, st, mid);
	buildTree(arr, tree, 2*treeIndex+2, mid+1, ed);
	tree[treeIndex] = merge(tree[2*treeIndex+1], tree[2*treeIndex+2]);
}


void update(vector<int> &arr, vector<int> &tree, int treeIndex, int st, int ed, int index, int val){
	if(st == ed){
		arr[st] = val;
		tree[treeIndex] = val;
		return;
	}

	int mid = st + (ed-st)/2;
	if(index <= mid){
		update(arr, tree, 2*treeIndex+1, st, mid, index, val);
	}
	else{
		update(arr, tree, 2*treeIndex+2, mid+1, ed, index, val);
	}
	tree[treeIndex] = merge(tree[2*treeIndex+1], tree[2*treeIndex+2]);
	return; 
}

int query(vector<int> &arr, vector<int> &tree, int treeIndex, int st, int ed, int i, int j){
	if(i > j){
		return 0;
	}
	else if(st == i && ed == j){
		return tree[treeIndex];
	}

	int mid = st + (ed-st)/2;
	int left = query(arr, tree, 2*treeIndex+1, st, mid, i, min(j, mid));
	int right = query(arr, tree, 2*treeIndex+2, mid+1, ed, max(i, mid+1), j);

	return merge(left, right);
}


int main(){
	vector<int> arr = {1, 3, 5, 7, 9};
	vector<int> tree(4*arr.size(), 0);
	buildTree(arr, tree, 0, 0, arr.size()-1);
	cout<<query(arr, tree, 0, 0, arr.size()-1, 1, 2)<<endl;
	update(arr, tree, 0, 0, arr.size()-1, 3, 28);
	cout<<query(arr, tree, 0, 0, arr.size()-1, 3, 3)<<endl;
}