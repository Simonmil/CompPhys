#include <iostream>

#include "time.h"

using namespace std;


double SourceTerm(double x){
    return 100*exp(-10*x);
}

double uExact(double x) {

   return 1 - (1 - exp(-10))*x - exp(-10*x);
}

void generalAlgorithm(double* a, double* b, double* c, double* f, double* v, int n){
    // This general algorithm solves the system -u'' = f, u(0) = u(1) = 0.

    // Initial condition force us to set these to zero
    a[0] = 0; b[0] = 0; c[0] = 0; f[0] = 0; v[0] = 0;
    a[n+1] = 0; b[n+1] = 0; c[n+1] = 0; f[n+1] = 0; v[n+1] = 0;


    for(int i=2; i < n+1; i++){
        b[i] = b[i] - a[i-1]*c[i-1]/b[i-1];

        f[i] = f[i] - a[i-1]*f[i-1]/b[i-1];

    }
    v[n] = f[n]/b[n];
    for(int i=n-1; i > 0; i--){
        v[i] = f[i] - (c[i+1]*v[i+1])/b[i];
    }
}

double RelError(double* v, double (uExact)(double),int n) {
    double* epsilon = new double[n+2];
    for(int i=0;i<n+2;i++) {
        epsilon[i] = log10(abs((v[i] - uExact(i)/uExact(i))));
    }
    return 0;
}

void FirstDerivative(double* a, double* b, double* c, double* f, double (SourceTerm)(double), int n){
    double h = 1.0/(n+1);

    for(int i=0;i<n+2;i++){
        b[i] = 2;
        c[i] = -1;
        a[i] = -1;
        f[i] = h*h*SourceTerm(i*h);
    }

}

void SecondDerivative(double* a, double* b, double* c, double* f, double (SourceTerm)(double), int n){
    double h = 1.0/(n+1);

    for(int i=0;i<n+2;i++){
        b[i] = 2;
        c[i] = -1;
        a[i] = -1;
        f[i] = h*h*SourceTerm(i*h);
    }

}

int main()
{
    int n = 10;

    double* b = new double[n+2]; // dette oppretter en dynamisk allokert array.
    double* c = new double[n+2];
    double* a = new double[n+2];
    double* f = new double[n+2];
    double* v = new double[n+2];

    // FirstDerivative(a, b, c, f, n)

    // SecondDerivative(a, b, c, f, n)

    // generalAlgorithm(a, b, c, f, v, n);


    return 0;

}
