#include<iostream>
using namespace std;

int fact(int n) {
  int value = 1;
  for(int i = 1; i<=n; i++) {
    value = value * i;
  }
  return value;
}

int nCr(int n, int r) {
  if(r > n) {
    return 0;
  }
  int num = fact(n);
  int deno = fact(r) * fact(n-r);
  int ans = num/deno;
  return ans;
}

int main() {
 int n, r;
 cin >> n >> r;
 cout<< "combination is : "<< nCr(n, r) << endl;
  
}