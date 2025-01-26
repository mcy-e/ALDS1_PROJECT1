#include<stdio.h>
#include<stdbool.h>
#include "../lib/mainlib.h"


int main(){
  // ** ||Instructions for users|| **//
  //TODO: // Uncomment the lines below to test specific functions./ You can modify the arguments or add new tests as needed.
  
 //& Testing the basic functions 
 /*printf("Initialize Matrix Test\n");
 int size = 3;
 double result[size][size];
 initializeMatrix(size, size, result, 1);
 printMatrix(size, size, result);

 printf("\nCopy Matrix Test\n");
 double original[size][size] = {{1,2,3},{4,5,6},{7,8,9}};
 double copy[size][size];
 copyMatrix(size, size, original, copy);
 printMatrix(size, size, copy);*/

 //& Testing Matrix Arithmetic
 /*int mat1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
 int mat2[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
 int result[3][3];

 printf("Add Matrices Test\n");
 addMatrices(size, size, mat1, mat2, result);
 printMatrix(size, size, result);

 printf("\nSubtract Matrices Test\n");
 subtractMatrices(size, size, mat1, mat2, result);
 printMatrix(size, size, result);

 printf("\nMultiply Matrices Test\n");
 multiplyMatrices(size, size, mat1, size, size, mat2, result);
 printMatrix(size, size, result);

 printf("\nScalar Multiply Matrix Test\n");
 double scalar_mat[size][size] = {{1.0,2.0,3.0},{4.0,5.0,6.0},{7.0,8.0,9.0}};
 scalarMultiplyMatrix(size, size, scalar_mat, 2.0);
 printMatrix(size, size, scalar_mat);*/

 //& Testing Matrix Properties and Checks
 /*printf("Is Square Matrix: %d\n", isSquareMatrix(size, size));
 printf("Is Identity Matrix: %d\n", isIdentityMatrix(size, mat1));
 printf("Is Diagonal Matrix: %d\n", isDiagonalMatrix(size, mat1));
 printf("Is Symmetric Matrix: %d\n", isSymmetricMatrix(size, mat1));
 printf("Is Upper Triangular: %d\n", isUpperTriangular(size, mat1));*/

 //& Testing Matrix Operations
 /*double trans_mat[size][size] = {{1,2,3},{4,5,6},{7,8,9}};
 double trans_result[size][size];
 transposeMatrix(size, size, trans_mat, trans_result);
 printMatrix(size, size, trans_result);

 printf("\nDeterminant Test: %f\n", determinantMatrix(size, trans_mat));

 double inv_mat[size][size] = {{1,2,3},{0,1,4},{5,6,0}};
 double inv_result[size][size];
 inverseMatrix(size, inv_mat, inv_result);
 printMatrix(size, size, inv_result);*/

 //& Testing Advanced Matrix Functions
 /*double cofactor_mat[size][size] = {{1,2,3},{4,5,6},{7,8,9}};
 double cofactor_result[size][size];
 cofactorMatrix(size, cofactor_mat, cofactor_result);
 printMatrix(size, size, cofactor_result);

 double adj_mat[size][size] = {{1,2,3},{4,5,6},{7,8,9}};
 double adj_result[size][size];
 adjointMatrix(size, adj_mat, adj_result);
 printMatrix(size, size, adj_result);

 double lu_mat[size][size] = {{1,2,3},{4,5,6},{7,8,9}};
 double lower[size][size];
 double upper[size][size];
 luDecomposition(size, lu_mat, lower, upper);

 printf("\nMatrix Rank: %d\n", matrixRank(size, size, lu_mat));*/

 //& Testing Special Matrix Operations
 /*printf("Trace Matrix: %d\n", traceMatrix(size, mat1));

 double rotate_mat[size][size] = {{1,2,3},{4,5,6},{7,8,9}};
 rotateMatrix90(size, rotate_mat);
 printMatrix(size, size, rotate_mat);

 double eigen_mat[size][size] = {{1,2,3},{4,5,6},{7,8,9}};
 double eigenvalues[size];
 findEigenvalues(size, eigen_mat, eigenvalues);
 
 double eigen2x2[2][2] = {{1,2},{3,4}};
 double eigenvalues2x2[2];
 findEigenvalues2x2(eigen2x2, eigenvalues2x2);*/

  return 0;
}