//
//  trianglesum.cpp
//  codechef
//
//  Created by Amit on 21/02/17.
//  Copyright © 2017 Amit. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int t,n;
    
    cin >> t;
    for(int i=0; i < t;i++){
        cin >> n;
        int mat[n][n];
        for(int j = 0;j < n;j++){
            for(int k = 0; k <= j ;k++){
                cin >> mat[j][k];
            }
        }
        
        for(int j = n-2;j >= 0;j--){
            mat[j][n-1] = mat[j][n-1] + mat[j+1][n-1];
            for(int k = 0; k <= j ;k++){
                if(mat[j+1][k] > mat[j+1][k+1]){
                    mat[j][k] += mat[j+1][k];
                }
                else{
                    mat[j][k] += mat[j+1][k+1];
                }
            }
        }
        cout << mat[0][0]<<endl;
    }
}
