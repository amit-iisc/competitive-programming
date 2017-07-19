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

	int n,i = 0;

	cin >> n;

	int result[4];

	result[0] = result[1] = result[2] = result[3] = 0;
	stack <int> s;

	vector <int> string(n);
	for(int i = 0; i < n; i++){
		cin >> string[i];
	}

	int nest = 0, max_seq = 0,pos = 0;
	while(i < string.size()){
		
		if(string[i] == 1){
			nest++;
			max_seq++;
			s.push(string[i]);
		}
		else{
			s.pop();
			max_seq++;
			if(result[0] < nest){
				result[0] = nest;
				result[1] = i;
			}
			nest--;	
		}

		if(s.empty()){
			if(max_seq > result[2]){
				result[2] = max_seq;
				result[3] = pos + 1;
			}
			max_seq = 0;
			pos = i+1;
		}

		i++;
		
	}

	for(int i = 0; i < 3; i++){
		cout << result[i] << " ";
	}
	cout << result[3];
	
	return 0;
}