#include <stdio.h>
#include <conio.h>

int a[10], n;

void qsort(int a[], int low, int high);
int partition(int a[], int low, int high);

void main()
{
    int i;

    printf("Enter number of elements:\n");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    qsort(a, 0, n - 1);

    printf("Sorted elements are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    getch();
}

// Quick Sort function
void qsort(int a[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = partition(a, low, high);
        qsort(a, low, mid - 1);
        qsort(a, mid + 1, high);
    }
}

// Partition function
int partition(int a[], int low, int high)
{
    int i, j, temp, pivot;

    pivot = a[low];
    i = low + 1;
    j = high;

    while(i <= j)
    {
        while(a[i] <= pivot)
        {
            i++;
        }

        while(a[j] > pivot)
        {
            j--;
        }

        if(i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}