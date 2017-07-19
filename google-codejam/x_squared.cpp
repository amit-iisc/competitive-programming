/*
ID: amitrao1
LANG: C++
PROG: test
*/


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

	freopen("B-large.in","rt",stdin);
	freopen("B-large.out","wt",stdout);

	int t;

	cin >> t;

	for(int k = 1; k <= t;k ++){

		int n;
		bool flag = true;

		cin >> n;

		char grid[n][n];
		vector <pair<int,int> > rowpair;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}

		for(int i = 0; i < n; i++){
			rowpair.clear();
			for(int j = 0; j < n; j++){
				if(grid[i][j] == 'X'){
					rowpair.push_back(make_pair(i,j));
				}
			}

			if((int)rowpair.size() > 2 || (int)rowpair.size() <= 0){
				flag = false;
				break;
			}
			else{
				if((int)rowpair.size() == 1){
					int count = 0;
					for(int k = 0; k < n; k++){
						if(grid[k][rowpair[0].second] == 'X'){
							count++;
						}
					}
					if(count != 1){
						flag = false;
						break;
					}
				}
				else{
					vector<int> index_k;
					For(it,rowpair){
						int index_i = (*it).first;
						int index_j = (*it).second;
						for(int k = 0; k < n; k++){
							if(grid[k][index_j] == 'X'){
								if(k != index_i){
									index_k.push_back(k);
								}
							}
						}
					}
					if(index_k[0] != index_k[1]){
						flag = false;
						break;
					}
				}
			}

		}
		cout << "Case #"<< k<<": ";
		if(flag){
			cout<< "POSSIBLE\n";
		}
		else{
			cout<< "IMPOSSIBLE\n";
		}

	}
	
	return 0;
}