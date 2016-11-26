#include <cmath>
#include <iostream>
#include "jacobi.h"



double max_offdiag(double** A, int* k, int* l, int N){

    double max = 0.0;

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(fabs(A[i][j]) > max){
                max = fabs(A[i][j]);
                *k = i;
                *l = j;
            }
        }
    }
    return max;
}


void rotate (double** A, double** R, int k, int l, int n){
    //rotation function

    double t,s,c;

    if (A[k][l] != 0.0){

        double tau = (A[l][l] - A[k][k])/(2*A[k][l]);

        if (tau > 0){

            t = -tau + sqrt(1 + tau*tau);
        }
        else{
            t = -tau - sqrt(1 + tau*tau);
        }
        c = 1.0/sqrt(1+t*t);
        s = t*c;
    }
    else{
        c = 1.0;
        s = 0.0;
    }
    double a_kk, a_ll, a_il, a_ik, r_il, r_ik;

    // starting algorithm

    a_kk = A[k][k];
    a_ll = A[l][l];


    A[k][k] = a_kk*c*c - 2*A[k][l]*c*s + a_ll*s*s;
    A[l][l] = a_ll*c*c + 2*A[k][l]*c*s + a_kk*s*s;
    A[k][l] = 0;
    A[l][k] = 0;

    for (int i = 0; i < n; i++){
        if (i != k && i != l){
            a_ik = A[i][k];
            a_il = A[i][l];
            A[i][k] = a_ik*c - a_il*s;
            A[k][i] = A[i][k];

            A[i][l] = a_il*c + a_ik*s;
            A[l][i] = A[i][l];
        }

        // And now, the eigenvectors
        r_ik = R[i][k];
        r_il = R[i][l];
        R[i][k] = c*r_ik - s*r_il;
        R[i][l] = c*r_il + s*r_ik;


    }
    return;

}



















