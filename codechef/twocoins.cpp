/*
ID: amitrao1
LANG: C++
PROG: test
*/


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
#include <climits>
#include <complex>

using namespace std;



#define rep(i,n) for (int i = 0; i < (int) n; ++i)
#define rep2(i,k,n) for (int i = k; i <= (int) n; ++i)
#define rep3(i,k,n) for (int i = k; i >= (int) n; --i)

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector< vector<int> > vii;

void dfsUtil(int parent,int node,bool *visited,bool *coin, bool *demand, std::vector<int> *adjList){

	//cout << "processing " << node <<" parent " << parent << "\n";
	visited[node] = true;
	int count = 0;

	if(adjList[node].size() == 1){
		//cout << "it was a leaf\n";
		coin[node] = true;
		//cout << "coin " << node << " set to 1" <<"\n";
		demand[parent] = true;
		//cout << "demand " << parent << " set to 1" <<"\n";
		return;
	}

	//cout << "it was not a leaf\n";
	For(it,adjList[node]){
		
		if(visited[*it] == false){
			//cout << "processing " << node <<" children\n";
			dfsUtil(node,*it,visited,coin,demand,adjList);
			if(coin[*it] == true){
				count++;
			}
		}
	}

	if(coin[node] == true){
		return;
	}
	

	if(count == 0){
		coin[node] = true;
		//cout << "coin " << node << " set to 1" <<"\n";
	}

	else if(count == 1 || demand[node] == true){
		coin[parent] = true;
		//cout << "coin " << parent << " set to 1" <<"\n";
	}
	

}

void dfs(int root, bool *visited, bool *coin, bool *demand, std::vector<int> *adjList){

	visited[root] = true;

	For(it,adjList[root]){
		dfsUtil(root,*it,visited,coin,demand,adjList);
	}

	if(demand[root] == true){
		coin[root] = true;
	}
	else{
		int count = 0;
		For(it,adjList[root]){
			if(coin[*it] == true){
				count++;
			}
		}
		if(count < 2){
			coin[root] = true;
		}
	}

}

int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	//freopen("B.out","rt",stdin);
	//freopen("B1.out","wt",stdout);

	int t;

	cin >> t;

	while(t--){

		int n,u,v,result = 0;

		cin >> n;

		bool demand[n+1], coin[n+1];
		std::vector<int> adjList[n+1];

		bool visited[n+1];

		for(int i = 0; i <= n; i++){
			visited[i] = false;
			demand[i] = false;
			coin[i] = false;
		}

		
		for(int i = 0; i < n-1; i++){
			cin >> u >> v;
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}

		dfs(1,visited,coin,demand,adjList);

		for(int i = 1; i <= n; i++){
			if(coin[i] == true){
				result++;
			}
		}

		if(n == 1){
			result = -1;
		}
		
		cout << result << "\n";
	}
	
	return 0;
}