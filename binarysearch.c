#include<stdio.h>

int binarySearch(int arr[], int size, int key){
    int low, mid, high;
    low = 0;
    high = size-1;
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid]<key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 3, 5, 56, 64, 73, 123, 225, 444};
    int size = sizeof(arr)/sizeof(int);
    int key = 56;
    int searchindex = binarySearch(arr, size, key);
    printf("The key %d was found at index %d\n", key, searchindex);

    return 0;
}