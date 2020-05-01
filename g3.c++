// check cycle

#include<bits/stdc++.h>
using namespace std;


void isCycle(int st, vector<int> &visited, vector<vector<int> > &graph){
	visited[st] = 1;
	bool cycle = false;
	queue<int> q;
	q.push(st);
	while(!q.empty()){
		int node = q.front();
		q.pop();
		// print here
		vector<int> n = graph[node];
		for(int i=0;i<n.size();i++){
			if(visited[n[i]] == 1){
				cycle = true;
				break;
			}
			else{
				visited[n[i]] = 1;
				q.push(n[i]);
			}
		}
	}
	cout<<"There is cycle "<<cycle<<endl;

}

bool isCycle1(int st, vector<int> &visited, vector<vector<int> > &graph){
	if(visited[st]  == 1)
		return true;

	vector<int> n = graph[st];
	visited[st] = 1;
	bool answer = false;
	if(n.size() > 0){
		for(int i=0;i<n.size();i++){
			answer = answer || isCycle1(n[i], visited, graph);
		}
	}
	return answer;
}

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


int main(){
	vector<vector<int> > graph = buildGraph();
	vector<int> visited(graph.size(), 0);
	bool answer = false;
	for(int i=1;i<visited.size();i++){
		if(visited[i] == 0)
			answer = answer || isCycle1(i, visited, graph);
	}
	cout<<"isCycle "<<answer<<endl;
}