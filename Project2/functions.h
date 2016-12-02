#ifndef functions_H
#define functions_H

#include <string>
using std::string;

void printMatrix(double** A, int N);

void printEigVal(double** A, int N);

void writeEigVal(double** A, int N, int rho_max, int rho_min, int iterations, double eps, const string& folder_path, int num_elec);

void writeEigVec(double** R, int N,int rho_max, const string& folder_path, int num_elec);

void writeEigValTwoElec(double** A, int N, int rho_max, int rho_min, int iterations, double eps, const string& folder_path, double omega_r);

void writeEigVecTwoElec(double** R, int N, int rho_max, const string& folder_path, double omega_r);

void checkIterations(int iterations, int max_iterations);

#endif
