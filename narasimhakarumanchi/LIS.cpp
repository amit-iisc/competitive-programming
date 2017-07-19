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
	scanf("%d", &t);
	while(t--){
	    int n;
	    scanf("%d",&n);
	    
	    int *arr = new int[n];
	    int *result = new int[n];
	    for(int i = 0; i < n ; i++){
	        scanf("%d", &arr[i]);
	    }
	    
	    for(int i = 0; i < n ; i++){
	        result[i] = 1;
	    }
	    
	    for(int i = 1; i < n ; i++){
	        for(int j = 0;j < i; j++){
	            if(arr[i] > arr[j] && result[i] <= result[j]){
	                result[i] = 1 + result[j];
	            }
	        }
	    }
	    
	    int max = 0;
	    for(int i = 0; i < n ; i++){
	        if(result[i] > max){
	            max = result[i];
	        }
	    }
	    
	    cout << max << "\n";
	    
	}
	

}
