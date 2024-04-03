#include <iostream>
using namespace std;

int main()
{
  int n;
  cout<<"Enter the value of n: ";
  cin>>n;
  int i = 1;
  while(i <= n) {
    //print 1st triangle
    int j = 1;
    while(j<= n-i+1) {
      cout<<j;
      j++;
    }
    //print 2nd triangle
    int k = 2*(i-1);
    while(k) {
      cout<<"*";
      k--;
    }
    //print 3rd triangle
    int start = n-i+1;
    while(start) {
      cout<<start;
      start--;
    }
    cout<<endl;
    i++;
  }
  
}
