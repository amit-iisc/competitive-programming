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

	cin >> t;

	while(t--){

		string str;
		int num,min = 0,max = 0,temp;

		cin >> str;

		for(int i = 0; i < str.length();){

			num = 0;

			while((str[i] == '=' || str[i] == '>') && i < str.length()){
				if(str[i] == '>'){
					num++;
				}
				i++;
			}
			temp = max - num;
			if(temp < min){
				min = temp;
			}
			num = 0;
			while((str[i] == '=' || str[i] == '<') && i < str.length()){
				if(str[i] == '<'){
					num++;
				}
				i++;
			}
			temp = min + num;
			if(temp > max){
				max = temp;
			}  

		}

		cout << max-min+1 << "\n";
	}
	
	return 0;
}
