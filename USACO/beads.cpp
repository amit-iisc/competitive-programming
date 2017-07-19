/*
ID: amitrao1
LANG: C++
TASK: beads
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

	freopen("beads.in","rt",stdin);
	freopen("beads.out","wt",stdout);

	int t,pivot,count_l = 0;
	char first,second;

	cin >> t;

	vector <char> str(t);
	vector < int > indexes;

	for(int i = 0; i < t; i++){
		cin >> str[i];
	}

	int i = 0;

	while(str[i] == 'w'){
		i++;
		if(i == str.size()){
			cout << i << "\n";
			return 0;
		}
	}
	first = str[i];
	while(str[i] == first || str[i] == 'w'){
		i++;
		if(i == str.size()){
			cout << i << "\n";
			return 0;
		}
	}

	pivot = i - 1;

	i = pivot;
	while(str[i] == 'w' || str[i] == first){
		count_l++;
		i--;
		if(i == -1){
			i = t-1;
		}
	}


	while(pivot < t){

		int count_r = 0;

		i = pivot + 1;
		if(i == t){
			i = 0;
		}
		second = str[i];
		while(str[i] == 'w' || str[i] == second){
			count_r++;
			i++;
			if(i == t){
				i = 0;
			}
		}
		i = pivot - count_l;
		if(i < 0){
			i += t;
		}
		while(str[i] == 'w'){
			count_l++;
			i--;
			if(i == -1){
				i = t - 1;
			}
		}

		if(count_r + count_l <= str.size()){
			indexes.push_back(count_r + count_l);
		}

		//cout << pivot << " " <<count_r<< " " << count_l << "\n";
		pivot = pivot + count_r;
		count_l = count_r;

		
	}

	//cout << pivot << " " <<count_r + count_l << "\n";

	int max = 0;
	for(i = 0; i < indexes.size(); i++){
		if(indexes[i] > max){
			max = indexes[i];
		}
	}

	cout << max << "\n";
	
	return 0;
}