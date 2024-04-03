#include<iostream>
using namespace std;

int main() {
  int arr[7] = {3,7,1,2,6,9,8};
  int n = 7;
  
  for(int i = 1; i < n; i++) {
    for( int j= 0; j < n-i; j++) {
      if(arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  for(int i = 0; i < n; i++) {
    cout<< arr[i]<< " " ;
  }
}