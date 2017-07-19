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

	freopen("C-small-attempt1.in","rt",stdin);
	freopen("B-large.out","wt",stdout);

	int t;

	cin >> t;

	for(int k = 1; k <= t;k ++){

		int n,q,matched = 0,unmatched;

		cin >> n >> q;

		int score;

		string answers;

		string myanswer;

		
		cin >> answers;
		
		cin >> myanswer;

		cin >> score;

		for(int i = 0; i < q; i++){
			if(answers[i] == myanswer[i]){
				matched++;
			}
		}

		unmatched = q - matched;

		int result;
		if(score <= matched){
			result = score + unmatched;
		}
		else{
			result = unmatched - score + matched;
		}

		cout << "Case #"<< k<<": " << result << "\n";
	}
	
	return 0;
}