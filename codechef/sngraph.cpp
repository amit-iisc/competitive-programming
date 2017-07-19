
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

    list<int> *adj;
 
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);   
    void addEdge(int v, int w);
    int connectedComponents();
    int list_size(int i);
};
 

int Graph::connectedComponents()
{
    int count = 0;
    bool *visited = new bool[V];
    for(int v = 0; v < V; v++)
        visited[v] = false;
 
    for (int v=0; v<V; v++)
    {
        if (visited[v] == false)
        {
  			count++;   
            DFSUtil(v, visited);
        }
    }
    return count;
}

int Graph::list_size(int i)
{
    return adj[i].size();
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    
    visited[v] = true;
 
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}


int main(){

	// fast I/O
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

	// freopen("B-small-attempt0.in","rt",stdin);
	// freopen("B.out","wt",stdout);

	int t;
	cin >> t;

	while(t--){

		int n,m,u,v;

		cin >> n >> m;

		int *deg = new int[n];
		int *res = new int[n];

		Graph g(n);

		for(int i = 0; i < m; i++){

			cin >> u >> v;
			g.addEdge(u, v);
		} 

		for(int i = 0; i < n; i++){

			deg[i] = g.list_size(i);
		}

		for(int i = 0; i < n; i++){

			cout << deg[i] << " ";
		}

	}
	

}