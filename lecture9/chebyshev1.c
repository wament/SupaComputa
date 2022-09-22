#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    const int Nmax = 4;
    int N;

    printf("\n Input polynomial degree (0-%i): ", Nmax);
    scanf("%i", &N);
    if (N < 0 || N > Nmax){
        printf(" Invalid value N = %i.\n", N);
        printf(" N must satisfy: 0 <= N <= %i\n\n", Nmax);
        exit(1);
    }


    // read in coefficents
    double b[Nmax+1];
    for (int i=0; i <= N; i++){
        printf(" Enter b[%i]",i);
        scanf("%lf", &b[i]);
    }
    printf("\n");

    // set x-coordinates
    const int NumPts = 21; 
    double x[NumPts];
    for (int  i = 0; i < NumPts; i++)
    {
        x[i] = -1.0 + i*(2.0/(1.0*(NumPts-1)));
    }


    double y[NumPts];
    void SamplePoly(const int N, const int NumPts, const double b[], const double x[], double y[]);
    SamplePoly(N, NumPts, b, x, y);

    void WritePoly(const int NmuPts, const double x[], double y[]);
    WritePoly(NumPts, x, y);

    system("python3 PlotPoly.py");

    return 0;
};


void SamplePoly(const int N, const int NumPts, const double b[], const double x[], double y[]){
    for (int i=0; i < NumPts; i++){
        const double a = x[i];
        y[i] = b[0];
        for (int k = 1; k <=N; k++){
            double phi;
            if (k==1){
                phi = a;
            }else if(k==2){
                phi = 2.0* pow(a,2) -1;
            }else if(k==3){
                phi = 4.0* pow(a,3) - 3.0*a;
            }else if(k==4){
                phi = 8.0* pow(a,4) - 8.0* pow(a,2) + 1;
            }else{
                printf("Error \n");
                exit(1);
            }
            y[i] += b[k]*phi;
        }
    }
};

void WritePoly(const int NumPts, const double x[], double y[]){
    FILE *f;
    f = fopen("poly.data", "w");

    if (f == NULL){
        printf("Error!");
        exit(1);
    }

    for(int i = 0; i < NumPts; i++){
        fprintf(f, "%f %f\n", x[i], y[i]);
    }
    fclose(f);
};