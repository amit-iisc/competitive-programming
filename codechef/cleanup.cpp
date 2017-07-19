
//  cleaningup.cpp
//  codechef
//
//  Created by Amit on 22/02/17.
//  Copyright Â© 2017 Amit. All rights reserved.
//

#include<iostream>
using namespace std;
 
int main(){
    
    int t;
    int n,m,index;
    
    cin >> t;
    while(t--){

        cin >>n >> m;
        
        bool array[n];
        bool flag = false;

        for(int i = 0;i < n;i++){
            
            array[i] = false;
        }
        
        for(int i=0;i<m;i++){
            
            cin >> index;
            array[index - 1] = true;
        }
        

        for(int i = 0; i < n; i++){
            
            //cout << "i = " << i << "\n";
            
            if(array[i] != true){
                if(flag == false){
                    cout << i+1 <<" ";
                    flag = true;
                    array[i] = true;
                }
                else{
                    flag = false;
                }
            }
        }
        
        cout << "\n";

        for(int i = 0; i < n; i++){
            //cout << "i = " << i << "\n";
            if(array[i] != true){
                    cout << i+1 <<" ";
            }
        }
        cout<<"\n";
        
    }
    return 0;
} 

