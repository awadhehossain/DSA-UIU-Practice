#include <stdio.h>

int lower_bound(int arr[], int n, int key)
{
    int low = 0, high = n;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (key>arr[mid])
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int key;
    printf("Enter the key: ");
    scanf("%d", &key);

    int result = lower_bound(arr, n, key);

    if (result == n)
        printf("No element greater than or equal to key found.");
    else
        printf("Lower bound index = %d and value = %d", result, arr[result]);

    return 0;
}