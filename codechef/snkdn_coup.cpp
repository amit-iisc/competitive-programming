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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

	// freopen("B-small-attempt0.in","rt",stdin);
	// freopen("B.out","wt",stdout);

	int t,n;
	char *arr1,*arr2;

	cin >> t;

	while(t--){

		cin >> n;
		arr1 = new char[n];
		arr2 = new char[n];

		int flag1 = 0,flag2 = 0,wallcount = 0,flag3 = 0,flag4 = 0;

		for(int i = 0; i < n; i++){
			cin >> arr1[i];
		}
		for(int i = 0; i < n; i++){
			cin >> arr2[i];
		}

		for(int i = 0; i < n; i++){

			if(arr1[i] == '*'){
				flag3 = 1;
				if(flag1 == 1){
					wallcount++;
					flag2 = 0;
				}
				else{
					flag1 = 1;
				}	
			}
			if(arr2[i] == '*'){
				flag4 = 1;
				if(flag2 == 1){
					wallcount++;
					if(arr1[i] != '*'){
						flag1 = 0;
					}
				}
				else{
					flag2 = 1;
				}		
			}
			
		}

		if(flag3 == 1 && flag4 == 1){
			wallcount++;
		}

		printf("%d\n",wallcount);

	}
	

}