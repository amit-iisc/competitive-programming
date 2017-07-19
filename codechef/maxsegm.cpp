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

	// freopen("B-small-attempt0.in","rt",stdin);
	// freopen("B.out","wt",stdout);

	int t;

	cin >> t;

	while(t--){

		int n,sum = 0,l = 0,r = 0;

		cin >> n;

		int c[n],w[n];

		vector <long long> sum_arr;
		bool is_unique[1000005] = {false};
		int position[n+1];
		long long pos_sum[n];


		for(int i = 0; i < n; i++){
			cin >> c[i];
		} 
		for(int i = 0; i < n; i++){
			cin >> w[i];
		} 

		is_unique[c[0]] = true;
		pos_sum[0] = w[0];
		position[c[0]] = 0;

		for(int i = 1; i < n; i++){

			pos_sum[i] = pos_sum[i-1] + w[i];
			
			if(is_unique[c[i]] == true){
				sum_arr.push_back(pos_sum[r] - pos_sum[l] + w[l]);

				
				l = max(position[c[i]] + 1, l);
			}
			else{
				is_unique[c[i]] = true;
			}

			//cout << i <<" "<<l <<" " << r<<" " <<pos_sum[r] - pos_sum[l] + w[l] << "\n";
			position[c[i]] = i;
			r++;
		}

		sum_arr.push_back(pos_sum[r] - pos_sum[l] + w[l]);

		//cout << sum_arr[sum_arr.size() - 1];

		long long max = *max_element(all(sum_arr));
		cout << max << "\n";
		
	}
	
	return 0;
}