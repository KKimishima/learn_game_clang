//関数ポインタのテスト
//動作テスト

#include<stdio.h>

// 呼び出す関数
void one(void);
void two(void);
void three(void);

void one(){
  puts("1です");
}

void two(){
  puts("2です");
}

void three(){
  puts("3です");
}

int main(){
  void (*po[])(int) = {one,two,three};
  int sw;
  int print_sw;

  printf("実行番号入力:");
  scanf("%d",&sw);

  (*po[sw])(print_sw);

  return 0;

}
