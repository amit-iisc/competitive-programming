
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
#include <complex>
#include <climits>

using namespace std;



#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)


int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// freopen("B-small-attempt0.in","rt",stdin);
	// freopen("B.out","wt",stdout);

	int t;

	cin >> t;

	while(t--){

		int n,m,max = 0,count = 0;

		queue<pair<int ,int> > q;
		int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

		cin >> n >> m;

		int arr[500][500];

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m ; j++){
				cin >> arr[i][j];
				if(arr[i][j] > max){
					max = arr[i][j];
				}
			}
			
		}

		//cout << "Here\n";

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m ; j++){
				if(arr[i][j] ==  max){
					arr[i][j] = 0;
					q.push(make_pair(i*m+j,0));
				}
				else{
					arr[i][j] = INT_MAX;
				}

			}
		}

		//cout << q.size() << endl;

		while(!q.empty()){
			pair <int, int> temp = q.front();
			q.pop();

			int i = temp.first / m;
			int j = temp.first % m;

			//cout<< " pass : ";
			//cout << i << j << endl;

			int val = temp.second;

			for(int k = 0; k < 8; k++){
				int x = i + dir[k][0];
				int y = j + dir[k][1];

				if(x >= 0 && x < n && y >= 0 && y < m){

					if(arr[x][y] > val + 1){
						arr[x][y] = val + 1;
						q.push(make_pair(x*m+y, val + 1));
					}
				}
			}

			//cout << q.size() << endl;
		}
		max = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m ; j++){
				if(arr[i][j] > max){
					max = arr[i][j];
				}
			}
		}

		printf("%d\n",max);
	}
	

}