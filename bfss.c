#include <stdio.h>

int adj[20][20], visited[20], i, j, n, start, queue[20];
int front = -1;
int rear = -1;

void bfs(int start);
void enqueue(int node);
int dequeue();

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Reading the adjacency matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter adj matrix  adj[%d][%d]: ", i, j);
            scanf("%d", &adj[i][j]);
        }
    }

    // Input starting vertex
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    // Check for valid start vertex
    if (start < 0 || start >= n)
    {
        printf("Invalid vertex!\n");
    }
    else
    {
        // Initialize visited array to 0 (not visited)
        for (i = 0; i < n; i++)
        {
            visited[i] = 0;
        }

        // Perform BFS
        bfs(start);
    }

    return 0;
}

void bfs(int start)
{
    enqueue(start);          // Enqueue the starting vertex
    visited[start] = 1;      // Mark the starting vertex as visited
    printf("%d ", start);    // Print the starting vertex

    while (front != -1)  // Continue while the queue is not empty
    {
        int node = dequeue();   // Dequeue the next node to process
        for (i = 0; i < n; i++)
        {
            if (adj[node][i] == 1 && visited[i] == 0)  // Check for unvisited neighbors
            {
                visited[i] = 1;      // Mark as visited
                printf("%d ", i);    // Print the visited node
                enqueue(i);          // Enqueue the unvisited neighbor
            }
        }
    }
}

// Enqueue function to add nodes to the queue
void enqueue(int node)
{
    if (front == -1 && rear == -1)  // If the queue is empty
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;  // Move the rear pointer to the next position
    }
    queue[rear] = node;  // Add node to the queue
}

// Dequeue function to remove nodes from the front of the queue
int dequeue()
{
    int node = queue[front];  // Get the node at the front of the queue
    if (front == rear)  // If there's only one element in the queue
    {
        front = -1;
        rear = -1;  // Reset the queue when it's empty
    }
    else
    {
        front++;  // Move the front pointer to the next position
    }
    return node;  // Return the dequeued node
}
