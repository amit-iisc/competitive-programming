
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

		int n,m,e,count = 0;

		int *c, *d;

		cin >> n >> m >> e;

		bool edge[n][m];
		bool flag[n];

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				edge[i][j] = false;
			}
			flag[i] = false;
		}

		c = new int[n];
		d = new int[m];

		for(int i = 0; i < n; i++){
			cin >> c[i];
		}

		for(int i = 0; i < m; i++){
			cin >> d[i];
		}

		sort(c,c+n);
		sort(d,d+m);

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(abs(c[i] - d[j]) <= e){
					edge[i][j] = true;
					flag[i] = true;
				}
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
	
				cout<<edge[i][j] << " ";
				
			}
			cout << "\n";
		}

		for(int i = n - 1, j = m - 1; i >= 0; ){
			
			if(flag[i] == true){
				while(edge[i][j] != true && j >= 0){
					j--;	
				}
				if(j >= 0){
					count++;
					cout<< i << " " << j << " " << count << endl;
					j--;
				}
			}
			i--;
		}

		cout << count << endl;

	}

}