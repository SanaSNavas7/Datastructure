#include <stdio.h>
#include <stdbool.h>
int adj[20][20], stack[20], top = -1, n, i, j, start, visited[20];
void dfs(int start);
void main()
{
    printf("\nEnter number of nodes:");
    scanf("%d", &n);
    // Reading the graph from adjacency matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("\nA[%d][%d]:", i, j);
            scanf("%d", &adj[i][j]);
        }
    }
    printf("\nEnter starting node:");
    scanf("%d", &start);
    printf("\nDFS Visited Order\n");
    dfs(start);
}
void dfs(int node)
{
    // visiting the node
    visited[node] = 1;
    printf(" %d", node);
    for (int i = 0; i < n; i++)
    {
        if (adj[node][i] == 1 && visited[i] != 1)
        {
            // calling dfs recursively on each children
            dfs(i);
        }
    }
}