#include <stdio.h>

int min(int a,int b)
{
    return (a<b)?a:b;
}

int main()
{
    int n;

    printf("Enter number of coin types: ");
    scanf("%d",&n);

    int coin[n];

    printf("Enter coins:\n");

    for(int i=0;i<n;i++)
        scanf("%d",&coin[i]);

    int amount;

    printf("Enter amount: ");
    scanf("%d",&amount);

    int dp[1000];

    dp[0]=0;

    for(int i=1;i<=amount;i++)
        dp[i]=9999;

    for(int i=1;i<=amount;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(coin[j]<=i)
            {
                dp[i]=min(dp[i],
                          dp[i-coin[j]]+1);
            }
        }
    }

    printf("Minimum Coins = %d\n",
           dp[amount]);

    return 0;
}
