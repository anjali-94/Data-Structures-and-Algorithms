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

void intersection(int arr1[], int arr2[], int size1, int size2)
{
  int arr[7];
  int k = 0;
  int i = 0;
  while (i < size1)
  {
    int temp = arr1[i];
    for (int j = 0; j < size2; j++)
    {
      if (arr2[j] == temp)
      {
        arr[k] = temp;
        k++;
      }
    }
    i++;
  }

  printArray(arr, k);
}


int main()
{
  int arr1[9] = {2, 7, 5, 9, 8, 1, 15, 21, 11};
  int arr2[11] = {2, 14, 11, 19, 8, 1, 6, 7, 12, 54, 21};
  intersection(arr1, arr2, 9, 11);
}
