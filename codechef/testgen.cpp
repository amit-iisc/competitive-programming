
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

using namespace std;



#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)


int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	//freopen("B-small-attempt0.in","rt",stdin);
	freopen("B.out","wt",stdout);

	int test = 100000;

	srand((unsigned)time(0)); 
    int n;
    n = 13;//((rand()%100)+50) * 6; 
    cout <<"1\n" << n << "\n"; 

    int final = 1;
    int initial = 1;
    int i = 1;
    while(i < n){
    	srand((unsigned)time(0) + i); 
    	int m = (rand()%3)+1;
    	for(int j = 1; j <= m && i < n; j++){
    		cout << initial << " " << j + final <<"\n";
    		i++;
    	}
    	srand((unsigned)time(0) + rand());
    	initial = (rand()% m)+1+final;
    	final = final + m;
    	
    }

}