
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

		int n,b;

		cin >> n >> b;

		if(n == 2){
			if(b == 1){
				cout << "YES\n";
				cout << "1 2\n";
			}
			else {
				cout<< "NO\n";
			} 
		}

		else if(2*b > n/2){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";

			for(int i = 2*b+2 ; i <= n; i++){
				cout << "1 " << i << "\n";
			}

			for(int i = 1; i <= 2*b; i++){
				cout << i << " "<< i+1 <<"\n";
			}
	
		}
		
	}	

}