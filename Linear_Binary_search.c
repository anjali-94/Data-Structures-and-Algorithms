#include <stdio.h>

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

#include<stdio.h>

int binarySearch(int arr[], int size, int key)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 56, 64, 73, 123, 225, 444};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("size is : %d\n",size);
    int key = 444;
    int index = binarySearch(arr, size, key);
    printf("The key %d was found at index %d.\n", key, index);
    return 0;
}