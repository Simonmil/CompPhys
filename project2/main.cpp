#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
#include <Eigen/Eigenvalues>
#include <Eigen/Core>

using namespace std;
using Eigen::MatrixXd;
using namespace Eigen;

double potential(double);
void output(double, double, int, VectorXd );

//begin main program

int main(){
    int i, lOrbital, Dim;
    double RMin, RMax, Step, DiagConst, NondiagConst, OrbitalFactor;
    // With spherical coordinates RMin = 0 always
    RMin = 0.0;

    RMax = 8.0; lOrbital = 0; Dim=2000;
    MatrixXd Hamiltonian(Dim,Dim);
    // Integration step length
    Step = RMax/Dim;
    DiagConst = 2.0/(Step*Step);
    NondiagConst = -1.0 / (Step*Step);
    OrbitalFactor = lOrbital * (lOrbital + 1.0);

    // local memory for r and the potential w[r]
    VectorXf r;
    VectorXd w;
    for(i = 0; i < Dim; i++) {
        r(i) = RMin + (i+1) * Step;
        w(i) = potential(r(i)) + OrbitalFactor/(r(i) * r(i));
    }

    // Setting up tridiagonal matrix and brute diagonalization using Eigen
    Hamiltonian(0,0) = DiagConst + w(0);
    Hamiltonian(0,1) = NondiagConst;
    for(i = 1; i < Dim-1; i++){
        Hamiltonian(i,i-1) = NondiagConst;
        Hamiltonian(i,i) = DiagConst + w(i);
        Hamiltonian(i,i+1) = NondiagConst;
    }
    Hamiltonian(Dim-1,Dim-2) = NondiagConst;
    Hamiltonian(Dim-1,Dim-1) = DiagConst + w(Dim-1);
    //Diagonalize and obtain eigenvalues
    cout << Hamiltonian << endl;
    //RowVectorXd Eigval = Hamiltonian.eigenvalues();
    //output(RMin,RMax,Dim,Eigval);

    return 0;
}

/*
 * The function potential()
 * calculates and return the value of the
 * potential for a given argument x.
 * The potential here is for the hydrogen atom
 */

double potential(double x)
{
    return x*x;
}

void output(double RMin, double RMax, int Dim, VectorXd d)
{
    int i;
    cout << "Results:" << endl;
    cout << setiosflags(ios::showpoint | ios::uppercase);
    cout << "RMin = " << setw(15) << setprecision(8) << RMin << endl;
    cout << "RMax = " << setw(15) << setprecision(8) << RMax << endl;
    cout << "Number of steps = " << setw(15) << Dim << endl;
    cout << "Five lowest eigenvalues:" << endl;
    for(i = 0; i < 5; i++) {
        cout << setw(15) << setprecision(8) << d[i] << endl;
    }
}


