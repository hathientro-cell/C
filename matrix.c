#include <stdio.h>

#define INF 9999

int main()
{
    int n;

    printf("Enter number of matrices: ");
    scanf("%d",&n);

    int p[n+1];

    printf("Enter dimensions array:\n");

    for(int i=0;i<=n;i++)
        scanf("%d",&p[i]);

    int m[20][20];

    for(int i=1;i<=n;i++)
        m[i][i]=0;

    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;

            m[i][j]=INF;

            for(int k=i;k<j;k++)
            {
                int cost=
                    m[i][k]
                    +m[k+1][j]
                    +p[i-1]*p[k]*p[j];

                if(cost < m[i][j])
                    m[i][j]=cost;
            }
        }
    }

    printf("Minimum Cost = %d\n",
           m[1][n]);

    return 0;
}
