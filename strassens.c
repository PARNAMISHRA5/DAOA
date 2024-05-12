#include <stdio.h>
#include <stdlib.h>
void matrixAdd(int n, int A[][n], int B[][n], int C[][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}
void matrixSubtract(int n, int A[][n], int B[][n], int C[][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}
void strassen(int n, int A[][n], int B[][n], int C[][n])
{
    if (n <= 64)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                C[i][j] = 0;
                for (int k = 0; k < n; k++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return;
    }
    int newSize = n / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize],
        A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize],
        B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize],
        C22[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }
    matrixAdd(newSize, A11, A22, temp1);
    matrixAdd(newSize, B11, B22, temp2);
    strassen(newSize, temp1, temp2, C11);
    matrixAdd(newSize, A21, A22, temp1);
    strassen(newSize, temp1, B11, C12);
    matrixSubtract(newSize, B12, B22, temp1);
    strassen(newSize, A11, temp1, C21);
    matrixSubtract(newSize, B21, B11, temp1);
    strassen(newSize, A22, temp1, C22);
    matrixAdd(newSize, A11, A12, temp1);
    strassen(newSize, temp1, B22, C21);
    matrixSubtract(newSize, A21, A11, temp1);
    matrixAdd(newSize, B11, B12, temp2);
    strassen(newSize, temp1, temp2, C22);
    matrixSubtract(newSize, A12, A22, temp1);
    matrixAdd(newSize, B21, B22, temp2);
    strassen(newSize, temp1, temp2, C11);
    matrixAdd(newSize, C11, C22, temp1);
    matrixSubtract(newSize, temp1, C12, temp2);
    matrixAdd(newSize, temp2, C21, C);
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}
void printMatrix(int n, int matrix[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter the size of the square matrices: ");
    scanf("%d", &n);
    int A[n][n], B[n][n], C[n][n];
    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);
    strassen(n, A, B, C);
    printf("Matrix A:\n");
    printMatrix(n, A);
    printf("Matrix B:\n");
    printMatrix(n, B);
    printf("Matrix C (result of A * B using Strassen's algorithm):\n");
    printMatrix(n, C);
    return 0;
}
