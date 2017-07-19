
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



#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)


int perfect_sum(int *arr, int start,int size, int sum){

	if(start == size-1){
		if(arr[start] == sum){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		if(arr[start] > sum){
			return perfect_sum(arr,start + 1,size, sum);
		}
		else if(arr[start] == sum){
			return 1 + perfect_sum(arr,start + 1,size, sum);
		}
		else{
			return perfect_sum(arr,start + 1,size, sum) + perfect_sum(arr,start + 1,size, sum - arr[start]);
		}
	}
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
		int n,sum;

		cin >> n;

		int arr[n];

		//std::vector< std::vector<int > > sum_reuse(n, std::vector<int>(100005));

		for(int i = 0; i < n; i++){

			cin >> arr[i];
		}

		cin >> sum;

		int result = perfect_sum(arr,0,n,sum);

		cout<< result << "\n";
		
	}
	return 0;
	
}