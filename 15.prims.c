#include <stdio.h>
#include <conio.h>

void main() {
    int n;
    printf("Enter no of vertices: ");
    scanf("%d", &n);
    
    int A[n][n], vi[n], i, j, u, v, e = 1, cost = 0, min = 999;
    
    // Initialize visited vertices to 0 (not visited)
    for (i = 0; i < n; i++) {
        vi[i] = 0;
    }

    // Read the adjacency matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter adj matrix value for A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
            if (A[i][j] == 0) {
                A[i][j] = 999;  // Treat 0 as infinity for no edge
            }
        }
    }

    // Find the initial minimum weight edge
    min = 999;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (A[i][j] < min) {
                min = A[i][j];
                u = i;
                v = j;
            }
        }
    }

    cost += min;
    vi[u] = 1;  // Mark the first vertex as visited
    vi[v] = 1;  // Mark the adjacent vertex as visited

    // Print the first selected edge
    printf("\nEdge {%d, %d} = %d\n", u, v, min);

    // Continue until we have n-1 edges
    while (e < n - 1) {
        min = 999;
        
        // Find the minimum weight edge
        for (i = 0; i < n; i++) {
            if (vi[i] == 1) {  // If the vertex is visited
                for (j = 0; j < n; j++) {
                    if (A[i][j] < min && vi[j] != 1) {  // If the vertex j is not visited
                        min = A[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        
        cost += min;
        vi[v] = 1;  // Mark the end vertex as visited

        // Print the selected edge
        printf("Edge {%d, %d} = %d\n", u, v, min);

        e += 1;  // Increase the edge count
    }

    // Print the total cost of the MST
    printf("\nCost of the MST is: %d\n", cost);
}
