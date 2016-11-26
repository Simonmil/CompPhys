#ifndef functions_H
#define functions_H

#include <string>
using std::string;

void printMatrix(double** A, int N);

void printEigVal(double** A, int N);

void writeEigVal(double** A, int N, int rho_max, double rho_min, int iterations, double eps, const string& folder_path, int num_elec);

void writeEigVec(double** R, int N,int rho_max, const string& folder_path, int num_elec);

void checkIterations(int iterations, int max_iterations);

#endif
