
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
#include <complex>

using namespace std;



#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)


int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// freopen("B-small-attempt0.in","rt",stdin);
	// freopen("B.out","wt",stdout);

	int t;

	cin >> t;

	while(t--){

		int n;

		cin >> n;

		pair <int , int> round[n];

		for(int i = 0; i < n-1; i++){
			round[i] = make_pair(i+1,i+2);
		}

		round[n-1] = make_pair(1,n);

		cout << n <<"\n";

		for(int i = 0; i < n; i++){
			cout << n << "\n";
			for(int j = 0; j < n; j++){
				int index = (i + j) % n;
				cout << j+1 << " " << round[index].first << " " << round[index].second <<"\n";
			}
		}

		
	}
	
	return 0;
}