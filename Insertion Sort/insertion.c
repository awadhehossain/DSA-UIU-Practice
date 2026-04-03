#include<stdio.h>

void insertion_sort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j;
        for(j=i-1;j>=0 && arr[j]>key;j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=key;
    }
}

int main()
{
    int n;
    printf("Enter the array size: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Initial Array: ");

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");

    insertion_sort(arr,n);

    printf("Sorted Array: ");

     for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}
