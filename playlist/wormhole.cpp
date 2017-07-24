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


int bin_search(std::vector<int> *v, int k){
	
	int l = 0,mid;
	int h = v->size();

	while(l < h){
		mid = (l + h) / 2;

		if(v->at(mid) == k){
			return mid;
		}
		else if(v->at(mid) < k){
			l = mid + 1;
		}
		else{
			h = mid;
		}
	}

	return l;
}


int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// freopen("B-small-attempt0.in","rt",stdin);
	// freopen("B.out","wt",stdout);


	// int myints[] = {10,20,30,40,50,60,70,80};
 //  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

 //  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

 //  int low,up;
 //  low=bin_search (v, 90); //          ^
 //  //up= std::upper_bound (v.begin(), v.end(), 30) - v.begin(); //                   ^

 //  std::cout << " at position " << low << '\n';
 //  //std::cout << "upper_bound at position " << up << '\n';

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
		
		int start = -1;
		while(v[j] <= contests[i].first && j < x){
			j++;
		}
		
		if(j != 0){
			start = --j;
		}

		int end = bin_search(&w,contests[i].second);

		//cout << start << " " << end << "\n";

		if(start != -1 && end < y){

			if(w[end] - v[start] < min){
				min = w[end] - v[start];
			}
		}
		//cout << min << "\n";
	}

	cout << min + 1;
	
	return 0;
}