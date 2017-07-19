#include <iostream>
using namespace std;

int main(){

	int t,j,num_tasks,first_even,first_odd,second_even,second_odd,first,second;

	cin >> t;

	for(int i = 0;i < t;i++){

		cin >> num_tasks;
		first_even = 0;
		first_odd = 0;
		second_even = 0;
		second_odd = 0;

		for(j = 0; j < num_tasks ;j++){

			cin >> first;
			if((j+1) % 2 == 0){
				first_even += first;
			}
			else{
				first_odd += first;
			}
		}

		for(j = 0; j < num_tasks ;j++){

			cin >> second;
			if((j+1) % 2 == 0){
				second_even += second;
			}
			else{
				second_odd += second;
			}
		}

		if(first_odd + second_even  > first_even + second_odd){
			cout << first_even + second_odd << endl;
		}
		else{
			cout << first_odd + second_even << endl;
		}
	}

	return 0;
}