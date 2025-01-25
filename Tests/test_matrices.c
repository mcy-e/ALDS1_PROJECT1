#include<stdio.h>
#include<stdbool.h>
#include "../lib/mainlib.h"

int main(){
// ** ||Instructions for users|| **//
  //TODO: // Uncomment the lines below to test specific functions./ You can modify the arguments or add new tests as needed.
 // int size=3;
  //int mat[3][3]={{1,2,3},{4,5,6},{7,8,9}};
  //double mat2[3][3]={{1,2,3},{4,5,6},{7,8,9}};
  //int pow=2;
  //double result[size][size];
  //double upper[size][size];
  //double lower[size][size];
  //double arr[size]; 
  //& Testing the basic functions
  //initializeMatrix(size,size,result,1);
  //multiplyMatrices(size,size,mat,size,size,mat,result);
  
  //&Testing Matrix Operations
 // printf("%f\n",determinantMatrix(size,mat));
  //matrixPower(size,mat,2,result);
  //printMatrix(size,size,result);
  //& Testing Matrix Arithmetic



  //& Testing Matrix Properties and Checks




  //& Testing the advanced functions
  //cofactorMatrix(size,mat,result);
  //adjointMatrix(size,mat,result);
  //printMatrix(size,size,result);
  //luDecomposition(size,mat,lower,upper);
  //printf("\nThe matrix\n");
  //printMatrix(size,size,mat);
  //printf("%d",matrixRank(size,size,mat));


  //& Testing Special Matrix Operations
  // printf("%d",traceMatrix(size,mat));
  //printMatrix(size,size,mat2);
  //printf("\n");
  //rotateMatrix90(size,mat2);
  //printMatrix(size,size,mat2); 
  findEigenvalues(size,mat,arr);

  return 0;
}