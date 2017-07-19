#include<iostream>
using namespace std;


void merge(int *array,int low,int mid,int high){
	int start = low;
	int start2 = mid + 1;
	int result_arr[high-low+1];
	int begin = low;
	low = 0;



	while(start <= mid && start2 <= high){
		if(array[start] <= array[start2]){
			result_arr[low++] = array[start++];
		}
		else{
			result_arr[low++] = array[start2++];
		}
	}

	while(start <= mid){
		result_arr[low++] = array[start++];

	}
	while(start2 <= high){
		result_arr[low++] = array[start2++];
		
	}

	for(int i = 0;i <= high-begin;i++){
	
		array[begin + i] = result_arr[i];
	}
	

}

void mergeSort(int *array,int low,int high){

	int mid;
	if(low < high){
		mid = (low + high)/2;

		mergeSort(array,low,mid);
		mergeSort(array,mid+1,high);
		merge(array,low,mid,high);
    }
}

int main(){
	int n,number;
	
	int array[1000000];
	cin>>n;
	int j;
	//cin >> array[0];
	for(int i=0;i<n;i++){
		cin >> number;
		array[i] = number;
	}
	
	mergeSort(array,0,n-1);

	for(int i=0;i<n-1;i++){
		cout<<array[i]<<endl;
	}
	cout<<array[n-1];
	return 0;
}
		
			