#ifndef MATRICES_H
#define MATRICES_H

//!Basic Functions

void initializeMatrix(int rows, int cols, double matrix[rows][cols], int value);

void printMatrix(int rows, int cols, double matrix[rows][cols]);

void inputMatrix(int rows, int cols, int matrix[rows][cols]);

void copyMatrix(int rows, int cols, double matrix[rows][cols],double copy[rows][cols]);

//!Arithmetic on Matrices

void addMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]);

void subtractMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols],int result[rows][cols]);

void multiplyMatrices(int rows1, int cols1, int mat1[rows1][cols1], int rows2, int cols2, int mat2[rows2][cols2], int result[rows1][cols2]);

void scalarMultiplyMatrix(int rows, int cols, double matrix[rows][cols], double scalar);

//!Matrix Properties and Checks
bool isSquareMatrix(int rows, int cols);

bool isIdentityMatrix(int size, int matrix[size][size]);

bool isDiagonalMatrix(int size, int matrix[size][size]);

bool isSymmetricMatrix(int size, int matrix[size][size]);

bool isUpperTriangular(int size, int matrix[size][size]);

bool isEqualMatrix(int rows, int cols,double mat1[rows][cols],double mat2[rows][cols]);

//!Matrix Operations
void transposeMatrix(int rows, int cols, double matrix[rows][cols], double result[cols][rows]);

double determinantMatrix(int size, double matrix[size][size]);

void inverseMatrix(int size, double matrix[size][size], double result[size][size]);

void matrixPower(int size, double matrix[size][size], int power, double result[size][size]);

//!Advanced Matrix Functions
void cofactorMatrix(int size, double matrix[size][size], double cofactor[size][size]);

void adjointMatrix(int size, double matrix[size][size], double adjoint[size][size]);

void luDecomposition(int size, double matrix[size][size], double lower[size][size],double upper[size][size]);

int matrixRank(int rows, int cols, double matrix[rows][cols]);

void reduceRowEchelonForm(int rows, int cols, double matrix[rows][cols]);

void swapRows(int rows,int cols,double mat[rows][cols],int row1,int row2);
void swapElements(double* elem2,double* elem1);

//!Special Matrix Operations
int traceMatrix(int size, int matrix[size][size]);

void rotateMatrix90(int size, double matrix[size][size]);

void reverseRows(int size, double matrix[size][size]);

void findEigenvalues(int size, double matrix[size][size],double eigenvalues[size]);

void findEigenvalues2x2(double matrix[2][2], double eigenvalues[2]);

double dotProduct(double vector1[], double vector2[], int size);

void normalizeVector(double vector[], int size);

void subtractProjection(double vector1[], double vector2[], int size);

void getColumn(int size,double Q[size][size], int col, double colVector[size]);

void gramSchmidt(int size ,double mat[size][size], double Q[size][size]);

#endif 
