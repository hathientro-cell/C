#include <stdio.h>

struct Activity
{
    int start;
    int finish;
};

void sort(struct Activity a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j].finish > a[j+1].finish)
            {
                struct Activity temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main()
{
    int n;

    printf("Enter number of activities: ");
    scanf("%d",&n);

    struct Activity a[n];

    printf("Enter start and finish times:\n");

    for(int i=0;i<n;i++)
        scanf("%d%d",&a[i].start,&a[i].finish);

    sort(a,n);

    printf("Selected Activities:\n");

    int last=0;

    printf("(%d,%d)\n",
           a[0].start,
           a[0].finish);

    for(int i=1;i<n;i++)
    {
        if(a[i].start >= a[last].finish)
        {
            printf("(%d,%d)\n",
                   a[i].start,
                   a[i].finish);

            last=i;
        }
    }

    return 0;
}
