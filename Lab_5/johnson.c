#include <stdio.h>

int main() {
    int n, i, j, mobile, pos=0, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n], dir[n];


    for(i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = -1;
    }

    while(1) {

        for(i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        mobile = 0;

        for(i = 0; i < n; i++) {
            if(dir[a[i]-1] == -1 && i != 0 && a[i] > a[i-1])
                if(a[i] > mobile) {
                    mobile = a[i];
                    pos = i;
                }

            if(dir[a[i]-1] == 1 && i != n-1 && a[i] > a[i+1])
                if(a[i] > mobile) {
                    mobile = a[i];
                    pos = i;
                }
        }

        if(mobile == 0)
            break;

        j = pos + dir[mobile-1];

        temp = a[pos];
        a[pos] = a[j];
        a[j] = temp;

        for(i = 0; i < n; i++) {
            if(a[i] > mobile)
                dir[a[i]-1] *= -1;
        }
    }

    return 0;
}
