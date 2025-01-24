#include<stdio.h>
#include<stdbool.h>
#include "../lib/mainlib.h"

int main(){
// ** ||Instructions for users|| **//
  //TODO: // Uncomment the lines below to test specific functions./ You can modify the arguments or add new tests as needed.
  int size=3;
  int mat[3][3]={{2,0,1},{3,4,5},{1,1,1}};
  int pow=2;
  int result[size][size];
  
   
   //& Testing the basic functions


  //& Testing the intermediate functions

  matrixPower(size,mat,pow,result);
  printMatrix(size,size,result);


  //& Testing the advanced functions

    return 0;
}