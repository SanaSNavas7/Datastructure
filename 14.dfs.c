#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
int adj[20][20], visited[20], n, start;
void dfs(int start);
void main()
{
    int i, j;
    printf("enter no of vertices");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {for(j=0;j<n;j++){
printf("enter adj matrix a[%d][%d]", i, j);
        scanf("%d", &adj[i][j]);
    }
    }
        
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    printf("enter starting vertex");
    scanf("%d", &start);
    dfs(start);
}

void dfs(int node)
{
    int i;
    visited[node] = 1;
    printf("%d", node);
    for (i = 0; i < n; i++)
    {
        if (adj[node][i] == 1 && visited[i] != 1)
        {
            dfs(i);
        }
    }
}
