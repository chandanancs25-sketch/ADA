#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void mergesort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);

int main()
{
    int n, i;
    int a[20000];
    clock_t start, end;
    double time_taken;

    printf("N\tTime (seconds)\n");

    // Run for different values of N
    for(n = 1000; n <= 10000; n += 1000)
    {
        // Generate random array
        for(i = 0; i < n; i++)
        {
            a[i] = rand() % 10000;
        }

        // Start time
        start = clock();

        mergesort(a, 0, n - 1);

        // End time
        end = clock();

        // Calculate time
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Print result
        printf("%d\t%f\n", n, time_taken);
    }

    return 0;
}

void mergesort(int a[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int c[20000];

    i = low;
    j = mid + 1;
    k = low;

    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }

    while(i <= mid)
        c[k++] = a[i++];

    while(j <= high)
        c[k++] = a[j++];

    for(i = low; i <= high; i++)
        a[i] = c[i];
}
