#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void sortArray(int arr[], int size)
{
  int left = 0;
  int right = size-1;
  while(left <= right) {
    if(arr[left] == 0 ) {
      left++;
    }
    if(arr[right] == 1 ) {
      right--;
    }

    if(arr[left] ==1 && arr[right] == 0 && left <=right) {
      swap(arr[left], arr[right]);
      left++;
      right--;
    }
  }

}


int main()
{
  int arr[9] = {1, 0, 1, 0, 1, 0, 1, 1, 0};
  printArray(arr, 9);
  sortArray(arr, 9);
  printArray(arr, 9);
}
