#include <stdio.h>

int greedyCoinChange(int coins[], int n, int amount) {
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
            printf("%d ", coins[i]);  // Print the coin used
        }
    }
    printf("\n");  // New line after printing coins used
    return count;
}

int main() {
    int coins[] = {1, 3, 4}; // Coin denominations
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount;

    printf("Enter the target amount: ");
    scanf("%d", &amount);

    printf("Coins used by greedy approach: ");
    int count = greedyCoinChange(coins, n, amount);
    printf("Total coins used: %d\n", count);

    return 0;
}
