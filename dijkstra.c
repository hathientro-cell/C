#include <stdio.h>

#define INF 9999

int minDistance(int dist[], int visited[], int n)
{
    int min=INF;
    int index=-1;

    for(int i=0;i<n;i++)
    {
        if(!visited[i] && dist[i]<min)
        {
            min=dist[i];
            index=i;
        }
    }

    return index;
}

int main()
{
    int n;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int graph[n][n];

    printf("Enter adjacency matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }

    int source;

    printf("Enter source vertex: ");
    scanf("%d",&source);

    int dist[n];
    int visited[n];

    for(int i=0;i<n;i++)
    {
        dist[i]=INF;
        visited[i]=0;
    }

    dist[source]=0;

    for(int count=0;count<n-1;count++)
    {
        int u=minDistance(dist,visited,n);

        visited[u]=1;

        for(int v=0;v<n;v++)
        {
            if(!visited[v]
               && graph[u][v]
               && dist[u]!=INF
               && dist[u]+graph[u][v] < dist[v])
            {
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }

    printf("Shortest Distances:\n");

    for(int i=0;i<n;i++)
    {
        printf("%d -> %d = %d\n",
               source,i,dist[i]);
    }

    return 0;
}
