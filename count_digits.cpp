#include<iostream>
using namespace std;

class Solution{
  public:
  int countdigits(int number){
    if(number == 0) return 1;
    int digits=0;
    number = abs(number);
    while(number!=0){
      digits++;
     number=number/10;
   }
   return digits;
  }
};

int main(){
  int number=365;
  Solution obj;
  cout<<"number of digits is : "<<obj.countdigits(number);
  return 0;
}