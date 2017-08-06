// ポインタの文字列と配列文字列の比較
// char *とchar[]の比較

#include<stdio.h>
#include<string.h>


int main(){
  char array_str[] = "array_str";
  char *pointer_str = "pointer_str";

  // 文字列の表示
  printf("配列の文字列 = %s\n",array_str);
  printf("ポインタの文字列 = %s\n",pointer_str);

  // 文字列の書き換え
  strcpy(array_str,"配列");
  printf("書き換えの文字列 = %s\n",array_str);
  strcpy(pointer_str,"配列");
  printf("ポインタの文字列 = %s\n",pointer_str);

  return 0;
}
