#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::ofstream;
using std::setw;
using std::string;
using std::to_string;


void printMatrix(double** A, int N){

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << setw(12) << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}

void printEigVal(double** A, int N){
    // Function that prints eigenvalues of A

    for (int i = 0; i < N; i++){
        cout << A[i][i] << endl;
    }
    return;
}

void writeEigVal(double** A, int N, int rho_max, double rho_min, int iterations, double eps, const string& folder_path, int num_elec){
    // Function for writing eigenvalues to file

    ofstream data;
    data.open(folder_path + "/eigen_values_N" + to_string(N) + "rhomax" + to_string(rho_max) + "numelec" + to_string(num_elec) + ".txt");
    data << "rho_max: " << rho_max << endl;
    data << "rho_min: " << rho_min << endl;
    data << "iterations: " << iterations << endl;
    data << "N: " << N << endl;
    data << "eps: " << eps << endl;

    for (int i = 0; i < N; i++){
        data << setw(5) << A[i][i] << " " << endl;
    }
    data.close();
    cout << folder_path << "/eigen_values_N" << to_string(N) << "rhomax" << to_string(rho_max) << "numelec" << to_string(num_elec) << ".txt" << " written" << endl;
    return;
}

void writeEigVec(double** R, int N, int rho_max, const string& folder_path,int num_elec){
    // Function for writing eigenvectors to file

    ofstream data;
    data.open(folder_path + "/eigen_vector_N" + to_string(N) + "rhomax" + to_string(rho_max) + "numelec" + to_string(num_elec) + ".txt");

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            data << setw(20) << R[i][j];
        }
        data << endl;
    }
    data.close();
    cout << folder_path << "/eigen_vectors_N" << to_string(N) << "rhomax" << to_string(rho_max) << "numelec" << to_string(num_elec) << ".txt" << " written" << endl;
    return;
}

void checkIterations(int iterations, int max_iterations){
    // To check if we exceeded the maximum limit of iterations

    if (iterations == max_iterations){
        cout << "The limit of iterations is reached=" << max_iterations << endl;
    }
    else{
        cout << "Iterations: " << iterations << endl;
    }
}






