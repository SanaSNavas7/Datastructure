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

    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter adj matrix  adj[%d][%d]: ", i, j);
            scanf("%d", &adj[i][j]);
        }
    }


    printf("Enter starting vertex: ");
    scanf("%d", &start);

    
    if (start < 0 || start >= n)
    {
        printf("Invalid vertex!\n");
    }
    else
    {

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
    enqueue(start);          
    visited[start] = 1;      
    printf("%d ", start);    

    while (front != -1)  
    {
        int node = dequeue();   
        for (i = 0; i < n; i++)
        {
            if (adj[node][i] == 1 && visited[i] == 0)  
            {
                visited[i] = 1;      
                printf("%d ", i);    
                enqueue(i);          
            }
        }
    }
}


void enqueue(int node)
{
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
    int node = queue[front]; 
    if (front == rear) 
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
