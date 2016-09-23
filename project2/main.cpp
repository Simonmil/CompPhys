#include <iostream>
#include <armadillo>
#include <cmath>
#include <string>
#include <time.h>

using namespace arma;
using namespace std;

int* largestNonDiagonalElement(mat A, double epsilon) {

    double maxValue;
    int* indexes = new int[2];
    indexes[0] = -1;
    double temp = 0;
    for(int i = 0; i < size(A,0); i++) {
        for(int j = 0; j < size(A,1); j++) {
            //Checking only values above the diagonal beacause A is symmetric
            if(j > i) {
                //Checking to find the maximum value in A.
                if(A(i,j) > epsilon) {
                   maxValue = A(i,j);
                   if(maxValue < temp) {
                       maxValue = temp;
                       indexes[0] = i;
                       indexes[1] = j;
                   }
                   else {
                       temp = maxValue;
                   }
                }

            }
        }

    }
    //returning the indexes where the maximum value resides in A

    return indexes;
}


void rotateJacobi() {

}


void similarityTransformation() {
    mat A;
    double epsilon;
    int indexTest = 0;
    while(indexTest != -1) {
        int* indexes = largestNonDiagonalElement(A, epsilon);

        indexTest = indexes[0];
    }
}

int main()
{

    mat A(5, 10, fill::randu);




    return 0;
}
