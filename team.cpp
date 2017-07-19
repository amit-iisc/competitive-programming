#include <iostream>

using namespace std;




int main(){

	int t,n,m,t1,t2;
	cin >> t;

	while(t--){

		cin >> n >> m;

		for(int i = 0; i < m; i++){
			cin >> t1 >> t2;
		}

		if(n % 2 == 0){
			cout << "yes";

		}
		else
		{
			cout << "no";
		}
		cout << "\n";
	}	

}