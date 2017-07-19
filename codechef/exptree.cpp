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

void gcd(long long &num, long long &denom){

	long long a = num;
	long long b = denom;
	long long r = a % b;
	while(r){

		a = b;
		b = r;
		r = a % b;
	}

	num = num / b;
	denom = denom / b;
}

void moduloinverse(long long a, long long b, long long& x, long long& y)
{
    if(a % b == 0)
    {
        x = 0;
        y = 1;
        return;
    }
    moduloinverse(b,a%b,x,y);
   
    long long temp = x;
    x = y;
    y = temp - y * (a / b);
}

long long inverse(long long a, long long p)
{
    long long x,y;

    moduloinverse(a,p,x,y);

    if(x<0){
    	x += p;
    }

    return x;
}


int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// freopen("B-small-attempt0.in","rt",stdin);
	// freopen("B.out","wt",stdout);

	int t;

	cin >> t;

	while(t--){
		long long n,num;

		cin >> n;

		long long num1 = n;
		long long num2 = n-1;
 		long long denom = 2 * (2 * n - 3);

		gcd(num1,denom);
		//cout << num1 << " " << denom << "\n";

		gcd(num2,denom);
		//cout << num2 << " " << denom << "\n";

		num = ((num1 % 1000000007) * (num2 % 1000000007)) % 1000000007;

		long long inv = inverse(denom, 1000000007);
		long long st = num % 1000000007;
		long long result1 = (inv * st) % 1000000007;

		num = ((num1 % 1000000009) * (num2 % 1000000009)) % 1000000009;

		inv = inverse(denom, 1000000009);
		st = num % 1000000009;
		long long result2 = (inv * st) % 1000000009;

		cout << result1 <<" "<< result2 << "\n";
	}
	
	return 0;
}