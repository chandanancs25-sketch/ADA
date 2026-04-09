#include <stdio.h>

#define MAX 20
#define INF 999

int parent[MAX];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main()
{
    int cost[MAX][MAX];
    int n, i, j;
    int mincost = 0;
    int edge_count = 0;
    int u, v, min;
    int a, b;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    for(i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in MST:\n");

    while(edge_count < n - 1)
    {
        min = INF;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        a = find(u);
        b = find(v);

        if(a != b)
        {
            printf("%d -> %d : %d\n", u, v, min);
            mincost += min;
            unionSet(a, b);
            edge_count++;
        }

        cost[u][v] = cost[v][u] = INF;
    }

    printf("\nMinimum Cost = %d\n", mincost);

    return 0;
}
