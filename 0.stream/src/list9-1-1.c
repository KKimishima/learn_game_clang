#include<stdio.h>

int main(){
  int ch;

  while (1) {
    ch = getchar();
    if (ch == EOF) {
      break;
    }
    putchar(ch);
    printf("\nchの中身;%d\n\n",ch);
  }
  return 0;

}
