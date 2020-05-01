#include<bits/stdc++.h>
using namespace std;


int merge(int a, int b){
	return (a+b);
}

void buildTree(vector<int> &arr, vector<int> &tree, int treeIndex, int st, int ed){
	if(st == ed){
		tree[treeIndex] = arr[st];
		return;
	}

	int mid = st + (ed-st)/2;
	// go left
	buildTree(arr, tree, 2*treeIndex+1, st, mid);
	// go right
	buildTree(arr, tree, 2*treeIndex+2, mid+1, ed);

	// update tree node
	tree[treeIndex] = merge(tree[2*treeIndex+1], tree[2*treeIndex+2]);
	return;
}

void update(vector<int> &arr, vector<int> &tree, vector<int> &lazy, int treeIndex, int st, int ed, int i, int j, int val){
	if(lazy[treeIndex]){
		tree[treeIndex] += (ed-st+1)*lazy[treeIndex];
		if(st != ed){
			lazy[2*treeIndex+1] += lazy[treeIndex];
			lazy[2*treeIndex+2] += lazy[treeIndex];
		}
		lazy[treeIndex] = 0;
	}
	if(i > j)
		return;

	if(st == i && ed == j){
		tree[treeIndex] += (j-i+1)*val;
		if(st != ed){
			lazy[2*treeIndex+1] = val;
			lazy[2*treeIndex+2] = val;
		}
		return ;
	}

	int mid = st + (ed-st)/2;
	update(arr, tree, lazy, 2*treeIndex+1, st, mid, i, min(j, mid), val);
	update(arr, tree, lazy, 2*treeIndex+2, mid+1, ed, max(i, mid+1), j, val);
	tree[treeIndex] = merge(tree[2*treeIndex+1], tree[2*treeIndex+2]);
	return;
}

int query(vector<int> &arr, vector<int> &tree, vector<int> &lazy, int treeIndex, int st, int ed, int i, int j){
	if(i > j)
		return 0;
	if(lazy[treeIndex]){
		tree[treeIndex] += (ed-st+1)*lazy[treeIndex];
		if(st != ed){
			lazy[2*treeIndex+1] += lazy[treeIndex];
			lazy[2*treeIndex+2] += lazy[treeIndex];
		}
		lazy[treeIndex] = 0;
	}
	if(i == st && j == ed){
		return tree[treeIndex];
	}

	int mid = st + (ed-st)/2;
	int left = query(arr, tree, lazy, 2*treeIndex+1, st, mid, i, min(mid, j));
	int right = query(arr, tree, lazy, 2*treeIndex+2, mid+1, ed, max(i, mid+1), j);
	return merge(left, right);

}




int main(){
	vector<int> arr = {1, 3, 5, 7, 9, 13, 12, 8, 7, 5, 4};
	vector<int> tree(4*arr.size(), 0);
	vector<int> lazy(4*arr.size(), 0);
	buildTree(arr, tree, 0, 0, arr.size()-1);
	cout<<query(arr, tree, lazy, 0, 0, arr.size()-1, 1, 6)<<endl;
	update(arr, tree, lazy, 0, 0, arr.size()-1, 0, 10, 2);
	cout<<query(arr, tree, lazy, 0, 0, arr.size()-1, 1, 6)<<endl;
	cout<<query(arr, tree, lazy, 0, 0, arr.size()-1, 1, 6)<<endl;
	update(arr, tree, lazy, 0, 0, arr.size()-1, 0, 10, 2);
	cout<<query(arr, tree, lazy, 0, 0, arr.size()-1, 1, 8)<<endl;

}