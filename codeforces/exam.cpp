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

	bool good[27];

	for(int i =1 ;i <= 26; i++){
		good[i] = false;
	}

	string goodstr;

	cin >> goodstr;

	for(int i =0 ;i < str.length(); i++){
		good[str[i] - 96] = true;
	}

	string pattern;

	cin >> pattern;

	int nq;

	cin >>nq;

	while(nq--){
		string tomatch;

		cin >> tomatch;

		std::vector<char> left,right;

		int i = 0;

		while(pattern[i] != *){
			left.push_back(pattern[i]);
			i++;
		}

		i = pattern.length() - 1;
		
		while(pattern[i] != *){
			right.push_back(pattern[i]);
			i--;
		}
		
		if(left.size() + right.size() < pattern.length() - 1){
			cout<< "NO\n";
		}
		
		if(left.size() == 0){
			int j = right.size() - 1;
			int k = tomatch.length() - 1;
			while(k >= 0){
				if(pattern[j] == '?'){
					if(good[tomatch[k] - 96] == false){
						cout << "NO\n";
						break;
					}
				}
				else if(pattern[j] != tomatch[k]){
					cout << "NO\n";
					break;
				}
				j--;
				k--;
			}
		}

		if(right.size() == 0){
			int j = 0;
			int k = 0;
			while(k <= 0){
				if(pattern[j] == '?'){
					if(good[tomatch[k] - 96] == false){
						cout << "NO\n";
						break;
					}
				}
				else if(pattern[j] != tomatch[k]){
					cout << "NO\n";
					break;
				}
				j--;
				k--;
			}
		}

	}
	
	return 0;
}