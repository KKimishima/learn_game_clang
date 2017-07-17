// 数あてゲーム
// whlie文を使って実装
//
#include<stdio.h>

int main(){
  int no;      // 入力値
  int ans = 7; // 答え

  // メッセージ  
  puts("数あてゲームスタート");
  puts("0~9までの数値を入力してください");
  puts("終了する場合は-1を入力してください");

  // whileに"1"にで無限ループ
  while(1){
    printf("数値:");  scanf("%d",&no);
  
    // 終了処理
    if(no == -1){
      puts("終了します");
      return -1;
    }

    // 判定処理
    if(no > ans){
      printf("数値が大きすぎです\n");
    } else if (no < ans){
      printf("数値が小さすぎです\n");
    } else {
      break;
    }
  }
  // 正常処理
  puts("正解!!");
  return 0;
}
