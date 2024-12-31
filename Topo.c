#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int n, adj[20][20], visitedCount = 0, queue[20], front = -1, rear = -1, inDegree[20];
void enqueue(int vertex);
int dequeue();
void main()
{
    printf("\nEnter the number of nodes:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        inDegree[i] = 0;
    }
    printf("\nEnter the adjacency matrix");
    // reading the adjacency matrix and upadating the indegree
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\na[%d][%d]:", i, j);
            scanf("%d", &adj[i][j]);
            if (i == j && adj[i][j] != 0)
            {
                printf("\nGraph contains self loops...Exiting");
                exit(0);
            }
            if (adj[i][j] == 1)
            {
                // incrementing indegree for j for each directed edge i-->j
                inDegree[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            // adding all the vertices with zero indegree to queue
            enqueue(i);
        }
    }
    printf("\nTopological Sorting Ordering\n");
    while (front != -1 && rear != -1)
    {
        // repeat all the steps while queue is not empty
        int vertex = dequeue();
        // removing vertex from queue and adding it to topological ordering
        printf("%d ", vertex);
        visitedCount++;
        // updating indegree for all adjacent vertices of vertex 'vertex' and adding
        // it to queue if the upadated indegree is zero
        for (int i = 0; i < n; i++)
        {
            if (adj[vertex][i] == 1)
            {
                inDegree[i]--;
                if (inDegree[i] == 0)
                {
                    enqueue(i);
                }
            }
        }
    }
    if (visitedCount < n)
    {
        // if there are nodes left even after queue is empty, the graph is cyclic
        printf("\nGraph is cyclic");
    }
}
void enqueue(int vertex)
{
    if (front == -1)
    {
        front++;
    }
    rear++;
    queue[rear] = vertex;
}
int dequeue()
{
    int vertex = queue[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    return vertex;
}
