#include<iostream>
using namespace std;

int TotalOnes(int a, int b) {
  int count_a = 0;
  while(a != 0) {
  int bit_a = a & 1;
  if(bit_a == 1) {
  count_a++;
  }
  a = a >> 1;
  }
  
  int count_b = 0;
  while(b != 0) {
  int bit_b = b & 1;
  if(bit_b == 1) {
  count_b++;
  }
  b = b >> 1;
  }
  
  int ans = count_b + count_a;
  return ans;
}


int main() {
  int a,b;
  cin >>a >> b;
  int ans = TotalOnes(a,b);
  cout<<ans<<endl;
  
}