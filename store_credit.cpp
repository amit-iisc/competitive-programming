#include <iostream>
#include <fstream>
using namespace std;

int main(){

	int n,c,l;

	ifstream myfile;
    myfile.open ("A-large-practice.in");

	int *arr;

	myfile >> n;

	for(int t = 0; t < n; t++){

		myfile >> c >> l;

		bool flag = false;

		arr = new int[l];

		for(int i = 0; i < l; i++){
			myfile >> arr[i];
		}

		for(int i = 0; i < l ;i++){
			for(int j = i + 1; j < l; j++ ){
				if( arr[i] + arr[j] == c){
					cout << "Case #" << t + 1 << ": " << i + 1<< " " << j + 1 << endl;
					flag = true;
					break;
				}
			}
			if(flag == true){
				break;
			}
		}
	}
}