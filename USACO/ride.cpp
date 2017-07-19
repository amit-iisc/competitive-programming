/*
ID: amitrao1
LANG: C++
PROG: ride
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

	freopen("ride.in","rt",stdin);
	freopen("ride.out","wt",stdout);

	string camel,group;

	int p_camel = 1,p_group = 1;

	cin >> camel >> group;

	for(int i = 0; i < camel.size(); i++){
		p_camel = (p_camel * (camel[i] - 'A' + 1)) % 47;
	}

	for(int i = 0; i < group.size(); i++){
		p_group = (p_group * (group[i] - 'A' + 1)) % 47;
	}

	if(p_camel == p_group){
		cout << "GO\n";
	}
	else{
		cout<<"STAY\n";
	}
	
	return 0;
}