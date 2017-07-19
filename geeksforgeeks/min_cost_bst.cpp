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
#include <climits>
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


int sum(int *freq,int left,int right){
    
    int sum = 0;
    for(int i = left; i <= right; i++){
    	sum += freq[i]; 
    }
    return sum;
}


int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// freopen("B-small-attempt0.in","rt",stdin);
	// freopen("B.out","wt",stdout);
	
	int t;
	
	cin >> t;
	
	while(t--){

	    int n,leftcost,rightcost,c;
	    
	    cin >> n;
	    int *keys = new int[n];
	    int *freq = new int[n];

	    int cost[n][n];
	    
	    for(int i = 0 ;i < n; i++){
	        cin >> keys[i];
	    }
	    
	    for(int i = 0 ;i < n; i++){
	        cin >> freq[i];
	    }

	    for(int i = 0 ;i < n; i++){
	        cost[i][i] = freq[i];
	    }

	    for(int L = 2; L <= n ; L++){
	    	for(int i = 0; i < n-L+1 ; i++){
	    		int j = i + L - 1;
	    		cost[i][j] = INT_MAX;

	    		for(int r = i; r <= j; r++){

	    			leftcost = (i > r - 1) ? 0 : cost[i][r-1];
	    			rightcost = (j < r + 1) ? 0 : cost[r+1][j];

	    			c = leftcost + rightcost + sum(freq,i,j);

	    			if(c < cost[i][j]){
	    				cost[i][j] = c;
	    			}

	    		}

	    	}
	    }
	   // for(int i = 0 ;i < n; i++){
	   //      for(int j = 0; j < n; j++){
	   //      	cout << cost[i][j] << " ";
	   //      }
	   //      cout << "\n";
	   //  }
	    
	    cout << cost[0][n-1] << endl;
	    
	}

}
