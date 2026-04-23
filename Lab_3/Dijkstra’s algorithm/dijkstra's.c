#include <stdio.h>

#define MAX 10
#define INF 999

int cost[MAX][MAX], dist[MAX], visited[MAX];
int n, src;

void dijkstra()
{
    int i, j, count = 1, min, u;

    // Initialize distances and visited array
    for (i = 1; i <= n; i++)
    {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }

    dist[src] = 0;
    visited[src] = 1;

    while (count < n)
    {
        min = INF;

        // Find the nearest unvisited node
        for (i = 1; i <= n; i++)
        {
            if (dist[i] < min && !visited[i])
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // Update distances of adjacent vertices
        for (i = 1; i <= n; i++)
        {
            if (!visited[i] && (dist[u] + cost[u][i] < dist[i]))
            {
                dist[i] = dist[u] + cost[u][i];
            }
        }

        count++;
    }
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);

            // Replace 0 with INF (no direct edge)
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra();

    printf("\nShortest paths from vertex %d:\n", src);
    for (i = 1; i <= n; i++)
    {
        printf("%d -> %d = %d\n", src, i, dist[i]);
    }

    return 0;
}
