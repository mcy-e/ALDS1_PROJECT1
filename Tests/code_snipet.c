#include <stdio.h>

void initializeMatrix(int rows, int cols, int matrix[rows][cols], int value) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (i == j) ? value : 0;
        }
    }
}

void copyMatrix(int rows, int cols, int source[rows][cols], int destination[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            destination[i][j] = source[i][j];
        }
    }
}

void multiplyMatrices(int rowsA, int colsA, int A[rowsA][colsA], int rowsB, int colsB, int B[rowsB][colsB], int result[rowsA][colsB]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrixPower(int size, int matrix[size][size], int power, int result[size][size]) {
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

int main() {
    int matrix[2][2] = {{1, 1}, {4, 5}};
    int result[2][2];
    int power = 2;

    matrixPower(2, matrix, power, result);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
