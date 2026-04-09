#include <stdio.h>

#define MAX 20
#define INF 9999

int main()
{
    int cost[MAX][MAX], selected[MAX];
    int n, i, j;
    int edge_count = 0;
    int min, u, v;
    int mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;   // no edge
        }
    }

    for(i = 0; i < n; i++)
        selected[i] = 0;

    selected[0] = 1;   // start from vertex 0

    printf("\nEdges in MST:\n");

    while(edge_count < n - 1)
    {
        min = INF;

        for(i = 0; i < n; i++)
        {
            if(selected[i])
            {
                for(j = 0; j < n; j++)
                {
                    if(!selected[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d -> %d : %d\n", u, v, min);

        mincost += min;
        selected[v] = 1;
        edge_count++;
    }

    printf("\nMinimum Cost = %d\n", mincost);

    return 0;
}
