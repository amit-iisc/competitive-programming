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

int nextbus(int time, int start, int freq){
	
	if(time <= start){
		return start;
	}

	int interval = ceil((time - start) /(float) freq);

	//cout << interval << "here\n";

	return interval * freq + start;
}

int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	freopen("A-small-practice.in","rt",stdin);
	freopen("A-small-practice.out","wt",stdout);

	int t;

	cin >> t;

	for(int ti = 1; ti <= t; ti++){

		long long n,ts,tf;

		cin >> n >> ts >> tf;

		long long s[n+1],f[n+1],d[n+1];

		long long dp[n][n+1];

		for(int i = 1; i < n; i++){
			cin >> s[i] >> f[i] >> d[i];
		} 

		dp[0][1] = 0;

		dp[1][1] = ts;
		

		for(int i = 2;i <= n;i++){
			dp[0][i] = nextbus(dp[0][i-1],s[i-1],f[i-1]) + d[i-1];
			//cout << "0" << " " << i << " " << dp[0][i] << "\n";
		}
		
		for(int i = 1; i < n; i++){
			for(int j = 2; j <= n; j++ ){

				if(j == i){
					dp[i][j] = dp[i-1][j] + ts;

					//cout << i << " " << j << " " << dp[i][j] << "\n";
				}
				else if(j > i){
					dp[i][j] = min(nextbus(dp[i][j-1],s[j-1],f[j-1]) + d[j-1] , dp[i-1][j] + ts);
					//cout << i << " " << j << " " << dp[i][j] << "\n";
				}
			}
		}

		long long result = -1;

		for(int i = 0; i < n; i++){
			// for(int j = 1; j <= n; j++ ){

			// 	cout << dp[i][j] << " ";
			// }
			// cout << endl;
			if(dp[i][n] <= tf){
				if(i > result){
					result = i;
				}
			}
		}
		cout << "Case #"<< ti<<": ";
		if(result == -1){
			cout << "IMPOSSIBLE\n";	
		}
		else{
			cout <<result << "\n";
		}
		
	}
	
	return 0;
}