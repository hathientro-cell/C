#include <stdio.h>

void minmax(int a[], int l, int r, int *min, int *max)
{
    if(l == r)
    {
        *min = *max = a[l];
        return;
    }

    if(r == l + 1)
    {
        if(a[l] < a[r])
        {
            *min = a[l];
            *max = a[r];
        }
        else
        {
            *min = a[r];
            *max = a[l];
        }
        return;
    }

    int mid = (l + r) / 2;

    int min1, max1, min2, max2;

    minmax(a, l, mid, &min1, &max1);
    minmax(a, mid + 1, r, &min2, &max2);

    *min = (min1 < min2) ? min1 : min2;
    *max = (max1 > max2) ? max1 : max2;
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int min,max;

    minmax(a,0,n-1,&min,&max);

    printf("Minimum = %d\n",min);
    printf("Maximum = %d\n",max);

    return 0;
}
