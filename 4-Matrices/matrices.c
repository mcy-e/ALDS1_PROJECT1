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
            matrix[i][j]=value;//*give the value to the matrix ;)
        }
        
    }
    
}
void printMatrix(int rows, int cols, double matrix[rows][cols]){
     for (int i = 0; i < rows; i++)
    {
        printf("\n");//*spereat every row
        printf(" ");//*separate first columns
        for (int j = 0; j < cols; j++)
        {
            printf("%f",matrix[i][j]);
            if (j+1 != rows)
            {
                printf(" ");//*stops when we reach the number of rows
            }
            
        }
        printf(" ");//*spereat every row
        
    }
}
void inputMatrix(int rows, int cols, int matrix[rows][cols]){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter element %d %d: ",i,j);
            scanf("%d",&matrix[i][j]);//*scan the input
        }
    }
}

void copyMatrix(int rows, int cols, double matrix[rows][cols],double copy[rows][cols]){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            copy[i][j]=matrix[i][j];//*copy the matrix
        }
        
    }
}
//!Matrix Arithmetic
void addMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j]=mat1[i][j]+mat2[i][j];//*apply the mathematical law
        }
        
    }
    
}
void subtractMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols],int result[rows][cols]){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j]=mat1[i][j]-mat2[i][j];//*apply the mathematical law
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
                result[i][j]=result[i][j]+(mat1[i][k]*mat2[k][j]);//*apply the mathematical law of multuplying two matrices
            }
            
            
        }
        
    }
    
}

void scalarMultiplyMatrix(int rows, int cols, double matrix[rows][cols], double scalar){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j]=matrix[i][j]*scalar;//*apply the mathematical law
        }
        
    }
    
}

//!Matrix Properties and Checks
bool isSquareMatrix(int rows, int cols){
    if (rows==cols) return true;//*is a square  the number of rows is the same as the number of cols
    return false;
}
bool isIdentityMatrix(int size, int matrix[size][size]){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i==j && matrix[i][j]==1 )  continue;//*diagonal element must be one 
            
            if (i!=j && matrix[i][j]==0) continue;//*the rest must be zero
            return false;//*otherwise case if 1st  is false and 2nd is false then return false
                        
        }
        
    }
    return true;//*complete checking 
}
bool isDiagonalMatrix(int size, int matrix[size][size]){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i!=j && matrix[i][j]!=0) return false;//*it's obvious
                        
        }
        
    }
    return true;//*complete checking with no problems
}
bool isSymmetricMatrix(int size, int matrix[size][size]){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j]!=matrix[j][i]) return false;//*isn't symmetric "متناظرة"
                        
        }
        
    }
    return true;//*complete checking with no problems
}

bool isUpperTriangular(int size, int matrix[size][size]){
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (matrix[i][j]!=0) return false;//*isn't upper triangular
                        
        }
        
    }
    return true;//*complete checking with no problems
}

bool isEqualMatrix(int rows, int cols,double mat1[rows][cols],double mat2[rows][cols]){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat1[i][j]!=mat2[i][j]) return false;
                        
        }
        
    }
    return true;//*complete checking with no problems
}

//!Matrix Operations
void transposeMatrix(int rows, int cols, double matrix[rows][cols], double result[cols][rows]){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i]=matrix[i][j];//*transposing the matrix
        }
        
    }
    
}




double determinantMatrix(int size, double matrix[size][size]) {
    if (size == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);//*the law for 2 by 2 matrix to ge the det
    }
    if (size == 1) {
        return matrix[0][0];//*in cas of 1 by 1 matrice
    }
  //*treating other cases when size is bigger then 2
    double temp[size - 1][size - 1];//*creat submatrix of the main matrix
    double det = 0;//*initialize beacause we're going to sum

    for (int j = 0; j < size; j++) {
        int sub_i = 0;
        for (int i = 1; i < size; i++) {
            int sub_j = 0;
            for (int k = 0; k < size; k++) {
                if (k == j) {
                    continue;
                }
                temp[sub_i][sub_j] = matrix[i][k];//*fill the temporary with the matrix we're just applying the mathematical formula ie we're not inventing a new science 
                //*just check the law and you will get it if you didn't
                sub_j++;
            }
            sub_i++;
        }
        double sign = 1;
        if (j % 2 != 0) {
            sign = -1;//*just applying the formula nothing new
        }
        det +=  matrix[0][j] * determinantMatrix(size - 1, temp);//*the recursive call because according to the "formula" we should get the determinant of the sub matrix generated
    }

    return det;//*returns the value
}


void inverseMatrix(int size, double matrix[size][size], double result[size][size]){
    int det =determinantMatrix(size ,matrix);//*steps to find the inverse of a matrix
    double temp[size][size];//*to calculate the cofactor matrix i know i made a procedure for that but i wrote this before making the function so stay calm
    //*and in case you're guessing i edited this comment
    for (int i = 0; i < size; i++)
    {
        for (int j = 0;j < size; j++)
        {
          temp[i][j] = pow(-1,i+j)*determinantMatrix(size-1,temp);//*the cofactor matrix  
        }
        
    }
    double Adjugate[size][size];
    transposeMatrix(size,size,temp,Adjugate);//*transpose the cofactor to get the adjugate
    scalarMultiplyMatrix(size,size,Adjugate,1/det);//*multiply the adjugate by the 1/det determined earlier and voila we get the inverse 
    copyMatrix(size,size,Adjugate,result);//*copy the result from the updated adjugate matrix 
}

void matrixPower(int size, double matrix[size][size], int power, double result[size][size]) {
    if (power == 0) {
        initializeMatrix(size, size, result, 1);//*case 0
        return;
    }
    if (power == 1) {
        copyMatrix(size, size, matrix, result);//*base case
        return;//*to force the procedure to stop and don't take in mind the below operations
    }

    double temp[size][size];
    double tempResult[size][size];
    matrixPower(size, matrix, power / 2, temp);//*the recursive call  the function will call itself recursively until pow is 1 so it passes to next step 
    multiplyMatrices(size, size, temp, size, size, temp, tempResult);//*then multiply the resulted by itself and copy it to result

    if (power % 2 != 0) multiplyMatrices(size, size, tempResult, size, size, matrix, result);//*in case of odd power we remuliply the matrix by the result
    if (power%2==0)  copyMatrix(size,size,tempResult,result);//*else
    
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

                    temp[sub_i][sub_j] = matrix[i][j];//*same approach as above but we skip the diagonal elements because that's the law
                    sub_j++;
                }
                sub_i++;
            }
           

            double sign = 1;
            if ((row + col) % 2 != 0) {
                sign = -1;//*the same as pow(-1, row+col)
            }
           
            cofactor[row][col] = sign * determinantMatrix(size - 1, temp);//*filling the matrix
        }
    }
}

 
void adjointMatrix(int size, double matrix[size][size], double adjoint[size][size]){
    double temp[size][size];//*to store the cofactor matrix
    cofactorMatrix(size, matrix, temp);
    transposeMatrix(size, size, temp, adjoint);//*we get the adjoint matrix
}

void luDecomposition(int size, double matrix[size][size], double lower[size][size], double upper[size][size]) {
    initializeMatrix(size, size, upper, 0);
    initializeMatrix(size, size, lower, 0);

    for (int i = 0; i < size; i++) {
        lower[i][i] = 1;
    }//*identity matrix

   
    
    for (int k = 0; k < size; k++) {
        for (int j = k; j < size; j++) {
            double sum = 0;
            for (int p = 0; p < k; p++) {
                sum += lower[k][p] * upper[p][j];//*following the formula
            }
            upper[k][j] = matrix[k][j] - sum;//*following the formula
        }
        
        
    } //*we get the upper diagonal matrix

    for (int k = 0; k < size; k++) {
        for (int i = k + 1; i < size; i++) {
            double sum = 0;
            for (int p = 0; p < k; p++) {
                sum += lower[i][p] * upper[p][k];
            }
            lower[i][k] = (matrix[i][k] - sum) / upper[k][k];//*same talk as above
        }

      
    }
    printf("\n upper matrix: \n");//*we print
    printMatrix(size, size, upper);
    printf("\n lower matrix: \n");
    printMatrix(size, size, lower);
}



int matrixRank(int rows, int cols, double matrix[rows][cols]){
    int rank=0;
    
    reduceRowEchelonForm(rows,cols,matrix);//*recommended  method to get the rank of the matrix
    
    for (int i = 0; i < rows; i++)
    {
        bool found =false;
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j]==0)
            {
                found=true;//*we look for rows the don't has  in it
                break;
            }
            
        }
        if (!found) rank++;//*we didn't find them so the rank is the number of rows that don't has  in it after reduce Row using Echelon Form
        
    }
    
    return rank;//*what you would expect
}

void reduceRowEchelonForm(int rows, int cols, double matrix[rows][cols]) {
    int col = 0;
    for (int k = 0; k < rows; k++) {
        
        int pivotRow = k;
        while (pivotRow < rows && matrix[pivotRow][col] == 0) {
            pivotRow++;//*it adds untill we get none element it may be the first or the seconde or none of them
        }
        //*we fix the column and look for rows with no  element
        if (pivotRow == rows) {
            col++;//*means  we scanned whole row and didn't find a non zero element
            k--;//*we reduce it to don't skip a row
            continue;//*go to next column and find the none zero element
        }

        if (pivotRow != k) {
            swapRows(rows, cols, matrix, k, pivotRow);//*in case the none zero element is not in the same row we swap the whole row
        }

        double pivot = matrix[k][col];
        for (int j = 0; j < cols; j++) {
            matrix[k][j] = matrix[k][j]/pivot;//*formula
        }

        for (int i = k + 1; i < rows; i++) {
            double factor = matrix[i][col];
            for (int j = 0; j < cols; j++) {
                matrix[i][j] -= factor * matrix[k][j];//*formula
            }
        }

        col++;//*means we end up with the first col move to next
    }
}

void swapRows(int rows, int cols, double mat[rows][cols], int row1, int row2) {
    for (int j = 0; j < cols; j++) {
        double temp = mat[row1][j];//*swap the rwo1 with row2
        mat[row1][j] = mat[row2][j];
        mat[row2][j] = temp;//*doesn't need an explanation it's obvious
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
        sum+=matrix[i][i];//*the sum of diagonal elemets
        
    }
    return sum;//*return the sum of diagonal elemets
}

void rotateMatrix90(int size, double matrix[size][size]){
    double temp[size][size];
    transposeMatrix(size,size,matrix,temp);//*transpose the matrix
    reverseRows(size,temp);//*reverse it's ros 
    
    
    copyMatrix(size,size,temp,matrix);//*and you get your rotated matrix
}

void reverseRows(int size, double matrix[size][size]){
    for (int i=0;i<size;i++){
        for (int j = 0; j <= size/2; j++)
        {
            double temp1=matrix[i][j];
            matrix[i][j]=matrix[i][size-1-j];//*the same approach as in an array the rows are fixed
            matrix[i][size-1-j]=temp1;

        }
        
    }
}


void findEigenvalues(int size, double matrix[size][size],double eigenvalues[size]){
    
    //ToDO i will solve it using QR algorithm or any other fast and efficient algorithm for now i use this unless method until i get the time
    //?GUESS WHAT?...
   /*double identity[size][size];
    int track=0;
    initializeMatrix(size,size,identity,0);
    for (int i = 0; i < size; i++)
    {
        identity[i][i] = 1;//*identity matrix
    }
    double lambda;//*the egigen value
    double diff[size][size];//*diffrence matrix of the matrix - the identity multiplied by lambda
    double scalarMatrix[size][size];
    for ( lambda =-10; lambda < 10; lambda+=0.1)//*there was a better approach but i will try brut force although it's not recommended
    {
        scalarMultiplyMatrix(size,size,identity,lambda);
        subtractMatrices(size,size,matrix,identity,diff);
        double det = determinantMatrix(size,diff);//*det of the diff matrix 
        if (fabs(det)<0.0001)//*solve for lambda
        { 
            eigenvalues[track]=lambda;//*lambda is a solution we add it to the engin values array
            track++;
            
        }
        
    }
    */
   bool stop=false;
   double upper[size][size];
   double Q[size][size];
   double checker=1e-6;//* instead off 10^-6 
   while (!stop)
   {
     upperTriangle(size,matrix,upper);//*get the upper triangle matrix
     gram_schmidt(size,matrix,Q);//*get the ortho something  matrix (i dont' know how to say it)
     multiplyMatrices(size,size,upper,size,size,Q,matrix);//*multiply the upper triangle by the ortho something matrix and assign to our matrix so we will update the value of our matrix 

        for (int i = 0; i < size; i++) 
            for (int j = 0; j < size; j++)
                if (i!=j && matrix[i][j]<checker) stop=true;//*stop the loop  //*check if the matrix is diagonal
            
                
    }

    for (int i = 0; i < size; i++) eigenvalues[i]=matrix[i][i];//*get the eigen values
    
}
void upperTriangle(int size, double matrix[size][size], double upper[size][size]){
    double lower[size][size];
    initializeMatrix(size, size, upper, 0);
    initializeMatrix(size, size, lower, 0);

    for (int i = 0; i < size; i++) {
        lower[i][i] = 1;
    }//*identity matrix

   
    
    for (int k = 0; k < size; k++) {
        for (int j = k; j < size; j++) {
            double sum = 0;
            for (int p = 0; p < k; p++) {
                sum += lower[k][p] * upper[p][j];//*following the formula
            }
            upper[k][j] = matrix[k][j] - sum;//*following the formula
        }
        
        
    } //*we get the upper diagonal matrix
    
}
void findEigenvalues2x2(double matrix[2][2], double eigenvalues[2]) {
    //*a simpler approach using 2 by 2 matrice
    double trace = matrix[0][0] + matrix[1][1];//*trcing the matrix i can call the function but why save some time
    double det = determinantMatrix(2,matrix);//*finding the det
    double discriminant = trace * trace - 4 * det;//*apply the formula

    if (discriminant < 0) {
        eigenvalues[0] = eigenvalues[1] = -1; //*error a complex eignvalues
        return;
    }

    eigenvalues[0] = (trace + sqrt(discriminant)) / 2;//*else we apply the formula and solve for lambda a and 2
    eigenvalues[1] = (trace - sqrt(discriminant)) / 2;
}



double dotProduct(double vector1[], double vector2[], int size) {
    double dot = 0;
    for (int i = 0; i < size; i++) {
        dot += vector1[i] * vector2[i];//*compute dot product of two vectors that's the law
    }
    return dot;
}



void normalizeVector(double vector[], int size) {
    double norm = 0;
    for (int i = 0; i < size; i++) {
        norm += vector[i] * vector[i];//*compute the norm of the vector according to the law
    }
    norm = sqrt(norm);

    for (int i = 0; i < size; i++) {
        vector[i] /= norm;//*normalizing every element in the vector
    }
}


void subtractProjection(double vector1[], double vector2[], int size) {
    double scale = dotProduct(vector1, vector2, size);
    for (int i = 0; i < size; i++) {
        vector1[i] -= scale * vector2[i];
    }
}

void getColumn(int size,double Q[size][size], int col, double colVector[size]) {
    for (int i = 0; i < size; i++) {
        colVector[i] = Q[i][col];  //*get the column of the matrix
    }
}

void gramSchmidt(int size ,double mat[size][size], double Q[size][size]) {
   initializeMatrix(size,size,Q,0);
    for (int j = 0; j < size; j++) {

        double vector[size];
        for (int i = 0; i < size; i++) {
            vector[i] = mat[i][j];//*copy column j of mat to a vector
        }

        
        for (int k = 0; k < j; k++) {
            double colVector[size];
            getColumn(size,Q, k, colVector);//*get the column of the Q matrix
            subtractProjection(vector, colVector, size);//*subtract projections onto previous orthogonal vectors
        }

        
        normalizeVector(vector, size);//*normalize vector :)

       
        for (int i = 0; i < size; i++) {
            Q[i][j] = vector[i]; //*paste to the Q matrix
        }
    }
}




