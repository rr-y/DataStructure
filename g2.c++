// basic graph dfs bfs no of connected components
// adjacency list implementation

#include<bits/stdc++.h>
using namespace std;


void bfs(int source, vector<vector<int> > &graph, vector<int> &visited){
	queue<int> q;
	int v = graph.size();
	q.push(source);
	visited[source] = 1;
	
	while(!q.empty()){
		int node = q.front();
		q.pop();
		vector<int> neighbour = graph[node];
		for(int i=0;i<neighbour.size();i++){
			int temp = neighbour[i];
			if(!visited[temp]){
				visited[temp] = 1;
				q.push(temp);
			}
		}
	}

}

void dfs(int source, vector<vector<int> > &graph, vector<int> & visited){
	if(visited[source] == 1)
		return;
	visited[source] = 1;
	vector<int> neighbour = graph[source];
	for(int i=0;i<neighbour.size();i++){
		dfs(neighbour[i], graph, visited);
	}
}


void countComponent(vector<vector<int> > &graph){
	int v = graph.size();
	vector<int> visited(v, 0);
	int component = 0;
	for(int i=1;i<visited.size();i++){
		if(visited[i] == 0){
			bfs(i, graph, visited);
			++component;
		}
	}
	cout<<"no of component "<<component<<endl;
}

int main(){
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

	countComponent(graph);
}