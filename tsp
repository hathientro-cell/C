#include <stdio.h>

#define INF 9999

int n;
int graph[10][10];
int dp[1024][10];

int min(int a,int b)
{
    return (a<b)?a:b;
}

int tsp(int mask,int pos)
{
    if(mask==(1<<n)-1)
        return graph[pos][0];

    if(dp[mask][pos]!=-1)
        return dp[mask][pos];

    int ans=INF;

    for(int city=0;city<n;city++)
    {
        if(!(mask&(1<<city)))
        {
            ans=min(
                ans,
                graph[pos][city]
                +
                tsp(mask|(1<<city),
                    city)
            );
        }
    }

    return dp[mask][pos]=ans;
}

int main()
{
    printf("Enter number of cities: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }

    for(int i=0;i<1024;i++)
    {
        for(int j=0;j<10;j++)
        {
            dp[i][j]=-1;
        }
    }

    printf("Minimum Cost = %d\n",
           tsp(1,0));

    return 0;
}
