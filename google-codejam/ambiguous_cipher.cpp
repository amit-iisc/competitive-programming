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

	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);

	int t;

	cin >> t;

	for(int k = 1; k <= t ; k++){

		string w;

		cin >> w;

		int n = w.size();

		vector <int> original(n);
		vector <int> result(n);

		for(int i = 0; i < n; i++){
			original[i] = w[i] - 'A';
		}

		result[1] = original[0];
		result[n - 2] = original[n-1];

		for(int i = 1; i < n-2; i = i+2){

			int temp;
			if(original[i+1] >= result[i]){
				temp = original[i+1] - result[i];
			}
			else{
				temp = (original[i+1] + 26) - result[i];
			}

			result[i+2]  = temp;
		}

		for(int i = n - 4; i >= 0; i = i - 2){
			int temp;
			if(original[i+1] >= result[i+2]){
				temp = original[i+1] - result[i + 2];
			}
			else{
				temp = (original[i+1] + 26) - result[i+2];
			}
		
			result[i]  = temp;
		}

		if(n%2 != 0){
			cout << "Case #"<< k<<": ";
			cout << "AMBIGUOUS\n" ;
		}
		else{
			cout << "Case #"<< k<<": ";
			for(int i = 0; i < n; i++){
				char ch = 65 + result[i];

				cout << ch ;
			}
			cout << "\n";
		}
		
	}
	
	return 0;
}