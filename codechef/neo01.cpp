
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

	//freopen("B.out","rt",stdin);
	// freopen("B.out","wt",stdout);

	int t;

	cin >> t;

	while(t--){

		int n, curr_count = 0, i = 0;

		long long sum = 0,result = 0;

		cin >> n;

		int *happ = new int [n];

		for(i = 0; i < n; i++){

			cin >> happ[i];
		}

		sort(happ,happ+n, greater <int> ());

		for(i = 0; i < n && happ[i] >= 0; i++){

				sum = sum + happ[i];
				curr_count++;
		}

		while(i < n){
			long long sum1 = sum + happ[i];
			int curr_count1 = curr_count + 1;

			if(sum * curr_count <= sum1 * curr_count1){
				sum = sum1;
				curr_count = curr_count1;
			}
			else{
				break;
			}
			i++;
		}

		result = sum * curr_count;

		while(i < n){
			result += happ[i];
			i++;
		}

		printf("%lld \n",result);

	}
	

}