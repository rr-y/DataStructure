// union find algorithm
#include<bits/stdc++.h>
using namespace std;

int findRoot(int v, vector<int> &parent){
	if(parent[v] == -1){
		return v;
	}

	int p = findRoot(parent[v], parent);
	parent[v] = p;
	return p;
}


int find(int a, int b, vector<int> &parent){
	return findRoot(a, parent) == findRoot(b, parent) ? 1:0;
}

void unions(int a, int b, vector<int> &parent, vector<int> &height)
{
	int root1 = findRoot(a, parent);
	int root2 = findRoot(b, parent);

	if(height[root1] > height[root2])
		parent[root2] = root1;

	else if(height[root1] < height[root2])
		parent[root1] = root2;
	
	else{
		parent[root2] = root1;
		height[root1] += 1;
	}
}

int main(){
	int v;
	cin>>v;
	vector<int> parent(v, -1);
	vector<int> height(v, 0);
	int q;
	cin>>q;
	int a, b, c;
	while(q--){
		
		cin>>a>>b>>c;
		if(a == 1)
			unions(b, c, parent, height);
		else
			cout<<find(b,c, parent)<<endl;
	}
}
