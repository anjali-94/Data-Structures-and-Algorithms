#include<iostream>
using namespace std;

int fibonacci(int a, int b, int n) {
  int i = 3;
  while(i<=n) {
    int temp = a + b;
    a = b;
    b = temp;
    i++;
    }
    return b;
}


int main() {
  int a = 0;
  int b = 1;
  int n;
  cin>> n;
  int ans = fibonacci(a,b,n);
  cout<<ans<<endl;
}