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

	int t;

	cin >> t;

	while(t--){

		int n;
		cin >> n;

		int arr[n];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}

		int dp[n][n];

		for(int i = 0; i < n; i++){
			dp[i][i] = 1;
		}
		int max;
		for(int l = 2; l <= n; l++){
			for(int i = 0; i < n; i++){
				int j = (i + l - 1) % n;
				max = 1;
				for(int k = 1; k < l; k++){
					int a = (i + k) % n;
					if(arr[a] > arr[i]){
						
						if(1 + dp[a][j] > max){
							max = 1 + dp[a][j];
						}
					}
				}
				dp[i][j] = max;
			}
		}

		// for(int l = 0; l < n; l++){
		// 	for(int i = 0; i < n; i++){
		// 		cout << dp[l][i] << " ";
		// 	}
		// 	cout << "\n";
		// }
		max = dp[0][n-1];
		for(int i = 1; i < n; i++){
			if(max < dp[i][i-1]){
				max = dp[i][i-1];
			}
		}
		cout << max << "\n";
	}
	
	return 0;
}