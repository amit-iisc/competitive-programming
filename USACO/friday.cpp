/*
ID: amitrao1
LANG: C++
PROG: friday
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

	freopen("friday.in","rt",stdin);
	freopen("friday.out","wt",stdout);

	int n,initial = 0;

	int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int days[7] = {0};

	cin >> n;

	for(int i = 0; i < n; i++){
		int year = 1900 + i;
		bool leap = false;
		if(year % 100 == 0){
			if(year % 400 == 0){
				leap = true;
			}
		}
		else{
			if(year % 4 == 0){
				leap = true;
			}
		}
		if(leap == true){
			month[1] = 29;
		}
		else{
			month[1] = 28;
		}

		for(int j = 0; j < 12; j++){
			days[initial]++;
			//cout << initial << "\n";
			initial = (initial + month[j]) % 7;

		}
	}

	for(int i = 0; i < 6; i++){
		cout << days[i] <<" ";
	}
	cout << days[6]<< "\n";
	
	return 0;
}