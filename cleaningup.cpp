//
//  cleaningup.cpp
//  codechef
//
//  Created by Amit on 22/02/17.
//  Copyright © 2017 Amit. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;

int main(){
    
    int t;
    int n,m;
    
    scanf("%d", &t);
    for(int k=0;k < t;k++){
        scanf("%d %d",&n,&m);
        int array[n];
        int index;
        
        
        for(int i=0;i<m;i++){
            
            scanf("%d",&index);
            array[index - 1] = -1;
        }
        index = 0;
        for(int i = 0; i < n; i++){
            if(array[i] != -1){
                if(index == 0){
                    cout << i+1 <<" ";
                }
                index = (index + 1) % 2;
            }
        }
        cout << "\n";
        index = 0;
        for(int i = 0; i < n; i++){
            if(array[i] != -1){
                if(index == 1){
                    cout << i+1 <<" ";
                }
                index = (index + 1) % 2;
            }
        }
        cout<<"\n";
        
    }
    return 0;
}
