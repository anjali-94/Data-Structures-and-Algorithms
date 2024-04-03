#include<iostream>
using namespace std;

// void reverse(int arr[], int size) {
//   for(int i = 0; i< size/2; i++) {
//     int temp = arr[size-i-1];
//     arr[size-i-1] = arr[i];
//     arr[i] = temp;
//    }
// }

// int swapElements(int arr[] ,int start, int end) {
//   int temp = arr[start];
//   arr[start] = arr[end];
//   arr[end] = temp;
// }

void reverse(int arr[], int size) {
  int start = 0;
  int end = size-1;
  while(start <= end) {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}

void printArray(int arr[], int size) {
  for(int i = 0; i< size; i++) {
    cout<< arr[i] <<" ";
  }
  cout<<endl;
}

int main() {
  int arr[7] = {2, 7, 5, 9, 8, 1, 15};
  printArray(arr,7);
  reverse(arr, 7);
  printArray(arr,7);
  
  }
  
