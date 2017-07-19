
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

		int n,k, k_count, temp, result = 0, temp_size = 0;

		cin >> n >> k;

		vector <int> *entry = new vector <int> [n];
		int *v_size = new int[n];

		for(int i = 0; i < n; i++){

			cin >> k_count;
			v_size[i] = k_count;

			for(int j = 0; j < k_count; j++){
				cin >> temp;
				entry[i].push_back(temp);
			}
		}

		for(int i = 0; i < n; i++){
			sort(all(entry[i]));
		}

		for(int i = 0; i < n - 1; i++){

			for(int j = i+1; j < n; j++){
				temp_size = 0;
				//cout << "running i = " << i << " and j = " << j << endl;
				int k_i = 0,k_j = 0;
				while(k_i < v_size[i] && k_j < v_size[j]){
					if(entry[i][k_i] == entry[j][k_j]){
						k_i++;
						k_j++;
						temp_size++;
					}
					else if(entry[i][k_i] > entry[j][k_j]){
						k_j++;
						temp_size++;
					}
					else if(entry[i][k_i] < entry[j][k_j]){
						k_i++;
						temp_size++;
					}
				}
				//cout << "size 1 = " << temp_size << " k_i = " << k_i << " k_j = " << k_j << " sizes = " << v_size[i] << " and" << v_size[j] <<endl; 
				while(k_i < v_size[i]){
					k_i++;
					temp_size++;
				}
				//cout << "size 2 = " << temp_size << endl;
				while(k_j < v_size[j]){
					k_j++;
					temp_size++;
				}
				//cout << "size 3 = " << temp_size << endl;

				if(temp_size == k){
					result++;
				}
				
			}
		}

		cout << result << "\n";

	}
	

}