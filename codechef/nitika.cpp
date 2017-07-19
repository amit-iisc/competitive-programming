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
	string str;

	cin >> t;

	getline(cin,str);

	while(t--){

		vector <string> name;
		string words;

		getline(cin,str);

		stringstream ss(str);

		while(ss >> words){

			name.push_back(words);
			
		}

		if(name[name.size() - 1][0] > 96){
			name[name.size() - 1][0] -= 32; 
		}
		for(int k = 1; k < name[name.size() - 1].length();k++){
			if(name[name.size() - 1][k] < 96){
				name[name.size() - 1][k] += 32; 
			}
			
		}

		for(int i = 0; i < name.size() - 1 ; i++){
			if(name[i][0] > 96){
				name[i][0] -= 32;
			}
			cout << name[i][0] << ". ";
		}

		cout << name[name.size() - 1].c_str() << "\n";

	}
	
	return 0;
}