//oh boy, this gonna be tough
//kudos to my next few hours of coding for understanding and typing this code out before midnight meet
//adios to my social life
//i hope i get appreciated after writing this code otherwise i gonna go on a skydiving trip without parachute
//sigh* 
//anyway lets do this

//i already regret it ngl
//starting it at 20:58
//its 21:11 im confused, checked the code which i printed for journal, its not making sense after a point
//going to revise the actual Dijkstra sums
//ill just type the code to take a matrix first ig

#include <stdio.h>
#define infinity 9999
#define max 10

int main()
{
    int G[max][max], n, i, j, start;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }
    //22:53 i figured it out... i mean not byhearted the code ...but went through an example with the code
    //understood it...now will write the code
    printf("\nEnter the starting node: ");
    scanf("%d", &start);
    dijkstra(G, n, start);
    return 0;
}

void dijkstra(int G[max][max], int n, int startNode)
{
    int cost[max][max], distance[max], pred[max];
    int visited[max], count, minDistance, nextNode, i, j;
    
    //Creating the cost matrix here, basically replaces zeros with infintiy
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(G[i][j]==0)
            {
                cost[i][j] = infinity;
            }
            else
            {
                cost[i][j] = G[i][j];
            }
        }
    }

    //Giving the initial values to stuff
    for(i=0; i<n; i++) //tired of typing this loop like a bazillion times, make this a shortcut already
    {
        distance[i] = cost[startNode][i];
        pred[i] = startNode;
        visited[i] = 0;
    }
    distance[startNode] = 0;    //startNode's distance from itself is 0
    visited[startNode] = 1; //as startNode is visited we change it to 1
    count = 1;

    //now the main part, finding the shortest path
    while(count<n-1)
    {
        minDistance = infinity;
        //nextNode gives the node at minimum distance
        for(i=0; i<n; i++)
        {
            if(distance[i]<minDistance && !visited[i])
            {
                minDistance = distance[i]; //basically checks all the distances to get the minimum distance
                nextNode = i;
            }
        }
        visited[nextNode] = 1;

        for(i=0; i<n; i++)
        {
            if(!visited[i])
            {
                if(minDistance + cost[nextNode][i] < distance[i])
                {
                    distance[i] = minDistance + cost[nextNode][i];
                    pred[i] = nextNode;
                }
            }
            count++;
        }
    }

    for(i=0; i<n; i++)
    {
        if(i!=startNode)
        {
            printf("\nDistance of node %d = %d", i, distance[i]);
            printf("\nPath = %d", i);
            j=i;
            do
            {
                j = pred[j];
                printf(" <-%d", j);
            } while(j != startNode);
        }
    }
}
//finsihed at 00:31... i gonna go touch some grass
