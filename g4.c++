#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > buildGraph(){
	int v, e;
	cout<<"no of vertices"<<endl;
	cin>>v;
	cout<<"no of edges"<<endl;
	cin>>e;
	cout<<"enter edges"<<endl;
	int e1, e2;
	vector<vector<int > > graph(v+1);
	for(int i=0;i<e;i++){
		cin>>e1>>e2;
		graph[e1].push_back(e2);
	}
	return graph;
}

int isBipartite(int st, vector<int> & color, vector<vector<int> > &graph, int newCol){
	if(color[st] != 0 && color[st] == newCol)
		return 1;
	else if(color[st] != 0 && color[st] != newCol)
		return 0;

	int answer = 1;
	color[st] = newCol;
	vector<int> n = graph[st];
	for(int i=0;i<n.size();i++){
		answer = answer && isBipartite(n[i], color, graph, newCol%2+1);
	}
	return answer;
}


int main(){
	vector<vector<int> > graph = buildGraph();
	vector<int> color(graph.size(), 0);
	cout<<isBipartite(1, color, graph, 1)<<endl;
	return 0;
}