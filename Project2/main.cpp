#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <armadillo>
#include <string>
#include "time.h"
#include "jacobi.h"
#include "functions.h"


using namespace std;
using namespace arma;



int main(int argc, char *argv[]){

    // Retrieving constants from commandline

    int N = atoi(argv[1]);
    double rho_min = atof(argv[2]);
    int rho_max = atoi(argv[3]);
    double omega_r = atof(argv[4]);
    string folder_path = argv[5];
    int num_elec = atoi(argv[6]);

    // Timer function

    std::ofstream timeit;
    timeit.open(folder_path + "/times/timeit.txt", std::ios_base::app);
    //timeit.open(folder_path + "/timeit_N" + to_string(N) + "_rhomax" + rho_max + ".txt");

    // iteraion limits

    int iterations = 0;
    int max_iterations = 1e7;
    double eps = 1e-8;
    double h = (rho_max - rho_min)/(N+1);

    // Setting up A and R

    double** A = new double*[N];
    double** R = new double*[N];
    for (int i = 0; i < N; i++){
        A[i] = new double[N];
        R[i] = new double[N];
    }

    // Setting V

    double* V = new double[N];

    if (num_elec == 1){
        for (int i = 1; i < N+1; i++){
            V[i-1] = (i*h)*(i*h);       //rho[i]**2
        }
    }
    else{
        for (int i = 1; i < N+1; i++){
            V[i-1] = omega_r*omega_r*(i*h)*(i*h) + 1.0/(i*h);
        }
    }

    // Giving A values

    double h_marked = 1.0/(h*h);
    for (int i = 0; i < N-1; i++){
        A[i][i] = 2*h_marked + V[i];
        A[i][i+1] = -h_marked;
        A[i+1][i] = -h_marked;
    }
    A[N-1][N-1] = 2.0*h_marked + V[N-1];

    // Giving R values

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            R[i][j] = 0.0;
        }
        R[i][i] = 1.0;
    }

    // starting the timing of the algorithm
    clock_t start, finish;
    start = clock();

    // Start the algorithm

    int k,l;
    double maxoffdiag = max_offdiag(A, &k, &l, N);
    while (maxoffdiag > eps && iterations < max_iterations){
        rotate(A,R,k,l,N);
        maxoffdiag = max_offdiag(A, &k, &l, N);
        iterations++;
    }

    // Ending algorithm clock
    finish = clock();
    timeit << "Jacobi:      " << "N " << std::setw(5) << N;
    timeit << "rho_min " << std::setw(5) << rho_min << " rho_max " << std::setw(5) << rho_max << " Time: ";
    timeit << std::setw(10) << std::setprecision(10) << ((finish - start)/((double)CLOCKS_PER_SEC/1000));
    timeit << " ms/n";

    checkIterations(iterations, max_iterations);

    // Writing eigenvalues and eigenvectors

    writeEigVal(A,N,rho_max,rho_min,iterations,eps,folder_path,num_elec);
    writeEigVec(R,N,rho_max,folder_path,num_elec);


    // Deallocation of memory

    for (int i = 0; i < N; i++){
        delete [] R[i];
        delete [] A[i];
    }
    delete [] A;
    delete [] R;
    delete [] V;
}


