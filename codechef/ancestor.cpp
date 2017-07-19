
//
//  Created by Amit 
//  Copyright © 2017 Amit. All rights reserved.
//


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <valarray>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <complex>

using namespace std;



#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)

class Graph
{
    int V;    
    vector<int> *adjList;

    void DFS_Util(int v, bool visited[]);
 
public:
    Graph(int v);   
    void addEdge(int v, int w);
    void printGraph();
    void BFS_Traversal(int s);
    void DFS_Traversal(int s);

};
 
 
Graph::Graph(int v)
{
    this->V = v;
    adjList = new vector<int> [v];
}
 
void Graph::addEdge(int v, int w)
{
    adjList[v-1].push_back(w-1);
    adjList[w-1].push_back(v-1);
}

void Graph::printGraph()
{
   
    for (int v = 0; v < V; ++v)
    {
        printf("\n Adjacency list of vertex %d\n head ", v);
        For(it,adjList[v])
        {
            printf("-> %d", *it);
        }
        printf("\n");
    }
}

void Graph::BFS_Traversal(int s)
{
	bool *visited = new bool[this->V];

	queue <int> q;

	for(int i = 0 ; i < this->V; i++){
		visited[i] = false;
	}

	q.push(s);
	visited[s] = true;

	while(!q.empty()){

		int v = q.front();
		q.pop();

		cout << v << " ";

		For(it,adjList[v]){

			if(visited[*it] != true){
				q.push(*it);
				visited[*it] = true;
			}
		}
	}
}

void Graph::DFS_Util(int v, bool visited[])
{
	visited[v] = true;

	cout << v << " ";

	For(it,adjList[v]){
		if(!visited[*it]){
			DFS_Util(*it,visited);
		}
	}

}

void Graph::DFS_Traversal(int s)
{
	bool *visited = new bool[this->V];

	for(int i = 0 ; i < this->V; i++){
		visited[i] = false;
	}

	DFS_Util(s,visited);
}


int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// freopen("B-small-attempt0.in","rt",stdin);
	// freopen("B.out","wt",stdout);

	int t,n,u,v;

	cin >> t;

	while(t--){

		cin >> n;

		Graph g1(n);
		Graph g2(n);


		for(int i = 0; i < n-1; i++){
			cin >> u >> v;
		}

		int parent[2][n-1];

		for(int i = 0; i < n-1; i++){

		}	

	} 
	

}