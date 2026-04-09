// Merge Sort: Sorting (small n) + Time Analysis (large n)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

int arr[MAX], temp[MAX];

// Function declarations
void mergesort(int low, int high);
void merge(int low, int mid, int high);

int main()
{
    int i, n;
    clock_t start, end;
    double time_taken;

    srand(time(NULL));

    // ----------- PART 1: Sorting for small n -----------
    printf("Sorting for small number of elements\n");
    printf("-----------------------------------\n");

    printf("Enter number of elements (small n): ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergesort(0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // ----------- PART 2: Time analysis for large n -----------
    printf("\n\nTime Analysis for large inputs\n");
    printf("-----------------------------------\n");
    printf("   n\t\tTime (seconds)\n");

    for (n = 10000; n <= 50000; n += 10000)
    {
        // Generate random numbers
        for (i = 0; i < n; i++)
        {
            arr[i] = rand() % 10000;
        }

        start = clock();

        mergesort(0, n - 1);

        end = clock();

        time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%6d\t\t%f\n", n, time_taken);
    }

    return 0;
}

// Merge Sort
void mergesort(int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        mergesort(low, mid);
        mergesort(mid + 1, high);
        merge(low, mid, high);
    }
}

// Merge function
void merge(int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}