#include<iostream>
using namespace std;

int main(){
	int t,m,n,k;

	char **arr;
	int **tri_size;

	cin >> t;

	for(int test = 1; test <= t; test++){
		cin >> m >> n >> k;

		arr =  new char[m][n];
		tri_size = new int[m][n];

		int min;

		for(int i = 0;i < m; i++){
			for(int i = 0;i < n; i++){
				cin >> arr[i][j];
			}
		}

		for(int i = 0;i < m; i++){
			for(int i = 0;i < n; i++){
				cin >> arr[i][j];
			}
		}

		for(int i = m-1; i >=0 ; i--){
			if(arr[i][n-1] == '#'){
				tri_size[i][n-1] = 1;
			}
			else{
				tri_size[i][n-1] = 0;
			}
			if(arr[i][0] == '#'){
				tri_size[i][0] = 1;
			}
			else{
				tri_size[i][0] = 0;
			}
		}

		for(int j = 0; j < n; j++){
			if(arr[m-1][j] == '#'){
				tri_size[m-1][j] = 1;
			}
			else{
				tri_size[m-1][j] = 0;
			}
		}

		for(int i = m-2;i >= 0; i--){
			for(int j = 1; j < n-1; j++){

				if(arr[i][j] == '#'){
					min = (arr[i+1][j-1] < arr[i+1][j]) ? arr[i+1][j-1] : arr[i+1][j];
					min = (min < arr[i+1][j+1]) ? min : arr[i+1][j+1];

					arr[i][j] = min + 1;
				}
				else{
					arr[i][j] = 0;
				}

			}
		}

	}
}