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
    
    cin >>t;
    
    while(t--){
        
        int n, arr[3],min_arr[3];
        
        cin >> n;
        cin >> arr[0] >> arr[1] >> arr[2];
        
        int result[n+1];
        
        result[0] = INT_MAX;
        result[1] = arr[0];
        result[2] = min(2 * arr[0], arr[0] + arr[2]);
        
        for(int i = 3; i <= n ;i++){
            int temp;
            if(i % 2 == 0){
                
                min_arr[0] = result[i-1] + arr[0];
                min_arr[1] = result[i/2] + arr[2];
                min_arr[2] = result[(i + 2)/2] + arr[2] + 2 * arr[1];
                temp =  *min_element(min_arr, min_arr + 3);

                cout << temp << "if even \n";
            }
            else{
                temp = min(result[i-1] + arr[0], result[i/2 + 1] + arr[2] + arr[1]);
                cout << temp << "if odd \n";
            }
            result[i] = temp;
        }
        
       cout << result[n] << "\n"; 
    }

    return 0;
}
