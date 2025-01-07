#include <stdio.h>

void main()
{
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    int A[n][n], vi[n], i, j, u, v, min, e = 1, cost = 0;
    
    // Initialize visited array
    for (i = 0; i < n; i++)
    {
        vi[i] = 0;  // All vertices are initially not included in MST
    }
    
    // Input adjacency matrix
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
            if (A[i][j] == 0 && i != j) // No edge case
            {
                A[i][j] = 999; // Use 999 to represent no edge between vertices
            }
        }
    }
    
    // Choose the first vertex in the MST (vertex 0)
    vi[0] = 1;  // Start from vertex 0
    while (e < n - 1)
    {
        min = 999;  // Reset the minimum edge value for the next iteration
        // Loop to find the minimum edge connecting the MST to a vertex outside it
        for (i = 0; i < n; i++)
        {
            if (vi[i] == 1)  // Check only vertices already in MST
            {
                for (j = 0; j < n; j++)
                {
                    if (A[i][j] < min && vi[j] == 0)  // Find edge to non-MST vertex
                    {
                        min = A[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // Add the selected edge to the MST
        cost += min;
        vi[v] = 1;  // Mark the vertex 'v' as part of the MST
        e++;
        printf("Edge {%d, %d}: %d\n", u + 1, v + 1, min);  // Print the edge and its weight
    }
    
    // Print the total cost of the MST
    printf("Total cost of MST: %d\n", cost);
}
