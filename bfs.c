#include <stdio.h>

void main()
{
    int n, edge;
    printf("Enter nummber of Vertices : ");
    scanf("%d", &n);

    int Vertex[n];
    int edges[n][n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter your Vertices : ");
        scanf("%d", &Vertex[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            edges[i][j] = edges[j][i] = 0;
            printf("Do you want a edge (%d,%d) or not(0/1) : ", Vertex[i], Vertex[j]);
            scanf("%d", &edge);

            if (edge)
                edges[i][j] = edges[j][i] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d : ", Vertex[i]);
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] == 1)
                printf("%d ", Vertex[j]);
        }
        printf("\n");
    }
}

