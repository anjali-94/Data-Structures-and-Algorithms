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

int main()
{
    int arr[] = {1, 23,52, 15, 56, 14,33, 223, 125, 444};
    int size = sizeof(arr)/sizeof(int);
    printf("size is: %d\n",size);
    int key = 444;
    int index = linearSearch(arr, size, key);
    printf("The key %d was found at index %d.\n", key, index);
    return 0;
}