#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char *argv[]) {
  int number;
  srand(time(NULL));
  for(int i=0;i<10;i++){
    number=rand();
    cout<<to_string(number)<<endl;
  }
}