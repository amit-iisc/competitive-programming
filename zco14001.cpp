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

	int n,h,command,position = 0;
	bool hasbox = false;

	cin >> n >> h;

	int arr[n];

	for(int i = 0; i < n;i++){
		cin >> arr[i];
	}

	cin >> command;

	while(command != 0){

		if(command == 1){
			if(position){
				position--;
			}
		}
		else if(command == 2){
			if(position != n-1){
				position++;
			}
		}
		else if(command == 3){
			if(!hasbox){
				if(arr[position] != 0){
					hasbox = true;
					arr[position]--;
				}
			}
		}
		else if(command == 4){
			if(hasbox){
				if(arr[position] != h){
					arr[position]++;
					hasbox = false;
				}
			}
		}
		cin >> command ;
	}
	
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}

	cout << "\n";
	return 0;
}