
#include <stdio.h>
#define MAX 5
void main()
{
    int n;
    printf("enter no of vertices");
    scanf("%d", &n);
    int visited[MAX] = {0}, adj[MAX][MAX] = {0}, i, j, current;
    int count = 0;
    int flag = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("adj[%d][%d]", i, j);
            scanf("%d", &adj[i][j]);
        }
    }
    while (count != n)
    {
        for (i = 0; i < n; i++)
        {
            flag = 0;
            if (visited[i] == 0)
            {
                for (j = 0; j < n; j++)
                {
                    if (adj[j][i] == 1)
                    {
                        flag = 1;
                        break;
                    }
                    if (flag == 0)
                    {
                        current = i;
                        printf("%d", current);
                        visited[current] = 1;
                        count++;
                        for (int i = 0; i < n; i++)
                        {
                            adj[current][i] = 0;
                        }
                        break;
                    }
                }
            }
        }
    }
}
