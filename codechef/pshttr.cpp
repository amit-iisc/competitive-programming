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

#define MAX 1000000000

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector< vector<int> > vii;

class segTreeNode{
public:
	int val;

	segTreeNode *left;
	segTreeNode *right;

	segTreeNode(){}

	segTreeNode(segTreeNode *l,segTreeNode *r,int v){
		this->left = l;
		this->right = r;
		this->val = v;
	}

	void buildTree(int low,int high){
		if(low == high){
			this->val = 0;
			return;
		}
		int mid = (low + high) / 2;
		this->left = new segTreeNode(NULL,NULL,0);
		this->right = new segTreeNode(NULL,NULL,0);
		this->left->buildTree(low,mid);
		this->right->buildTree(mid+1,high);

		this->val = this->left->val ^ this->right->val;
	}

	void upgrade(segTreeNode *prev,int low,int high,int idx,int newval){

		if(idx < low || idx > high || low > high){
			return;
		}

		//cout << "Inside";
		if(prev == NULL){
			if(low == high){
				this->val = newval;
				return;
			}

			int mid = (low + high) / 2;

			if(idx <= mid){
				this->left = new segTreeNode(NULL,NULL,0);
				this->right = NULL;
				this->left->upgrade(NULL,low,mid,idx,newval);
				
			}
			else{
				this->right = new segTreeNode(NULL,NULL,0);
				this->left = NULL;
				this->right->upgrade(NULL,mid+1,high,idx,newval);
			}

			this->val = newval;
		}
		else{
			if(low == high){
				this->val = prev->val ^ newval;
				return;
			}

			int mid = (low + high) / 2;
			

			if(idx <= mid){
				this->left = new segTreeNode(NULL,NULL,0);
				this->right = prev->right;
				this->left->upgrade(prev->left,low,mid,idx,newval);

			}
			else{
				this->right = new segTreeNode(NULL,NULL,0);
				this->left = prev->left;
				this->right->upgrade(prev->right,mid+1,high,idx,newval);
			}

			int p1 = 0,p2 = 0;
			if(this->left != NULL){
				p1 = this->left->val;
			}

			if(this->right != NULL){
				p2 = this->right->val;
			}
	
			this->val = p1 ^ p2; 
		}

	}

	int query(int low,int high,int num){
		if(num < low || low > high){
			return 0;
		}

		if(num > high){
			return this->val;
		}

		int mid = (low + high) / 2;
		if(num == mid){
			if(this->left != NULL){
				return this->left->val;
			}
		}
		else if(num < mid){
			if(this->left != NULL){
				return this->left->query(low,mid,num);
			}
		}
		else{
			int p1 = 0,p2 = 0;
			if(this->left != NULL){
				p1 = this->left->val;
			}
			if(this->right != NULL){
				p2 =  this->right->query(mid+1,high,num);
			}

			return p1 ^ p2;
		}
		return 0;
	}
};


int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// freopen("B-small-attempt0.in","rt",stdin);
	//freopen("B.out","wt",stdout);

	int t;

	cin >> t;

	while(t--){

		int n,u,v,c;

		int srcnode = 1;

		cin >> n;


		map < pair <int,int> , int > cost;
		std::vector<int> adjList[n+1];

		for(int i = 0; i < n-1; i++){
			cin >> u >> v >> c;

			adjList[u].push_back(v);
			adjList[v].push_back(u);

			cost[make_pair(u,v)] = c;
			cost[make_pair(v,u)] = c;
		}

		bool visited[n+1];

		for(int i = 0; i <= n; i++){
			visited[i] = false;
		}

		segTreeNode *node[n+1];

		node[srcnode] = new segTreeNode(NULL,NULL,0);

		stack <int> dfs;
		dfs.push(srcnode);

		visited[srcnode] = true;

		while(!dfs.empty()){

			srcnode = dfs.top();
			dfs.pop();

			For(it,adjList[srcnode]){
				//cout << "here";
				if(!visited[*it]){
					visited[*it] = true;
					dfs.push(*it);

					int edgecost = cost[make_pair(srcnode,*it)];
					node[*it] = new segTreeNode(NULL,NULL,0);
					node[*it]->upgrade(node[srcnode],1,MAX,edgecost,edgecost);
				}
			}
		}

		// for(int i = 1; i <= n;i++ ){
		// 	cout << node[i]->val << " ";
		// }

		int nq,k;
		cin >> nq;

		for(int i = 0; i < nq; i++){
			cin >> u >> v >> k;

			int p = node[u]->query(1,MAX,k);
			int q = node[v]->query(1,MAX,k);

			cout << (p ^ q) << "\n";
		}


	}
	
	return 0;
}