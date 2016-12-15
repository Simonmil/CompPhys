#include "unittest.h"
#include <iostream>
#include <cmath>
#include "functions.h"
#include "jacobi.h"


using std::cout;
using std::endl;

bool TestJacobiRotation(bool passed){
    int N = 2;
    double** A = new double*[N];
    for(int i = 0; i < N;i++){
        A[i] = new double[N];
    }

    double** R = new double*[N];
    for(int i = 0; i < N;i++){
        R[i] = new double[N];
    }

    A[0][0] = 2; A[0][1] = 1;
    A[1][0] = 1; A[1][1] = 2;

    int lambda1 = 3;
    int lambda2 = 1;

    int iterations = 0;
    int max_iterations = 1e7;
    double eps = 1e-8;

    int k, l;
    double maxoffdiag = max_offdiag(A, &k, &l, N);
    while(fabs(maxoffdiag) > eps && iterations < max_iterations){
        rotate(A,R,k,l,N);
        maxoffdiag = max_offdiag(A,&k,&l,N);
        iterations++;
    }


    if(iterations == 1 && (A[0][0]-lambda1) < 1e-16 && (A[1][1]-lambda2) < 1e-16){
        cout << "Jacobi-test: Passed" << endl;
        return passed;
    }
    else{
        cout << "Jacobi-test: Failed" << endl;
        passed = false;
        return passed;
    }

}

bool TestOrthogonality(bool passed){

    bool orth_pass = true;
    double orth_eps = 1e-14;

    int N = 200;
    double rho_min = 0.0;
    double rho_max = 5.0;
    double h = (rho_max-rho_min)/(N+1);

    double** A = new double*[N];
    double** R = new double*[N];
    for(int i = 0; i < N;i++){
        A[i] = new double[N];
        R[i] = new double[N];
    }

    double* V = new double[N];


    for(int i = 1; i < N+1;i++){
        V[i-1] = (i*h)*(i*h);
    }


    double h_marked = 1.0/(h*h);
    for(int i = 0; i < N-1; i++){
        A[i][i] = 2.0*h_marked + V[i];
        A[i][i+1] = -h_marked;
        A[i+1][i] = -h_marked;
    }
    A[N-1][N-1] = 2.0*h_marked + V[N-1];


    for(int i = 0;i < N; i++){
        for(int j = 0; j < N; j++){
            R[i][j] = 0.0;
        }
        R[i][i] = 1.0;
    }


    int iterations = 0;
    int max_iterations = 1e7;
    double eps = 1e-8;


    int k, l;
    double maxoffdiag = max_offdiag(A, &k, &l, N);
    while(fabs(maxoffdiag) > eps && iterations < max_iterations){
        rotate(A,R,k,l,N);
        maxoffdiag = max_offdiag(A, &k, &l, N);
        iterations++;


        if(iterations % 10 == 0){
            double total_dot_sum = 0;

            for(int i = 0; i < N-1; i++){
                double dot_sum = 0;

                for(int j = 0; j < N; j++){
                    dot_sum += R[j][i]*R[j][i+1];
                }

                total_dot_sum + dot_sum;
            }

            if(fabs(total_dot_sum) > orth_eps){
                cout << "Orthogonality test: Failed" << endl;
                passed = false;
                return passed;
            }
        }
    }
    cout << "Orthogonality test: Passed" << endl;
    return passed;
}
