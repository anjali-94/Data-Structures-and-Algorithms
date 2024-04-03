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

int findUniqueElement(int arr[], int size)
{
  int ans = 0;
  for(int i = 0; i < size; i++) {
    ans = ans ^ arr[i];
  }
  return ans;

}


int main()
{
  int arr[7] = {1, 6, 2, 5, 6, 5, 1};
  printArray(arr, 7);
  cout<< " unique element is: " <<findUniqueElement(arr, 7);
}
