
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

	int arr[3][100000];

	cin >> t;

	while(t--){

		int p,q,r;

		long long result = 0,sum_x = 0,sum_z = 0,n = 0,m = 0;

		cin >> p >> q >> r;
		

		for(int i = 0; i < p; i++){
			cin >> arr[0][i];
		}
		for(int i = 0; i < q; i++){
			cin >> arr[1][i];
		}
		for(int i = 0; i < r; i++){
			cin >> arr[2][i];
		}

		sort(arr[0], arr[0] + p);
		sort(arr[1], arr[1] + q);
		sort(arr[2], arr[2] + r);

		for(int i = 0; i < q; i++){

			long long val = arr[1][i];

			while(arr[0][n] <= val && n < p){
				
				sum_x += arr[0][n];
				n++;
			}

			while(arr[2][m] <= val && m < r){
				
				sum_z += arr[2][m];
				m++;
			}

			sum_z %= 1000000007;
			sum_x %= 1000000007;
			long long n_val = (n * val) % 1000000007;
			long long m_val = (m * val) % 1000000007;

			result += (n_val * m_val) % 1000000007;
			result = (result + (m_val * sum_x) % 1000000007) % 1000000007;
			result = (result + (sum_x * sum_z) % 1000000007) % 1000000007;
			result = (result + (n_val * sum_z) % 1000000007) % 1000000007;

			//cout << val << " " << result << endl;

		}

		//result  = result % 1000000007;

		cout << result << endl;

	}
	

}