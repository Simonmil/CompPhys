#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <armadillo>
#include "time.h"

using std::cout;
using std::string;
using std::endl;
using std::ofstream;
using std::setw;
using arma::vec;
using arma::mat;
using arma::zeros;
using arma::eig_sym;



int main(int argc, char *argv[]){

    // Retrieving constants from commandline

    int N = atoi(argv[1]);
    double rho_min = atof(argv[2]);
    int rho_max = atoi(argv[3]);
    string folder_path = argv[4];


    // Timer function

    std::ofstream timeit;
    timeit.open(folder_path + "/times/armatime.txt", std::ios_base::app);

    // iteraion limits

    int iterations = 0;
    double eps = 1e-8;
    double h = (rho_max - rho_min)/(N+1);

    // Setting up A

    mat A = zeros<mat>(N,N);
    vec V = zeros<vec>(N);
    mat Eigvecs = zeros<mat>(N,N);
    vec Eigvals = zeros<vec>(N);

    // Setting V


    for (int i = 1; i < N+1; i++){
       V(i-1) = (i*h)*(i*h);       //rho[i]**2
    }

    // Giving A values

    double h_marked = 1.0/(h*h);
    for (int i = 0; i < N-1; i++){
        A(i,i) = 2*h_marked + V(i);
        A(i,i+1) = -h_marked;
        A(i+1,i) = -h_marked;
    }
    A(N-1,N-1) = 2.0*h_marked + V(N-1);


    // starting the timing of the algorithm
    clock_t start, finish;
    start = clock();

    // Start the algorithm


    eig_sym(Eigvals,Eigvecs,A);

    // Ending algorithm clock
    finish = clock();
    timeit << "Arma:      " << "N " << std::setw(5) << N;
    timeit << "rho_min " << std::setw(5) << rho_min << " rho_max " << std::setw(5) << rho_max << " Time: ";
    timeit << std::setw(10) << std::setprecision(10) << ((finish - start)/((double)CLOCKS_PER_SEC/1000));
    timeit << " ms/n";


    // Function for writing eigenvalues to file

    ofstream data;
    data.open(folder_path + "/Armadillo_eigenvalues" + ".txt");
    data << "rho_max: " << rho_max << endl;
    data << "rho_min: " << rho_min << endl;
    data << "iterations: " << iterations << endl;
    data << "N: " << N << endl;
    data << "eps: " << eps << endl;

    for (int i = 0; i < N; i++){
        data << setw(5) << A(i,i) << " " << endl;
    }
    data.close();
    cout << folder_path << "/Armadillo_eigenvalues" << ".txt" << " written" << endl;

    return 0;

}
