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

void calculate(int p, int q, std::vector<char> &result){
	if(p >= 0 && q >= 0){
		while(p--){
			result.push_back('R');
		}
		while(q--){
			result.push_back('U');
		}
	}
	else if(p >= 0 && q <= 0){
		q = abs(q);
		while(q--){
			result.push_back('D');
		}
		while(p--){
			result.push_back('R');
		}
	}
	else if(p <= 0 && q <= 0){
		q = abs(q);
		while(q--){
			result.push_back('D');
		}
		p = abs(p);
		while(p--){
			result.push_back('L');
		}
	}
	else{
		p = abs(p);
		while(p--){
			result.push_back('L');
		}
		while(q--){
			result.push_back('U');
		}
	}
}


int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// freopen("B-small-attempt0.in","rt",stdin);
	// freopen("B.out","wt",stdout);

	int n,f_x = 0,f_y = 0,x,y,p,q;

	cin >> n;

	std::vector<char> result;

	for(int i = 0; i < n; i++){

		cin >> x >> y;

		p = x - f_x;
		q = y - f_y;

		calculate(p,q,result);
		
		f_x = x;
		f_y = y;
	}

	p = -f_x;
	q = -f_y;

	calculate(p,q,result);

	for(int i = 0; i < result.size(); i++){
		cout << result[i];
	}
	
	return 0;
}