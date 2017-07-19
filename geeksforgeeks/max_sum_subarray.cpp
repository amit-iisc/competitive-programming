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
	    int n,k;
	    cin >> n;
	    
	    int arr[n];
	    int sum = 0, max = INT_MIN,fullsum = 0;
	    
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }

	    cin >> k;

	    for(int i = 0; i < k-1; i++ ){
	        sum += arr[i];
	    }

	    fullsum = sum;
	    for(int i = k-1; i < n; i++ ){
	        fullsum += arr[i];
	        if(fullsum > max){
	            max = fullsum;
	            //cout << max << " ";
	        }
	    }
	    for(int i = 1; i <= n - k; i++){
	        sum = sum - arr[i-1] + arr[i+k-2];
	        fullsum = sum;
	        for(int j = k - 1 + i; j < n; j++){
	            fullsum += arr[j];
    	        if(fullsum > max){
    	            max = fullsum;
    	            //cout << max << " ";

    	        }
	        }
	    }
	    cout << max <<endl;
	    
	}

}
