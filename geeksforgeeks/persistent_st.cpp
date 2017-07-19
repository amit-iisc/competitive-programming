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

class st_node{

public:
	int value;
	st_node *left;
	st_node *right;

	st_node(){}

	st_node(st_node *l,st_node *r, int val){
		value = val;
		left = l;
		right = r;
	}

	void build_st(int *arr,int low,int high){

		if(low == high){
			value = arr[low];
			return;
		}

		int mid = (low + high) / 2;
		this->left = new st_node(NULL,NULL,0);
		this->right = new st_node(NULL,NULL,0);
		this->left->build_st(arr,low,mid);
		this->right->build_st(arr,mid+1,high);
		this->value = this->left->value + this->right->value;
	}

	void upgrade(st_node *prev,int low,int high,int index,int newval){
		
		if(index > high || index < low || high < low){
			return;
		}

		if(low == high){
			this->value = newval;
			return;
		}

		int mid = (low + high) / 2;

		if(index > mid){
			this->left = prev->left;
			this->right = new st_node(NULL,NULL,0);
			this->right->upgrade(prev->right,mid+1,high,index,newval);
		}
		else{
			this->left = new st_node(NULL,NULL,0);
			this->right = prev->right;
			this->left->upgrade(prev->left,low,mid,index,newval);
		}
		this->value = this->left->value + this->right->value;

	}

	int query(int low,int high,int l,int r){
		if(r < low || l > high || low > high){
			return 0;
		}
		if(l <= low && r >= high){
			return this->value;
		}

		int mid = (low + high) / 2;
		int p1 = this->left->query(low,mid,l,r);
		int p2 = this->right->query(mid+1,high,l,r);
		return p1 + p2;
	}
};


int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// freopen("B-small-attempt0.in","rt",stdin);
	// freopen("B.out","wt",stdout);

	int n;

	cin >> n;

	int arr[n];

	st_node *version[n];

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	st_node *root = new st_node(NULL,NULL,0);
	root->build_st(arr,0,n-1);

	version[0] = root;
	version[1] = new st_node(NULL,NULL,0);

	version[1]->upgrade(root,0,n-1,2,10);

	cout << version[0]->query(0,n-1,1,3) << " ";
	cout << version[1]->query(0,n-1,1,3)<< "\n";

	
	
	return 0;
}