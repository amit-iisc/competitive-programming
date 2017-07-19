
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


class array_element
{
public:
  int data;
  int actualIndex;
  bool operator < (const array_element &rhs) const { return data < rhs.data; }
};


int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// freopen("B-small-attempt0.in","rt",stdin);
	// freopen("B.out","wt",stdout);

	int t;

	cin >> t;

	while(t--){

		int n,q;

		array_element temp;
		

		cin >> n >> q;

		int arr[n];

		std::vector<array_element> act_index_vector;

		for(int i = 0; i < n; i++){
			cin >> arr[i];
			temp.data = arr[i];
			temp.actualIndex = i;
			act_index_vector.push_back(temp);
		}

		sort(all(act_index_vector));

		while(q--){
			int a,b,c,d;

			cin >> a >> b >> c >> d;

			int length = b - a + 1,diff = 0,j = 0,k = 0;

			int first[length];
			int second[length];


			for(int i = 0; i < n; i++){
				if(act_index_vector[i].actualIndex >= a-1  && act_index_vector[i].actualIndex < b){
					first[j] = act_index_vector[i].data;
					j++;
				}
				if(act_index_vector[i].actualIndex >= c-1 && act_index_vector[i].actualIndex < d){
					second[k] = act_index_vector[i].data;
					k++;
				}

			}
			
			for(int i = 0; i < length; i++){
				if(first[i] != second[i]){
					diff++;
				}
			}

			if(diff <= 1){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}


		}
	}

	return 0;
	

}