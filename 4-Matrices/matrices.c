#include<stdbool.h>
#include<math.h>
#include<stdio.h>
#include "../lib/mainlib.h"
#include<limits.h>
//& MAKE SURE TO INSTALL BETTER COMMENTS EXTENSION IF YOU ARE IN VS CODE FOR BETTER READABILITY 

//!Basic Functions
void initializeMatrix(int rows, int cols, int matrix[rows][cols], int value){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j]=value;
        }
        
    }
    
}
void printMatrix(int rows, int cols, int matrix[rows][cols]){
     for (int i = 0; i < rows; i++)
    {
        printf("\n");
        printf(" ");
        for (int j = 0; j < cols; j++)
        {
            printf("%d",matrix[i][j]);
            if (j+1 != rows)
            {
                printf(" ");
            }
            
        }
        printf(" ");
        
    }
}
void inputMatrix(int rows, int cols, int matrix[rows][cols]){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter element %d %d: ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
}

void copyMatrix(int rows, int cols, int matrix[rows][cols],int copy[rows][cols]){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j]=copy[i][j];
        }
        
    }
}
//!Matrix Arithmetic
void addMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j]=mat1[i][j]+mat2[i][j];
        }
        
    }
    
}
void subtractMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols],int result[rows][cols]){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j]=mat1[i][j]-mat2[i][j];
        }
        
    }
    
}

void multiplyMatrices(int rows1, int cols1, int mat1[rows1][cols1], int rows2, int cols2, int mat2[rows2][cols2], int result[rows1][cols2]){
   
   initializeMatrix(rows1,cols2,result,0);
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            for (int  k= 0; k<cols1 ; k++)
            {
                result[i][j]=result[i][j]+(mat1[i][k]*mat2[k][j]);
            }
            
            
        }
        
    }
    
}

void scalarMultiplyMatrix(int rows, int cols, int matrix[rows][cols], int scalar){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j]=matrix[i][j]*scalar;
        }
        
    }
    
}

//!Matrix Properties and Checks
bool isSquareMatrix(int rows, int cols){
    if (rows==cols) return true;
    return false;
}
bool isIdentityMatrix(int size, int matrix[size][size]){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i==j && matrix[i][j]==1 )  continue;
            
            if (i!=j && matrix[i][j]==0) continue;
            return false;
                        
        }
        
    }
    return true;
}
bool isDiagonalMatrix(int size, int matrix[size][size]){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i!=j && matrix[i][j]!=0) return false;
                        
        }
        
    }
    return true;
}
bool isSymmetricMatrix(int size, int matrix[size][size]){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j]!=matrix[j][i]) return false;
                        
        }
        
    }
    return true;
}

bool isUpperTriangular(int size, int matrix[size][size]){
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (matrix[i][j]!=0) return false;
                        
        }
        
    }
    return true;
}

//!Matrix Operations
void transposeMatrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i]=matrix[i][j];
        }
        
    }
    
}


int determinantMatrix(int size, int matrix[size][size]) {
    if (size == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }
    if (size==1)
    {
        return matrix[0][0];
    }
    
    int temp[size - 1][size - 1];
    int det = 0;


    while (size > 2) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1; j++) {
                temp[i][j] = matrix[i + 1][j + 1];
            }
        }

        int j = 0;
        for (int i = 0; i < size; i++) {
            
            det += pow(-1,i) * matrix[i][j] * determinantMatrix(size - 1, temp);
        }
        
        size--;
    }
    
    return det;
}

void inverseMatrix(int size, double matrix[size][size], double result[size][size]){
    int det =determinantMatrix(size ,matrix);
    double temp[size][size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0;j < size; j++)
        {
          temp[i][j] = pow(-1,i+j)*determinantMatrix(size-1,temp);  
        }
        
    }
    double Adjugate[size][size];
    transposeMatrix(size,size,temp,Adjugate);
    scalarMultiplyMatrix(size,size,Adjugate,1/det);

}

void matrixPower(int size, int matrix[size][size], int power, int result[size][size]){
    if (power==0)
    {
        initializeMatrix(size,size,result,1);
        return;
    }
    if (power==1)
    {
        copyMatrix(size,size,matrix,result);
        return;
    }
    int temp[size][size];
    matrixPower(size,matrix,power/2,temp);
    multiplyMatrices(size,size,temp,size,size,temp,result);
    if (power%2!=0)
    {
        multiplyMatrices(size,size,matrix,size,size,temp,result);
    }
}

//!Advanced Matrix Functions
void cofactorMatrix(int size, int matrix[size][size], int cofactor[size][size]){}
void adjointMatrix(int size, int matrix[size][size], int adjoint[size][size]){}

void luDecomposition(int size, double matrix[size][size], double lower[size][size],double upper[size][size]){}

int matrixRank(int rows, int cols, int matrix[rows][cols]){}

//!Special Matrix Operations
int traceMatrix(int size, int matrix[size][size]){}

void rotateMatrix90(int size, int matrix[size][size]){}

void findEigenvalues(int size, double matrix[size][size],double eigenvalues[size]){}


