#include <stdio.h>
#include <stdlib.h>

#define N 4

int getInvCount(int *arr)
{
    int inv_count = 0;
    for (int i = 0; i < N * N - 1; i++)
    {
        for (int j = i + 1; j < N * N; j++)
        {
            if (arr[j] && arr[i] && arr[i] > arr[j])
                inv_count++;
        }
    }
    return inv_count;
}

int findXPosition(int puzzle[N][N])
{
    for (int i = N - 1; i >= 0; i--)
        for (int j = N - 1; j >= 0; j--)
            if (puzzle[i][j] == 0)
                return N - i;
}

int isSolvable(int puzzle[N][N])
{
    int invCount = getInvCount((int *)puzzle);
    if (N & 1)
        return !(invCount & 1);
    else
    {
        int pos = findXPosition(puzzle);
        if (pos & 1)
            return !(invCount & 1);
        else
            return invCount & 1;
    }
}

int getManhattanDistance(int value, int row, int col)
{
    if (value == 0)
        return 0;
    int goalRow = (value - 1) / N;
    int goalCol = (value - 1) % N;
    return abs(row - goalRow) + abs(col - goalCol);
}

int calculateTotalCost(int puzzle[N][N])
{
    int totalCost = 0;
    totalCost += getInvCount((int *)puzzle);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            totalCost += getManhattanDistance(puzzle[i][j], i, j);
    return totalCost;
}

int main()
{
    int puzzle[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 0, 8},
        {9, 10, 7, 11},
        {13, 14, 15, 12},
    };

    if (!isSolvable(puzzle))
    {
        printf("Not Solvable\n");
        return 0;
    }

    int totalCost = calculateTotalCost(puzzle);
    printf("Total Cost: %d\n", totalCost);
    return 0;
}
