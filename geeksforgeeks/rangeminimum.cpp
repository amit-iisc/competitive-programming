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


int find_min(int *st, int ss,int se, int l,int r,int si){
	if(l > se || r < ss){
		return INT_MAX;
	}

	if(l <= ss && r >= se){
		return st[si];
	}

	int mid = (ss + se)/2;

	return min(find_min(st,ss,mid,l,r,2 * si + 1),find_min(st,mid+1,se,l,r,2 * si + 2));
}

int construct_st(int * arr, int *st, int ss, int se,int si){	
	int mid;

	
	if(ss == se){
		st[si] = arr[ss];
		//cout << ss << " " << se << " " << st[si] << "\n";
	}
	else{
		mid = (ss + se)/2;


		st[si] = min(construct_st(arr,st,ss,mid,2 * si + 1),construct_st(arr,st,mid+1,se,2 * si + 2));
		//cout << ss << " " << se << " " << mid << " " << st[si] << " \n";
	}

	return st[si];
}


int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// freopen("B-small-attempt0.in","rt",stdin);
	// freopen("B.out","wt",stdout);

    int n,qs,qe;

    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }

    int max_size = 2 * pow (2, ceil(log2(n))) - 1;

    int st[max_size];

    construct_st(arr,st,0,n-1,0);

    // for(int i = 0; i < max_size; i++){
    // 	cout << st[i] << " ";
    // }

    cin >> qs >> qe;

    cout << find_min(st,0,n-1,qs,qe,0) << "\n";
	
	return 0;
}