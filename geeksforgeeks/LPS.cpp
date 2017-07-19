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
	    
	    string str;
	    cin >> str;
	    
	    int n = str.size();
	    int LPS[n][n];
	    
	    for(int i = 0; i < n; i++){
	        LPS[i][i] = 1;
	    }
	    
	    for(int l = 2; l <= n; l++){
	        for(int i = 0; i <= n - l; i++){
	            int j = i + l - 1;
	            
	            if(str[i] == str[j]){
	                if(i+1 <= j-1){
	                    LPS[i][j] = 2 + LPS[i+1][j-1];
	                }
	                else{
	                    LPS[i][j] = 2;
	                }
	            }
	            else{
	                LPS[i][j] = max(LPS[i+1][j],LPS[i][j-1]);
	            }
	        }
	    }
	    cout << LPS[0][n-1]<< "\n";
	}
    return 0;	

}
