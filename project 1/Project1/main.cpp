#include <iostream>
#include <new>
#include <cstdio>
#include <cstdlib>
#include <cstdio>

using namespace std;

/* What is the best way to declare an array and a matrix?
 */

void fi(double **f, int n){
    /* We are filling the array f with values from the function that is given
     */
    int i;
    /* Defining the step-length h
     */
    int h = 1/(n+1);

    for(i=0;i<n;i++){
        /*is this the correct way of calling the values in f?
         * Will this update f that is outside the function?
         * Is it correct to call exp just like that? Or do we need to #include some library?
         */
        f[i] = (h**2)*100*exp(-10*(i*h));
    }
}

void generalAlgorithm( double* A[], double* f[], double **f_d_tilde, int n){
    /*In this function we are going to solve the linear system Ax=f.
     * We use the general algorithm for a n x n tridiagonal matrix A.
     */


    /* void or double[]? How does return work in c++
     * Are the inputs correct? Is double* A[] a matrix?
     * Does double **f_d_tilde mean that we only make changes in f_d_tilde?
     * Does double **f_d_tilde mean that I can send in f_d_tilde as anything, as long as it works in the function?
     */
    int i;
    /* Is A[0][0] the correct way of calling the numbers? Or is it a better way to extract the numbers from the matrix A?
     */

    double b_init = A[0][0];
    double f_start = f[0]; //correct way to call the initial value?
    /* How do we declare an array?
     */


    double b_tilde[n];
    b_tilde[0] = b_init;


    double f_tilde[n];
    f_tilde[0] = f_start;

    for(i=1; i < n; i++){
        b_tilde[i] = A[i][i] - A[i][i-1]*A[i-1][i]/b_tilde[i-1];

        f_tilde[i] = f[i] - A[i][i-1]*f_tilde[i-1]/b_tilde[i-1];

    }
    f_d_tilde[n-1] = f_tilde[n-1]/b_tilde[n-1];
    for(i=n-2; i >= 0; i--){
        f_d_tilde[i] = (A[i][i+1]*f_d_tilde[i+1]/b_tilde[i+1])/b_tilde[i];
    }
    /*We hope that f_d_tilde is now returned, because this is the solution we want.
     */


}

int main()
{   /*
    rows = 10;
    int **A = new int*[rows];
    */
    return 0;

}
