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

void pairSum(int arr[], int size)
{
  int i = 0;
  int sum[i];
  int first = 0;
  int second = 1;
  while(first < size && second < size) {
    sum[i] = arr[first] + arr[second];
    first = first + 2;
    second = second + 2;
    i++;
  }
  if(first != size) {
    sum[i] = arr[first];
    i++;
    first++;
  }

  printArray(sum, i);
}


int main()
{
  int arr[11] = {2, 7, 5, 2, 8, 1, 15, 8, 11, 12, 7};
  pairSum(arr, 11);
}
