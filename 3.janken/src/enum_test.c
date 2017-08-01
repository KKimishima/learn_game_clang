// 共有体の実験
// 
//
#include<stdio.h>

typedef enum {
  zero,
  one,
  two
} data;

int main(){
  data sw;

  sw = zero;
  
  switch(sw){
    case zero : puts("ゼロ"); break;
    case one  : puts("イチ"); break;
    case two  : puts("二");   break;
  }
  
  return 0;
}
