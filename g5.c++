// dijkastra

#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int> > > buildGraph(){
	int v, e;
	cout<<"no of vertices"<<endl;
	cin>>v;
	cout<<"no of edges"<<endl;
	cin>>e;
	cout<<"enter edges"<<endl;
	int e1, e2, e3;
	vector<vector<pair<int, int> > > graph(v+1);
	for(int i=0;i<e;i++){
		cin>>e1>>e3>>e2;
		graph[e1].push_back({e2, e3});
	}
	return graph;
}


void dijkstra(int st, vector<vector<pair<int, int> > > &graph){
	int v = graph.size();
	vector<int> visited(v, 0);
	vector<int> distance(v, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >  pq;
	distance[st] = 0;
	visited[st] = 1;
	pq.push({0, st});
	while(!pq.empty()){
		auto temp = pq.top();
		pq.pop();
		int node = temp.second;
		visited[node] = 1;
		cout<<"node "<<node<<endl;
		int val = temp.first;
		vector<pair<int, int> > n = graph[node];
		for(int i=0;i<n.size();i++){
			if(!visited[n[i].second]){
				if(val + n[i].first < distance[n[i].second]){
					cout<<"y"<<endl;
					distance[n[i].second] = val + n[i].first;
					pq.push({distance[n[i].second], n[i].second});
				}
			}
		}
	}

	for(int i=1;i<v;i++)
		cout<<distance[i]<<" ";
	cout<<endl;
}

int main(){
	vector<vector<pair<int, int> > > graph = buildGraph();
	dijkstra(1, graph);
}



6 3 0 1 2 0 2 3 1 1 3 0 3 4 0 4 3 1 1 4 