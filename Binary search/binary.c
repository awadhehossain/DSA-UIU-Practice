#include<stdio.h>
int binary_search(int arr[],int n,int key)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(key==arr[mid])
        {
            return mid;
        }
        else if (key<arr[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return -1;
}
int main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter the key:");
    scanf("%d",&key);
    int result=binary_search(arr,n,key);
    if(result==-1)
    {
        printf("ELements is not found in the array.");
    }
    else
    {
        printf("The elemets is found at index %d and the element is %d",result,arr[result]);
    }

    return 0;

}