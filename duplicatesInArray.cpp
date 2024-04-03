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

void duplicate(int arr[], int size)
{
  int k = 0;
  int duplicate[100];
  int i = 0;
  while (i < size)
  {
    int temp = arr[i];
    for (int j = i+1; j < size; j++)
    {
      if (arr[j] == temp)
      {
        duplicate[k] = temp;
        k++;
      }
    }
    i++;
  }

  printArray(duplicate, k);
}


int main()
{
  int arr[11] = {2, 7, 5, 2, 8, 1, 15, 8, 11, 12, 7};
  duplicate(arr, 11);
}
