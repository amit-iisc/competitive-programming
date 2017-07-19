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
    
    int arr[105];
    
    for(int i = 0; i < 105; i++){
        arr[i] = i*i;
    }
    
    while(t--){
        
        int n,min;
        
        cin >> n;
        
        int result[n+1];
        result[0] = 0;
        result[1] = 1;
        
        for(int i = 2; i <= n; i++){
            min = result[i-1] + 1;
            
            for(int j = 2; j*j <= i; j++){
                int temp = result[i - arr[j]] + 1;
                if(temp < min){
                    min = temp;
                }
            }
            result[i] = min;
            //cout<< result[i] << " ";
        }
        
        cout << result[n] <<"\n";
    }
    return 0;

}
