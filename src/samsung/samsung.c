//
// Created by EARN on 09-06-2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "samsung.h"



//
int Gcd(int num1, int num2)
{
    if (num2 != 0)
        return Gcd(num2, num1%num2);
    else
        return num1;
}

int* newArray( int size){
    int* pointer;
    pointer = (int* ) calloc(size, sizeof(int));
    return pointer;
}


int function(){
    int N, Q, i;
    int *array;
    array = newArray(1000);

    //INPUT
    scanf("%d %d", &N, &Q);

    for (i = 0; i< N; i++) {
        scanf("%d",& array[i]);
    }
    for (int j = 0; j < Q; j++) {
        logic(array);
    }
}

void logic(int *array){

    int L, R;
    int count;
    int result;
    scanf("%d %d",&L,&R);
    count = R-L;
    if(count == 1){
        printf("%d\n",Gcd(Fibonacci(array[L-1]),Fibonacci(array[R-1])));
    }else{
        while(L <= R){
            result= Gcd(Fibonacci(L-1),Fibonacci(L));
            Gcd(result,Fibonacci(R));
            L++;
        }
        printf("%d\n",result);
    }

}


void multiply(int F[2][2], int M[2][2]);

void power(int F[2][2], int n);

int Fibonacci(int n)
{
    int F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(F, n-1);
    return F[0][0];
}


void power(int F[2][2], int n)
{
    if( n == 0 || n == 1)
        return;
    int M[2][2] = {{1,1},{1,0}};

    power(F, n/2);
    multiply(F, F);

    if (n%2 != 0)
        multiply(F, M);
}

void multiply(int F[2][2], int M[2][2])
{
    int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
    int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
    int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
    int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}