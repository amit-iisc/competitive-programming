//
//  xor_sum.cpp
//  codechef
//
//  Created by Amit on 21/02/17.
//  Copyright © 2017 Amit. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    
    int array[1000001];
    
    array[0] = 0;
    
    for(int i = 1; i<= 1000000;i++){
       // cout<<"here"<<i;
        if(i % 2 != 0){
            array[i] = i;
        }
        
        else{
            
                array[i] = array[i/2];
           
        }
        
    }
    for(int i = 1;i <= 1000000;i++){
        array[i] = array[i] ^ array[i-1];
    }
    
    int q,l,r,result;
    
   // cout << "enter input";
    
    cin >> q;
    
    for(int i = 0; i < q; i++){
        
        
        
        cin >> l;
        cin >> r;
        
        result = array[l-1] ^ array[r];
        cout << result << endl;
    }
}
