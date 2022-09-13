#include <math.h>
#include <stdio.h>
#include <limits.h>
// written by William Ament

//function def
int fact(int n);
double exp(double n);
double log(double n);

//main process
int main(){
    // factorial was written by me.
    // exp and log are from math.h
    printf("Factorial f(n) when n=8: %d \n", fact(8));
    printf("Exponential e(n) when n=5: %f \n", exp(5.0));
    printf("Logorithm l(n) when n=6 %f \n", log(6.0));
    return 0;
}

//factorial 
int fact(int n){
    int out = 1; 

    if( n<0){ //check for positive n
        printf("Error: N must be non-negative.");
        return 0;
    }else if (n == 0 || n == 1){ //return 1 for 0! and 1!
        return 1;
    }

    // set i to 1 to avoid multiplying by 0
    for(int i = 1; i < n; i++){
        if(INT_MAX*1.0 / out < 1){ //check for max_value
            printf("Error: n is too large. Overflow.");
        }
        out *= i;
    }
    return out;
}

