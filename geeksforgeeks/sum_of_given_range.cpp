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


void updateValue(int *st, int ss, int se,int index,int diff,int si){

	if(index > se || index < ss){
		return;
	}

	st[si] += diff;

	int mid = (ss + se)/2;

	//cout << ss << se << mid << "\n";

	if(se != ss){
		updateValue(st,ss,mid,index,diff,2*si+1); 
		updateValue(st,mid+1,se,index,diff,2*si+2); 
	}
}


int getSum(int *st, int ss,int se, int l, int r, int si){
	if(l <= ss && r >= se){
		return st[si];
	}

	if(l > se || r < ss){
		return 0;
	}

	int mid = (ss + se) / 2;

	//cout << mid << ss << se << "\n";

	return getSum(st, ss , mid, l, r, 2 * si + 1) + getSum(st, mid+1, se, l, r, 2 * si + 2);
}

int constructStUtil(int *st, int ss,int se, int *arr, int si){

	//cout << ss << " " << se << "\n";
	if(ss == se){
		st[si] = arr[ss];
	}
	else{
		int mid = (ss + se) / 2;

		st[si] = constructStUtil(st,ss,mid,arr,2 * si + 1) + constructStUtil(st,mid + 1,se,arr,2 * si + 2);
	}

	return st[si];
}


int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// freopen("B-small-attempt0.in","rt",stdin);
	// freopen("B.out","wt",stdout);

	int n,querystart,queryend,newvalue,index;

	cin >> n;

	int arr[n];
	

	for(int i = 0; i < n ; i++){
		cin >> arr[i];
	}

	int max_size = 2 * pow(2, ceil(log2(n))) - 1;

	int st[max_size];

	constructStUtil(st,0,n-1,arr,0);

	for(int i = 0; i < max_size; i++){
		cout << st[i] << " ";
	}

	// cin >> querystart >> queryend;

	// cout << getSum(st, 0, n-1, querystart, queryend, 0) << "\n";

	cin >> index >> newvalue;

	int diff = newvalue - arr[index];

	arr[index] = newvalue;

	updateValue(st,0,n-1,index,diff,0);

	for(int i = 0; i < max_size; i++){
		cout << st[i] << " ";
	}

	return 0;
}