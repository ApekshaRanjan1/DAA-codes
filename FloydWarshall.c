//sigh starting again with a matrix
#include <stdio.h>
#include <limits.h>
#define inf INT_MAX
int n;

int main()
{
    printf("\nEnter number of vertices: ");
    scanf("%d", &n);

    int i, j;
    int graph[n][n];
    //im tired, need water

    printf("\nEnter the elements in the adjacency matrix: ");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &graph[i][j]);
            if(graph[i][j]==0)
            {
                graph[i][j] = inf;
            }
        }
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==j)
            {
                graph[i][j]=0;
            }
        }
    }

    floydWarshall(graph);
    return 0;
}

void floydWarshall(int graph[n][n])
{
    int dist[n][n];
    int i, j, k;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    for(k=0; k<n; k++)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(dist[i][k] != inf && dist[k][j] != inf && dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }//was stressing on this part for no reason...its so easy

    printf("\n\n-------------------------------------------------------------\n");
    printf("\nShortest path matrix ==> \n");

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(dist[i][j]==inf)
            {
                printf("INF\t");
            }
            else{
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}
//the code was easy ngl...
