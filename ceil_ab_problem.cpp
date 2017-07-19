//
//  ceil_ab_problem.cpp
//  codechef
//
//  Created by Amit on 22/02/17.
//  Copyright © 2017 Amit. All rights reserved.
//

#include <stdio.h>


int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    
    int result = a-b;
    if(result % 10 == 9){
        result = (result / 10) * 10 + 1;
    }
    else{
        result = (result / 10) * 10 + 9;
    }
    printf("%d",result);
}
