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

	int t;
	string str;

	cin >> t;
	getline(cin,str);

	while(t--){

		int s_vote = 0,m_vote = 0;

		getline(cin,str);

		// if(str[0] == 'm'){
		// 	if(str[1] == 's'){
		// 		str[1] = 'd';
		// 	}
		// }

		for(int i = 0; i < str.length() ; i++){

			if(str[i] == 'm'){
				if(i-1 >= 0 && str[i-1] == 's'){
					str[i-1] = 'd';
				}
				else if(i+1 < str.length() && str[i+1] == 's'){
					str[i+1] = 'd';
				}
			}
		}

		for(int i = 0; i < str.length(); i++){
			
			if(str[i] == 'm'){
				m_vote++;
			}
			if(str[i] == 's'){
				s_vote++;
			}

		}

		//printf("%d %d\n",m_vote,s_vote);
		//printf("%s\n",str.c_str());

		if(s_vote == m_vote){
			printf("tie\n");
		}
		else if(s_vote > m_vote){
			printf("snakes\n");
		}
		else{
			printf("mongooses\n");
		}



	}
	

}