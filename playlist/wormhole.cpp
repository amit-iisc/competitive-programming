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


// int search_w(std::vector<int> v, int k){
// 	int low = 0,high = v.size() - 1;

// 	if(v[high] < k){
// 		return -1;
// 	}

// 	if(k <= v[low]){
// 		return v[low];
// 	}

// 	int mid	= (low + high) / 2;

// 	while(mid > low){
// 		if(v[mid] >= k){
// 			high = mid;
// 		}
// 		else{
// 			low = mid;
// 		}

// 		mid	= (low + high) / 2;
// 	}
// 	if(v[mid] >= k){
// 		return v[mid];
// 	}
// 	else{
// 		if(mid + 1 < v.size()){
// 			return v[mid+1];
// 		}
// 		else{
// 			return -1;
// 		}
// 	}
// }


int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// freopen("B-small-attempt0.in","rt",stdin);
	// freopen("B.out","wt",stdout);

	int n,x,y,p,q;

	cin >> n >> x >> y;

	vector<pair <int,int> > contests(n);
	std::vector<int> v(x);
	std::vector<int> w(y);	

	for(int i = 0; i < n;i++){
		cin >> p >> q;
		contests[i] = make_pair(p,q);
	}

	for(int i = 0; i < x;i++){
		cin >> v[i];
	}
	for(int i = 0; i < y;i++){
		cin >> w[i];
	}

	sort(all(contests));
	sort(all(v));
	sort(all(w));

	int min = INT_MAX;

	int j = 0; 
	for(int i = 0; i < n; i++){
		
		while(v[j] <= contests[i].first && j < x){
			j++;
		}
		int start = -1;
		if(j != 0){
			start = --j;
		}

		int end = upper_bound(all(w),contests[i].second) - w.begin();

		if(end >= y){
			if(w[y-1] >= contests[i].second){
				end = y-1;
			}
			else{
				end = -1;
			}
		}

		//cout << start << " " << end << "\n";

		if(start != -1 && end != -1){

			if(w[end] - v[start] < min){
				min = w[end] - v[start];
			}
		}
		//cout << min << "\n";
	}

	cout << min + 1;
	
	return 0;
}