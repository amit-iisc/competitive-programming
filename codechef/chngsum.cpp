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


// void updateValue(int *st, int ss, int se,int index,int diff,int si){

// 	if(index > se || index < ss){
// 		return;
// 	}

// 	st[si] += diff;

// 	int mid = (ss + se)/2;

// 	//cout << ss << se << mid << "\n";

// 	if(se != ss){
// 		updateValue(st,ss,mid,index,diff,2*si+1); 
// 		updateValue(st,mid+1,se,index,diff,2*si+2); 
// 	}
// }


int getmin(pair<int,int> *st, int ss,int se, int l, int r, int si){
	if(l <= ss && r >= se){
		return st[si].first;
	}

	if(l > se || r < ss){
		return INT_MAX;
	}

	int mid = (ss + se) / 2;

	//cout << mid << ss << se << "\n";

	return min(getmin(st, ss , mid, l, r, 2 * si + 1) , getmin(st, mid+1, se, l, r, 2 * si + 2));
}

int getmax(pair<int,int> *st, int ss,int se, int l, int r, int si){
	if(l <= ss && r >= se){
		return st[si].second;
	}

	if(l > se || r < ss){
		return INT_MIN;
	}

	int mid = (ss + se) / 2;

	//cout << mid << ss << se << "\n";

	return max(getmax(st, ss , mid, l, r, 2 * si + 1) , getmax(st, mid+1, se, l, r, 2 * si + 2));
}

pair<int,int> constructStUtil(pair<int,int> *st, int ss,int se, int *arr, int si){

	//cout << ss << " " << se << "\n";
	if(ss == se){
		st[si].first = arr[ss];
		st[si].second = arr[ss];
	}
	else{
		int mid = (ss + se) / 2;

		st[si].first = min(constructStUtil(st,ss,mid,arr,2 * si + 1).first , constructStUtil(st,mid + 1,se,arr,2 * si + 2).first);
		st[si].second = max(constructStUtil(st,ss,mid,arr,2 * si + 1).second , constructStUtil(st,mid + 1,se,arr,2 * si + 2).second);
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

	int arr[n],i,j,k,l;
	

	for(i = 0; i < n ; i++){
		cin >> arr[i];
	}

	int min[n],max[n];
	int sum[n];
	int a[n],count[n];

	int last = 0;


	a[0] = arr[0];
	max[0] = arr[0];
	sum[0] = arr[0];
	count[0] = 1;

	int till = 1;

	for(int i =1;i <n;i++){
		till++;

		if(arr[i] <= a[0] && arr[i] >= a[last]){
			int index = binary_search(a,a+last,arr[i]);
			
		}
		else if(arr[i] >a[0]){

		}
		else{

		}

	}



	

	return 0;
}