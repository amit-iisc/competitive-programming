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
#include <climits>

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
        int n,line,updateindex,cost;
        cin >> n;
        
        int arr[n];

        int DP[n+1];
        
        int result[n];
        
        for(int i = 0; i < n; i++){
            cin >>arr[i];
        }
        
        cin >> line;
        
        vector<int> result_vector[n];
        result_vector[0].push_back(0);

        result[0] = 0;

        DP[0] = 0;
        DP[1] = (line - arr[0]) * (line - arr[0]);
        
        for(int i = 1; i < n; i++){
            
            int sum = arr[i];
            updateindex = i;
            int min = DP[i] + (line - arr[i]) * (line - arr[i]);
            int j = i-1;
            while(j >= 0 && sum <= line){
                sum += arr[j] + 1;

                if(sum <= line){
                    cost = DP[j] + (line - sum) * (line - sum);
                    if(cost <= min){
                        min = cost;
                        updateindex = j;
                    }
                }
                j--;
            }
            DP[i+1] = min;
            if(updateindex > 0){
                result_vector[i] = result_vector[updateindex - 1];
            }
            for(int k = updateindex; k <= i; k++){
                result_vector[i].push_back(updateindex);
            }
        }
        
        for(int i = 0; i < n; ){
            cout << i+1 << " ";
            int j = i;
            while(j < n && result_vector[n-1][j] == result_vector[n-1][i]){
                j++;
            }

            cout << j << " ";
            i = j;
        }
        cout << "\n";
    }


}
