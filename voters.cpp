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

	int n1,n2,n3;
	cin >> n1 >> n2 >> n3;

	int arr1[n1],arr2[n2],arr3[n3];

	vector <int> result;

	for(int i = 0; i < n1; i++){
		cin >> arr1[i];
	}
	for(int i = 0; i < n2; i++){
		cin >> arr2[i];
	}
	for(int i = 0; i < n3; i++){
		cin >> arr3[i];
	}
	int i1 = 0,i2 = 0,i3 = 0,count,lowest;
	lowest = min(arr1[i1],min(arr2[i2],arr3[i3]));

	//cout << lowest << "\n";

	while(i1 < n1 || i2 < n2 || i3 < n3){
		count = 0;

		if(i1 < n1 && arr1[i1] == lowest){
			count++;
			i1++;
		}
		if(i2 < n2 && arr2[i2] == lowest){
			count++;
			i2++;
		}
		if(i3 < n3 && arr3[i3] == lowest){
			count++;
			i3++;
		}

		if(count >= 2){
			result.push_back(lowest);
		}

		if(i1 < n1 && i2 < n2 && i3 < n3){
			lowest = min(arr1[i1],min(arr2[i2],arr3[i3]));
		}
		else if((i1 >= n1 && i2 >= n2) || (i3 >= n3 && i2 >= n2) || (i1 >= n1 && i3 >= n3)){
			break;
		}
		else{
			if(i1 >= n1){
				lowest = min(arr2[i2],arr3[i3]);
			}
			else if(i2 >= n2){
				lowest = min(arr1[i1],arr3[i3]);
			}
			else if(i3 >= n3){
				lowest = min(arr2[i2],arr1[i1]);
			}
		}	

	}


	cout << result.size() << "\n";

	for(int i = 0; i < result.size(); i++){
		cout << result[i] << "\n";
	}


	return 0;
}