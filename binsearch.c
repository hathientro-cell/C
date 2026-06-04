#include <stdio.h>
#include <stdlib.h>
int binsearch(int n,int arr[10],int key){
    int l=0,r=n-1,mid;
    while(l<=r){
        mid=(l+r)/2;
        if (key<arr[mid]){
            r=mid-1;
        }
        if (key>arr[mid]){
            l=mid+1;
        }
        if (key == arr[mid]){
            return mid;
        }
    }
    return(-1);
}
int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int val = binsearch(10,arr,1);
    printf("Value Found at %d",val);
}
