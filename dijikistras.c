
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void dijkstra(int n, int a[n][n], int v[], int d[], int start) {
    d[start] = 0; 

    for (int count = 0; count < n - 1; count++) {
        int min = INT_MAX, u = -1;
        for (int i = 0; i < n; i++) {
            if (!v[i] && d[i] < min) {
                min = d[i];
                u = i;
            }
        }
        if (u == -1) break;
         v[u] = 1; 
        for (int i = 0; i < n; i++) {
            if (a[u][i] != 0 && !v[i] && d[u] + a[u][i] < d[i]) {
                d[i] = d[u] + a[u][i];
            }
            
        }
    }
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int a[n][n], v[n], d[n], start;
    for (int i = 0; i < n; i++) {
        v[i] = 0;
        d[i] = INT_MAX;
    }
    printf("Enter the adjacency matrix (use -1 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == -1) a[i][j] = 0; 
        }
    }
    printf("Enter the starting node (0-based index): ");
    scanf("%d", &start);
    dijkstra(n, a, v, d, start);
    printf("Shortest distances from node %d:\n", start);
    for (int i = 0; i < n; i++) {
        if (d[i] == INT_MAX) {
            printf("Node %d is unreachable from node %d\n", i, start);
        } else {
            printf("Distance to node %d: %d\n", i, d[i]);
        }
    }
return 0;
}
