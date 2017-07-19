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


class CompareDist
{

	public:
	    bool operator()(pair<int,int> n1,pair<int,int> n2) {
	        return n1.second < n2.second;
	    }
};  

int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	//freopen("B.out","rt",stdin);
	//freopen("B1.out","wt",stdout);

	int t;

	cin >> t;

	while(t--){

		int n,d;

		long long happiness = 0,sadness = 0,temp2;
		cin >> n >> d;

		vector < pair<int ,int> > day[d+1];

		int di[n];
		long long ti[n];
		//pair <int ,int> sadness[n];

	    priority_queue < pair<int,int>,vector< pair<int,int> >,CompareDist > pq;

		for(int i = 0;i < n; i++){
			cin >> di[i] >> ti[i] >> temp2;
			day[di[i]].push_back(make_pair(i + 1,temp2));
			sadness += ti[i] * temp2;
			//cout << sadness << " " << ti[i] << " " << temp2 << "\n";
		}

		

		for(int i = 1; i <= d; i++){
			For(it,day[i]){
				pq.push(*it);
			}
			
			pair <int , int> temp_el = pq.top();
			if(!pq.empty()){
			
				happiness += temp_el.second;
			}

			if(!(--ti[temp_el.first - 1])){
				pq.pop();
				//cout << pq.size() << " i2\n";
			}

			//cout << happiness << " i\n";
		}
		
		cout << sadness - happiness << "\n";
		
	}
	
	return 0;
}