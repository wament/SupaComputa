#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int factorial(int n);

int main(int argc, char** argv){
    const double e = 2.718281828459; // e constant
    double input [argc-1]; // array of z values computed from z = x - x0
    double result [argc-1][11]; // array of computed exp values with n = [0-10]
    // argc - 1 because argv[0] is the program name, not a useful argument

    for(int in = 0; in < argc-1; in++){
        input[in] = atof(argv[in+1]) - round(atof(argv[in+1])); // z = x - x0
        // argv[in+1] because we want to iterate from 0, but skip the first input in argv (the program name)

        double approx [11]; // approximation of e^x for n = 0,1,2...,10
        double sum = 0; // series sum for appoximation

        for(int n = 0; n < 11; n++){ // n loop
            sum = 0;
            if(n == 0){ //series sum loop is skipped on first iteration. 
                sum = 1;
            }

            // 0 < 0 is false, loop is skipped on first iteration
            for(int s = 0; s < n; s++){ // series sum loop
                sum += pow(input[in], s) / factorial(s); // z^s / s!  where s <= n
            }
            result[in][n] = pow(e, round(atof(argv[in+1]))) * sum; // store computed exp value
        }
        
    }

    //print results out 
    for(int i = 0; i < argc-1; i++){
        printf("e^%f = [", atof(argv[i+1]));
        for(int j = 0; j < 10; j++){
            printf("%f, ",result[i][j]);
        }
        printf("%f]\n\n", result[i][10]);
    }
    return 0;
}



int factorial(int n){
    if(n <= 1){
        return 1;
    }
    return factorial(n-1)*n;
}