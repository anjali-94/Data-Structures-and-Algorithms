#include<stdio.h>

void display(int arr[],int size)
{
    for(int i = 0; i < size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    

}

void ind_deletion(int arr[],int size,int index)
{ 
    for(int i = index+1; i <= size-1; i++) {
        arr[i-1]=arr[i];
    }

}

int main() {
    int arr[100] = {3,5,8,10,34,65};
    int size = 6, index=2;
    display(arr,size);
    ind_deletion(arr,size,index);
    size=size-1;
    display(arr,size);

   

}