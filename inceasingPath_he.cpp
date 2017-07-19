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

#define M 1000000007

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector< vector<int> > vii;





void moduloinverse(long long a, long long b, long long& x, long long& y)
{
    if(a % b == 0)
    {
        x = 0;
        y = 1;
        return;
    }
    moduloinverse(b,a%b,x,y);
   
    long long temp = x;
    x = y;
    y = temp - y * (a / b);
}

long long inverse(long long a, long long p)
{
    long long x,y;

    moduloinverse(a,p,x,y);

    if(x<0){
    	x += p;
    }

    return x;
}


void dfsUtil(int node,bool *visited, int *arr,vector <int> *adjList){

	visited[node] = true;

	if(adjList[node].size() == 1){
		return;
	}

	For(it,adjList[node]){
		if(!visited[*it]){
			dfsUtil(*it,visited,arr,adjList);
			arr[node] += arr[*it];
		}
	}
}

void dfs(int root,bool *visited, int *arr,vector <int> *adjList){

	visited[root] = true;

	For(it,adjList[root]){
		dfsUtil(*it,visited,arr,adjList);
	}
}

int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// freopen("B-small-attempt0.in","rt",stdin);
	// freopen("B.out","wt",stdout);

	int n,u,v;
	long long result_denom = 1, result_num = 1;

	cin >> n;

	int arr[n+1];
	bool visited[n+1];
	vector <int> adjList[n+1];

	for(int i = 0; i <= n; i++){
		arr[i] = 1;
		visited[i] = 0;
	}

	for(int i = 1; i < n; i++){
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	dfs(1,visited,arr,adjList);	

	for(int i = 2; i <= n; i++){
		result_num = (result_num * (i % M)) % M;
		result_denom = (result_denom * (arr[i] % M)) % M;
	}

	result_num /= n;

	long long result = (result_num * inverse(result_denom, M)) % M ;

	cout << result_num << " " << result_denom << " " << result; 
	
	return 0;
}