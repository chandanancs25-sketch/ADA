#include <stdio.h>
#define MAX 10

int adj[MAX][MAX], indeg[MAX], n;

void topoSort() {
    int deg[MAX], visited[MAX] = {0}, order[MAX], cnt = 0;

    for (int i = 0; i < n; i++) deg[i] = indeg[i];

    while (cnt < n) {
        int src = -1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && deg[i] == 0) { src = i; break; }

        if (src == -1) { printf("Cycle detected!\n"); return; }

        visited[src] = 1;
        order[cnt++] = src + 1;

        for (int j = 0; j < n; j++)
            if (adj[src][j]) deg[j]--;
    }

    printf("Topological Order: ");
    for (int i = 0; i < n; i++)
        printf("%d%s", order[i], i < n-1 ? " -> " : "\n");
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
            if (adj[i][j]) indeg[j]++;
        }

    topoSort();
    return 0;
}
