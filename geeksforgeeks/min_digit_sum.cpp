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
        int n,sum;
        
        cin >> n >> sum;
        int dp[n+1][sum+1];
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                dp[i][j] = 0;
            }
        }
        for(int i = 1; i < 10; i++){
            dp[1][i] = 1;
        }
        
        for(int i = 2; i <= n; i++ ){
            for(int j = 0; j <= sum; j++){
                int tmp_sum = 0;
                for(int k = 0; k < 10; k++){
                    int temp;
                    if(j - k < 0){
                        temp = 0;   
                    }
                    else{
                        temp = dp[i-1][j - k];
                    }
                    tmp_sum = (tmp_sum + temp) % 1000000007;
                }
                dp[i][j] = tmp_sum;
            }
        }

        if(dp[n][sum] == 0){
            cout << "-1\n";
        }
        else{
            cout << dp[n][sum] << "\n";
        }
    }

    return 0;
}
