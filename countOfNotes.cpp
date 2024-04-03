#include<iostream>
#include<math.h>
using namespace std;

int main() {
  int amount;
  cin >> amount;
  int count;
  
  while(amount != 0) {
    if(amount >= 100){
    count = 100;
  }
  else if(amount >= 50){
    count = 50;
  }
  else if(amount >= 20){
    count = 20;
  }
  else if(amount >= 1){
    count = 1;
  }
   switch(count) {

  case 1: if(amount>0 && amount <20){
    cout<<"Total no of 1rs notes: "<< (amount/1)<<endl;
    amount = amount % 1;
    break;
    } 
    case 20: if(amount>= 20 && amount <50){
    cout<<"Total no of 20rs notes: "<<(amount/20)<<endl;
    amount = amount % 20;
    break;
    } 
    case 50: if(amount>=50 && amount <100){
    cout<<"Total no of 50rs notes: "<<(amount/50)<<endl;
    amount = amount % 50;
    break;
    } 
    case 100: if(amount>=100){
    cout<<"Total no of 100rs notes: "<<(amount/100)<<endl;
    amount = amount % 100;
    break;
    }

     default: cout<<"invalid value"<<endl;

  }

}
}