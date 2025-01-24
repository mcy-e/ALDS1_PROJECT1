#ifndef MATRICES_H
#define MATRICES_H

//!Basic Functions

void initializeMatrix(int rows, int cols, int matrix[rows][cols], int value);

void printMatrix(int rows, int cols, int matrix[rows][cols]);

void inputMatrix(int rows, int cols, int matrix[rows][cols]);

void copyMatrix(int rows, int cols, int matrix[rows][cols],int copy[rows][cols]);

//!Arithmetic on Matrices

void addMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]);

void subtractMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols],int result[rows][cols]);

void multiplyMatrices(int rows1, int cols1, int mat1[rows1][cols1], int rows2, int cols2, int mat2[rows2][cols2], int result[rows1][cols2]);

void scalarMultiplyMatrix(int rows, int cols, int matrix[rows][cols], int scalar);

//!Matrix Properties and Checks
bool isSquareMatrix(int rows, int cols);

bool isIdentityMatrix(int size, int matrix[size][size]);

bool isDiagonalMatrix(int size, int matrix[size][size]);

bool isSymmetricMatrix(int size, int matrix[size][size]);

bool isUpperTriangular(int size, int matrix[size][size]);

//!Matrix Operations
void transposeMatrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]);

int determinantMatrix(int size, int matrix[size][size]);

void inverseMatrix(int size, double matrix[size][size], double result[size][size]);

void matrixPower(int size, int matrix[size][size], int power, int result[size][size]);

//!Advanced Matrix Functions
void cofactorMatrix(int size, int matrix[size][size], int cofactor[size][size]);

void adjointMatrix(int size, int matrix[size][size], int adjoint[size][size]);

void luDecomposition(int size, double matrix[size][size], double lower[size][size],double upper[size][size]);

int matrixRank(int rows, int cols, int matrix[rows][cols]);

//!Special Matrix Operations
int traceMatrix(int size, int matrix[size][size]);

void rotateMatrix90(int size, int matrix[size][size]);

void findEigenvalues(int size, double matrix[size][size],double eigenvalues[size]);

#endif 
