#include<stdbool.h>
#include<math.h>
#include<stdio.h>
#include "../lib/mainlib.h"
#include<limits.h>
//& MAKE SURE TO INSTALL BETTER COMMENTS EXTENSION IF YOU ARE IN VS CODE FOR BETTER READABILITY 

//!Basic Functions
void initializeMatrix(int rows, int cols, double matrix[rows][cols], int value){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j]=value;
        }
        
    }
    
}
void printMatrix(int rows, int cols, double matrix[rows][cols]){
     for (int i = 0; i < rows; i++)
    {
        printf("\n");
        printf(" ");
        for (int j = 0; j < cols; j++)
        {
            printf("%f",matrix[i][j]);
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

void copyMatrix(int rows, int cols, double matrix[rows][cols],double copy[rows][cols]){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            copy[i][j]=matrix[i][j];
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

void scalarMultiplyMatrix(int rows, int cols, double matrix[rows][cols], double scalar){
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

bool isEqualMatrix(int rows, int cols,double mat1[rows][cols],double mat2[rows][cols]){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat1[i][j]!=mat2[i][j]) return false;
                        
        }
        
    }
    return true;
}

//!Matrix Operations
void transposeMatrix(int rows, int cols, double matrix[rows][cols], double result[cols][rows]){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i]=matrix[i][j];
        }
        
    }
    
}




double determinantMatrix(int size, double matrix[size][size]) {
    if (size == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }
    if (size == 1) {
        return matrix[0][0];
    }

    double temp[size - 1][size - 1];
    double det = 0;

    for (int j = 0; j < size; j++) {
        int sub_i = 0;
        for (int i = 1; i < size; i++) {
            int sub_j = 0;
            for (int k = 0; k < size; k++) {
                if (k == j) {
                    continue;
                }
                temp[sub_i][sub_j] = matrix[i][k];
                sub_j++;
            }
            sub_i++;
        }
        double sign = 1;
        if (j % 2 != 0) {
            sign = -1;
        }
        det +=  matrix[0][j] * determinantMatrix(size - 1, temp);
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

void matrixPower(int size, double matrix[size][size], int power, double result[size][size]) {
    if (power == 0) {
        initializeMatrix(size, size, result, 1);
        return;
    }
    if (power == 1) {
        copyMatrix(size, size, matrix, result);
        return;
    }

    int temp[size][size];
    
    matrixPower(size, matrix, power / 2, temp);
    multiplyMatrices(size, size, temp, size, size, temp, result);

    if (power % 2 != 0) {
        multiplyMatrices(size, size, result, size, size, matrix, result);
    }
}


//!Advanced Matrix Functions
void cofactorMatrix(int size, double matrix[size][size], double cofactor[size][size]) {
    double temp[size - 1][size - 1];

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            int sub_i = 0;

            for (int i = 0; i < size; i++) {
                if (i == row) continue;

                int sub_j = 0;
                for (int j = 0; j < size; j++) {
                    if (j == col) continue;

                    temp[sub_i][sub_j] = matrix[i][j];
                    sub_j++;
                }
                sub_i++;
            }
           

            double sign = 1;
            if ((row + col) % 2 != 0) {
                sign = -1;
            }
           
            cofactor[row][col] = sign * determinantMatrix(size - 1, temp);
        }
    }
}

 
void adjointMatrix(int size, double matrix[size][size], double adjoint[size][size]){
    double temp[size][size];
    cofactorMatrix(size, matrix, temp);
    transposeMatrix(size, size, temp, adjoint);
}

void luDecomposition(int size, double matrix[size][size], double lower[size][size], double upper[size][size]) {
    initializeMatrix(size, size, upper, 0);
    initializeMatrix(size, size, lower, 0);

    for (int i = 0; i < size; i++) {
        lower[i][i] = 1;
    }

   
    
    for (int k = 0; k < size; k++) {
        for (int j = k; j < size; j++) {
            double sum = 0;
            for (int p = 0; p < k; p++) {
                sum += lower[k][p] * upper[p][j];
            }
            upper[k][j] = matrix[k][j] - sum;
        }
        
        
    }

    for (int k = 0; k < size; k++) {
        for (int i = k + 1; i < size; i++) {
            double sum = 0;
            for (int p = 0; p < k; p++) {
                sum += lower[i][p] * upper[p][k];
            }
            lower[i][k] = (matrix[i][k] - sum) / upper[k][k];
        }

      
    }
    printf("\nUper matrix:\n");
    printMatrix(size, size, upper);
    printf("\nLower matrix:\n");
    printMatrix(size, size, lower);
}



int matrixRank(int rows, int cols, double matrix[rows][cols]){
    int rank=0;
    
    reduceRowEchelonForm(rows,cols,matrix);
    
    for (int i = 0; i < rows; i++)
    {
        bool found =false;
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j]==0)
            {
                found=true;
                break;
            }
            
        }
        if (!found) rank++;
        
    }
    
    return rank;
}

void reduceRowEchelonForm(int rows, int cols, double matrix[rows][cols]) {
    int col = 0;
    for (int k = 0; k < rows; k++) {
        
        int pivotRow = k;
        while (pivotRow < rows && matrix[pivotRow][col] == 0) {
            pivotRow++;
        }
        
        if (pivotRow == rows) {
            col++;
            k--;
            continue;
        }

        if (pivotRow != k) {
            swapRows(rows, cols, matrix, k, pivotRow);
        }

        double pivot = matrix[k][col];
        for (int j = 0; j < cols; j++) {
            matrix[k][j] = matrix[k][j]/pivot;
        }

        for (int i = k + 1; i < rows; i++) {
            double factor = matrix[i][col];
            for (int j = 0; j < cols; j++) {
                matrix[i][j] -= factor * matrix[k][j];
            }
        }

        col++;
    }
}

void swapRows(int rows, int cols, double mat[rows][cols], int row1, int row2) {
    for (int j = 0; j < cols; j++) {
        double temp = mat[row1][j];
        mat[row1][j] = mat[row2][j];
        mat[row2][j] = temp;
    }
}

void swapElements(double* elem2,double* elem1){
    double tmp=*elem1;
    *elem1=*elem2;
    *elem2=tmp;
}

//!Special Matrix Operations
int traceMatrix(int size, int matrix[size][size]){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=matrix[i][i];
        
    }
    return sum;
}

void rotateMatrix90(int size, double matrix[size][size]){
    double temp[size][size];
    transposeMatrix(size,size,matrix,temp);
    reverseRows(size,temp);
    
    
    copyMatrix(size,size,temp,matrix);
}

void reverseRows(int size, double matrix[size][size]){
    for (int i=0;i<size;i++){
        for (int j = 0; j <= size/2; j++)
        {
            double temp1=matrix[i][j];
            matrix[i][j]=matrix[i][size-1-j];
            matrix[i][size-1-j]=temp1;

        }
        
    }
}

void findEigenvalues(int size, double matrix[size][size],double eigenvalues[size]){
    
    //ToDO i will solve it using QR algorithm or any other fast and efficient algorithm for now i use this unless method until i get the time
    double identity[size][size];
    int track=0;
    initializeMatrix(size,size,identity,0);
    for (int i = 0; i < size; i++)
    {
        identity[i][i] = 1;
    }
    double lambda;
    double diff[size][size];
    double scalarMatrix[size][size];
    for ( lambda =-10; lambda < 10; lambda+=0.1)
    {
        scalarMultiplyMatrix(size,size,identity,lambda);
        subtractMatrices(size,size,matrix,identity,diff);
        double det = determinantMatrix(size,diff);
        if (fabs(det)<0.0001)
        { 
            eigenvalues[track]=lambda;
            track++;
            
        }
        
    }
    


}

void findEigenvalues2x2(double matrix[2][2], double eigenvalues[2]) {
    double trace = matrix[0][0] + matrix[1][1];
    double det = determinantMatrix(2,matrix);
    double discriminant = trace * trace - 4 * det;

    if (discriminant < 0) {
        eigenvalues[0] = eigenvalues[1] = -1; 
        return;
    }

    eigenvalues[0] = (trace + sqrt(discriminant)) / 2;
    eigenvalues[1] = (trace - sqrt(discriminant)) / 2;
}




