#include <iostream>
using namespace std;

int main(void){
  int i=0;
  int d;
  int e;
  while (cin.peek()!='\n'){
    cin>>d;
    if (d<i){
      cout<<"-"<<endl;
    }
    if (d>i){
      cout<<"+"<<endl;
    }
    i=d;
    cin.clear();
    cin.get();
  }
  return 0;
}
