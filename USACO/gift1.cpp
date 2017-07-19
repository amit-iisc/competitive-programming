/*
ID: amitrao1
LANG: C++
PROG: gift1
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

	freopen("gift1.in","rt",stdin);
	freopen("gift1.out","wt",stdout);

	map <string , int > memberId;

	int n,amount,n_taker;
	string memberName;

	cin >>n;

	vector <string> givers;
	int money[n];

	for(int i = 0; i < n; i++){
		money[i] = 0;
	}

	for(int i = 0; i < n; i++){
		cin >> memberName;
		givers.push_back(memberName);
		memberId[memberName] = i;
	}

	for(int i = 0; i < n; i++){
		cin >> memberName;
		cin >> amount >> n_taker;

		int index = memberId[memberName];

		int share,rem;
		if(n_taker == 0){
			share = 0;
			rem = amount;
		}
		else{
			share = amount / n_taker;
			rem = amount - (n_taker * share);
		}

		money[index] = money[index] - amount + rem;

		for(int j = 0;j < n_taker; j++){
			cin >> memberName;
			money[memberId[memberName]] += share;
		}

		
	}

	for(int k = 0; k < n; k++){
		cout << givers[k] << " " << money[k] << "\n";
	}
	
	return 0;
}