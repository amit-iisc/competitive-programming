#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int t,n;
	long long sum = 0;
	int mod  = 1000000007;
	int *arr;
	long long *times;

	cin >> t;

	for(int test = 1; test <= t; test++){
		cin >> n;
		arr = new int[n];
		times = new long long[n];
		sum = 0;
		times[0] = 0;
		times[1] = 1;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		for(int i = 2; i < n; i++){
			times[i] = 2 * times[i-1];
			times[i] = times[i] % mod;
		}

		for(int i = 0; i < n; i++){
			for(int j = i; j < n ;j++){
				int diff = arr[j] - arr[i];
				sum = sum + (diff * times[j-i]);
			}
		}
		sum %= mod;
		cout << "case #" << test << ": " << sum <<endl;
	}
}