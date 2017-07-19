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


class AbstractGraph
{
	
public:
 
    virtual void addEdge(int v, int w) = 0;
    virtual void printGraph() = 0;
    virtual void BFS_Traversal(int s) = 0;
    virtual void DFS_Traversal(int s) = 0;

};

class Graph : public AbstractGraph
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

class DirectedGraph : public Graph
{

};

class UndirectedGraph : public Graph
{

};
 
 
Graph::Graph(int v)
{
    this->V = v;
    adjList = new vector<int> [v];
}
 
void DirectedGraph::addEdge(int v, int w)
{
    adjList[v].push_back(w);
}

void UndirectedGraph::addEdge(int v, int w)
{
    adjList[v].push_back(w);
    adjList[w].push_back(v);
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

	Graph g(5);

	g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

	g.printGraph();
	cout << "\n";
	g.BFS_Traversal(2);
	cout << "\n";
	g.DFS_Traversal(2);
	
	return 0;	

}