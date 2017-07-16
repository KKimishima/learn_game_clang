#include<stdio.h>

int main(void){
  int no;   // 読み込んだ値
  int ans = 7;  // 当てさせる数値

  puts("0~9までの数値を入力してください");
  printf("数値"); scanf("%d",&no);

  if(no > ans){
    // \aは警報を鳴らす
    printf("\a答えはもっと小さいよ\n");
  } if(no < ans){
    printf("\a答えはもっと大きいよ\n");
  } else{
    // 上記の条件から正解が絞り込まれる
    printf("正解");
  }
  return 0;
}
