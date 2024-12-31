#include <stdio.h>


#define SIZE 50

int vertices;
int indegree[SIZE];
int graph[SIZE][SIZE];

void topological() {
    int count = 0;
    int stack[SIZE], top = -1;

    for (int i = 0; i < vertices; i++) {
        indegree[i] = 0;  //initializing
        for (int j = 0; j < vertices; j++) {
            if (graph[j][i] == 1) {
                indegree[i]++;
            }
        }
    }

    // Push vertices with indegree 0 to stack
    for (int i = 0; i < vertices; i++) {
        if (indegree[i] == 0) {
            stack[++top] = i;
        }
    }

    printf("Topological Sort: ");
    while (top != -1) {
        int u = stack[top--];  
        printf("%d ", u);

        // Reduce the indegree of neighbors and push those with indegree 0
        for (int i = 0; i < vertices; i++) {
            if (graph[u][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    stack[++top] = i;
                }
            }
        }
    }

    printf("\n");
}

int main() {
    // Initialize the graph
    printf("Enter the number of vertices: \n");
    scanf("%d", &vertices);

    // Initialize the adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    // Assign edges to the graph
    int edge;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i != j) {
                printf("\nDoes edge exist between the vertices: %d and %d? (Enter '1' if Yes, '0' if No): ", i, j);
                scanf("%d", &edge);
                if (edge == 1) {
                    graph[i][j] = 1;
                }
                else if (edge != 0) {
                    printf("Enter a valid input!\n");
                }
            }
        }
    }

    // Print the adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    // Perform topological sorting
    topological();

    return 0;
}
