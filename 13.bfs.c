#include <stdio.h>

int n, i, j, adj[20][20], start, visited[20], queue[20], front = -1, rear = -1;

void bfs(int start);
void enqueue(int node);
int dequeue();

int main()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Initialize visited array to 0
    for (i = 0; i < n; i++)
        visited[i] = 0;

    // Reading the graph from adjacency matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter A[%d][%d]: ", i, j);
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid Entry!!\n");
    }
    else
    {
        printf("BFS visited order:\n");
        bfs(start);
    }

    return 0;
}

void bfs(int start)
{
    enqueue(start);
    visited[start] = 1;
    printf("%d\t", start);

    while (front != -1) // Loop while queue is not empty
    {
        int node = dequeue();
        for (int i = 0; i < n; i++)
        {
            if (adj[node][i] == 1 && visited[i] == 0) // Correct indexing
            {
                visited[i] = 1;
                printf("%d\t", i);
                enqueue(i);
            }
        }
    }
}

void enqueue(int node)
{
    if (rear == 19) // Check for queue overflow
    {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = node;
}

int dequeue()
{
    if (front == -1) // Check for underflow
    {
        printf("Queue Underflow!\n");
        return -1;
    }

    int node = queue[front];
    if (front == rear) // If only one element was present
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    return node;
}
