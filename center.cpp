#include<iostream>
using namespace std;

int main(){
	int t,n;

	float *x, *y, *w, min_x,max_x,min_y,max_y;

	cin >> t;

	for(int test = 1; test <= t; test++){
		cin >> n;

		x = new float[n];
		y = new float[n];
		w = new float[n];

		for(int i = 0;i < n; i++){
			cin >> x[i] >> y[i] >> w[i];
		}
	}
}