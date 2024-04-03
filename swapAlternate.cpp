#include<iostream>
using namespace std;

void printArray(int arr[], int size) {
  for(int i = 0; i< size; i++) {
    cout<< arr[i] <<" ";
  }
  cout<<endl;
}

void swapAlternate(int arr[], int size) {
  for(int i = 0; i < size; i = i+2) {
    if(i+1 < size) {
      swap(arr[i], arr[i+1]);
    }
  }
}

int main() {
  int arr[7] = {2, 7, 5, 9, 8, 1, 15};
  printArray(arr,7);
  swapAlternate(arr, 7);
  printArray(arr,7);
  
  }
  
