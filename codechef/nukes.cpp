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


int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// freopen("B-small-attempt0.in","rt",stdin);
	// freopen("B.out","wt",stdout);



	int a,n,k;

	cin >> a >> n >> k;

	int count[k+1],bound = 1,c = 0;
	
	for(int i = 0; i < k ; i++){
		count[i] = 0;

	}

	while(a > bound && c < k){
		bound *= (n+1);
		c++;
	}
	if(c == k){
		count[k-1] = n;
		bound /= (n+1);
		c = k-1;
	}
	while(a > bound){
		a -= bound;
	}
	int i = c;
	while(a > 0){

		while(i >= 0 && a < bound){
			i--;
			bound /= (n+1);
		}


		while(a >= bound){
			a = a - bound;
			count[i]++;
		}
		if(count[i] > n){
			count[i] = n;
		}	

	}

	for(int i = 0; i < k ; i++){
		cout <<count[i] << " ";
	}
	cout << "\n";
		
	
	
	return 0;
}