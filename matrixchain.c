#include <stdio.h>
void main()
{
    int i, j, k;
    int check = 1;
    int seq[] = {2, 3, 4, 2};
    int n = sizeof(seq) / sizeof(seq[0]);
    int C[n][n];
    int P[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = 0;
            P[i][j] = 0;
        }
    }
    printf("Optimal Parenthesis Matrix:\n");
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i && j < n; j++)
        {
            int min = 10000;
            for (k = j; k < j + i; k++)
            {
                if (min > C[j][k] + C[k + 1][j + i] + seq[j - 1] * seq[k] * seq[j + i])
                {
                    min = C[j][k] + C[k + 1][j + i] + seq[j - 1] * seq[k] * seq[j + i];
                    P[j][j + i] = k;
                }
            }
            C[j][j + i] = min;
        }
    }
    printf("\nCost Matrix:\n");
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            printf("%d \t", C[i][j]);
        }
        printf("\n");
    }
    printf("\nOptimal Parenthesis Matrix:\n");
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            printf("%d \t", P[i][j]);
        }
        printf("\n");
    }
}