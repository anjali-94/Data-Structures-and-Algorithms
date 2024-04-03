#include<iostream>
#include<climits>
using namespace std;

int getMax(int arr[], int n) {
  int maxi = INT_MIN;
  for(int i = 0; i < n; i++) {
    maxi = max(maxi, arr[i]);
  }
  return maxi;
  
}

int getMin(int arr[], int n) {
  int mini = INT_MAX;
  for(int i = 0; i < n; i++) {
    mini = min(mini, arr[i]);
  }
  return mini;
  
}


int main() {
  int arr[100];
  int size;
  cout<< "enter the size of an array: ";
  cin >> size;
  for(int i= 0 ; i< size; i++) {
    cin >>arr[i];
  }
  cout<< " Maximum value is: "<<getMax(arr, size)<<endl;
  cout<< " Minimum value is: "<<getMin(arr, size)<<endl;
  
}