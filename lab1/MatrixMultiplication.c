#include <stdio.h>

#define MAX_SIZE 10

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
int multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int r1, int c1, int r2, int c2);

int main() {
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int r1, c1, r2, c2;

    // Read dimensions and matrices
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);
    readMatrix(mat1, r1, c1);
    
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &r2, &c2);
    readMatrix(mat2, r2, c2);

    // Check compatibility
    if (c1 != r2) {
        printf("Matrices cannot be multiplied. Incompatible dimensions.\n");
        return 1;
    }

    // Multiply matrices
    multiplyMatrices(mat1, mat2, result, r1, c1, r2, c2);

    // Display results
    printf("First Matrix:\n");
    displayMatrix(mat1, r1, c1);
    printf("Second Matrix:\n");
    displayMatrix(mat2, r2, c2);
    printf("Product of the matrices:\n");
    displayMatrix(result, r1, c2);

    return 0;
}

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0; // Initialize the result matrix element
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return 0; // Indicate successful multiplication
}
