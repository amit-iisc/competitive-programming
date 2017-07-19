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
        int n, amount;
        
        cin >> n >> amount;
        
        int arr[n];
        
        for(int i=0; i < n; i++){
            cin >> arr[i];
        }
        int dp[amount + 1];
        dp[0] = 0;
        
        for(int i = 1; i <= amount; i++){
            int min = INT_MAX;
            int temp;
            for(int j = 0; j < n; j++){
                if(i - arr[j] < 0){
                    temp = amount + 1;
                }
                else{
                    temp = 1 + dp[i - arr[j]];
                }
                if(temp < min){
                    min = temp;
                }
            }
            dp[i] = min;
            //cout << dp[i] << " ";
        }
        
        //cout << endl;
        if(dp[amount] > amount){
            cout << "-1\n";
        }
        else{
            cout << dp[amount] << "\n";
        }
    }

    return 0;
}
