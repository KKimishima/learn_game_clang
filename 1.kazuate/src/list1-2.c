// 数あてゲーム2
// 数値を当てるまで繰り返し入力させる

#include<stdio.h>
#include<stdlib.h>

int main(){
  int no;    // 入力値
  int ans = 7;   // 答え

  puts("数あてゲームスタート");
  puts("0~1までの数値を入力してください");
  puts("終了する場合は-1を入力してください");
  do{
    printf("数値:");  scanf("%d",&no);

    if (no == -1){puts("終了します"); exit(1);}
 
   if(no > ans){
      printf("もっと小さい数値です\n");
    } else if(no < ans){
      printf("もっと大きい数値です\n");
    }
  }while(no != ans);

  puts("正解");

  return 0;
}
