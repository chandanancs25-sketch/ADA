#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }


    int w = W;
    int selected[n];
    int count = 0;

    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            selected[count++] = i-1;
            w -= wt[i-1];
        }
    }

    printf("Maximum value in knapsack = %d\n", dp[n][W]);
    printf("Number of items selected = %d\n", count);
    printf("Items selected (0-based index): ");
    for (int i = count-1; i >= 0; i--)
        printf("%d ", selected[i]);
    printf("\n");

    return dp[n][W];
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];
    printf("Enter Profits of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    knapsack(W, wt, val, n);

    return 0;
}
