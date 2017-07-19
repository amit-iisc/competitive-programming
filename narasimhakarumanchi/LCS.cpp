
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



#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)


int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// freopen("B-small-attempt0.in","rt",stdin);
	// freopen("B.out","wt",stdout);

	int t;

	cin >> t;

	while(t--){

		int m,n;

		cin >> m >> n;

	    string s1,s2;

	    cin >> s1 >> s2;

	    //cout << m << " " << n << endl;

	    int LCS[m][n];

	    if(s1[0] == s2[0]){
	    	LCS[0][0] = 1;
	    }
	    else{
	    	LCS[0][0] = 0;
	    }

	    for(int i = 1; i < m; i++){
	    	if(s1[i] == s2[0]){
	    		LCS[i][0] = 1;
	    	}
	    	else{
	    		LCS[i][0] = LCS[i-1][0];
	    	}
	    }

	    for(int i = 1; i < n; i++){
	    	if(s1[0] == s2[i]){
	    		LCS[0][i] = 1;
	    	}
	    	else{
	    		LCS[0][i] = LCS[0][i-1];
	    	}
	    }

	    for(int i = 1; i < m; i++){
	    	for(int j = 1 ; j < n; j++){

	    		if(s1[i] == s2[j]){
	    			LCS[i][j] = LCS[i-1][j-1] + 1;
	    		}
	    		else{
	    			LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
	    		}
	    	}
	    }

	    cout << LCS[m-1][n-1] << "\n";
	}

    return 0;

}