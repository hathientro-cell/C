#include <stdio.h>

struct Item
{
    int weight;
    int value;
    float ratio;
};

void sort(struct Item item[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(item[j].ratio < item[j+1].ratio)
            {
                struct Item temp = item[j];
                item[j] = item[j+1];
                item[j+1] = temp;
            }
        }
    }
}

int main()
{
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d",&n);

    struct Item item[n];

    printf("Enter value and weight:\n");

    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&item[i].value,&item[i].weight);

        item[i].ratio =
            (float)item[i].value/item[i].weight;
    }

    printf("Enter capacity: ");
    scanf("%d",&capacity);

    sort(item,n);

    float profit = 0;

    for(int i=0;i<n;i++)
    {
        if(capacity >= item[i].weight)
        {
            profit += item[i].value;
            capacity -= item[i].weight;
        }
        else
        {
            profit += item[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum Profit = %.2f\n",profit);

    return 0;
}
