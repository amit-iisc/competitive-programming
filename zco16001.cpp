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


int findMax(vector<int> v1, vector<int> v2, int k){

	priority_queue <int> p1,p2;

	for(int i = 0; i < v1.size();i++){
		p1.push(v1[i]);
	}

	for(int i = 0; i < v2.size();i++){
		p2.push(-v2[i]);
	}

	while(p1.top() > -(p2.top()) && k > 0){

		int temp = p1.top();
		int temp2 = p2.top();
		p1.pop();
		p2.pop();

		//cout << temp << " " << temp2 << "\n";

		p1.push(-temp2);
		p2.push(-temp);

		k--;
	}

	while(p2.size() > 1){
		p2.pop();
	}

	return p1.top() - p2.top();
}

int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// freopen("B-small-attempt0.in","rt",stdin);
	// freopen("B.out","wt",stdout);

	int n,k,result;

	cin >> n >> k;

	vector <int> v1(n);
	vector <int> v2(n);

	for(int i = 0; i < n; i++){
		cin >> v1[i];
	}

	for(int i = 0; i < n; i++){
		cin >> v2[i];
	}


	// if(*max_element(all(v1)) <= *max_element(all(v2))){
	// 	result = findMax(v1,v2,k);
	// }
	// else{
	// 	result = findMax(v2,v1,k);
	// }

	result = min(findMax(v1,v2,k),findMax(v2,v1,k));
	

	cout << result << "\n";
	
	return 0;
}