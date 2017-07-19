//
//  leadgame.cpp
//  codechef
//
//  Created by Amit on 21/02/17.
//  Copyright © 2017 Amit. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    
    int n,p1=0,p2=0,p3,p4;
    
    cin >> n;
    int winner = 1, maxlead = 0;
    
    for(int i=0; i < n;i++){
        cin >> p3;
        cin >> p4;
        p1 += p3;
        p2 += p4;
        if(maxlead < abs(p2 - p1)){
            maxlead = abs(p2 - p1);
            if(p2 > p1){
                winner = 2;
            }
            else{
                winner = 1;
            }
        }
        
    }
    cout << winner <<" "<<maxlead;
    return 0;
}
