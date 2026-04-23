#include <stdio.h>


float knapsack(int weight[], int profit[], int n, int capacity) {
    float ratio[n];


    for (int i = 0; i < n; i++) {
        ratio[i] = (float)profit[i] / weight[i];
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {

                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;


                int t = profit[i];
                profit[i] = profit[j];
                profit[j] = t;


                t = weight[i];
                weight[i] = weight[j];
                weight[j] = t;
            }
        }
    }

    float total = 0;


    for (int i = 0; i < n; i++) {
        if (capacity >= weight[i]) {
            total += profit[i];
            capacity -= weight[i];
        } else {
            total += profit[i] * ((float)capacity / weight[i]);
            break;
        }
    }

    return total;
}

int main() {
    int capacity, n;

    printf("Enter bag capacity: ");
    scanf("%d", &capacity);

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], profit[n];

    printf("Enter weight and profit:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weight[i], &profit[i]);
    }

    float maxProfit = knapsack(weight, profit, n, capacity);

    printf("Maximum profit = %.2f\n", maxProfit);

    return 0;
}
