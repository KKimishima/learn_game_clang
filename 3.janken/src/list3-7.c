// じゃんけんゲームの改良
// ポインタによる二次元配列を使い文字を表示する
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define JUNKEN_PATTEN_MAX 3      // じゃんけん表示数

int main(){
  // 結果の数値の変数
  int i;
  int junken_input_value;       // ユーザが入力する数値
  int junken_auto_value;        // 自動生成される数値
  int junke_reslut_value;        // 結果の数値
  int retry;                    // 再挑戦するかのフラグ

  // 表示文字列の変数
  const char *junken_input_patten[] = {    // じゃんけんの入力表示文字列
    "グー",
    "チョキ",
    "パー"
  };
  const char *junke_reslut_patten[] = {      // じゃんけんの結果表示文字列
    "引き分け",
    "負け",
    "勝ち"
  };

  //乱数の種を生成
  srand(time(NULL));
  

  //メイン処理ループ開始
  do{
    // ランダム生成
    junken_auto_value = rand() % 3;   
  
    do{
      puts("じゃんけんスタート");
      printf("じゃんけんぽん..");

      // パターン表示
      for (i = 0;i < JUNKEN_PATTEN_MAX;i++){
        printf("(%d)%s",i,junken_input_patten[i]);
      };
      // 入力
      printf(":");
      scanf("%d",&junken_input_value);
    }while(junken_input_value < 0 || junken_input_value > 2);
  
    // 入力結果表示
    printf("自分:%s,相手:%s\n",junken_input_patten[junken_input_value],junken_input_patten[junken_auto_value]);

    // 結果計算
    junke_reslut_value = (junken_input_value - junken_auto_value + 3) % 3;
    printf("結果:%s\n",junke_reslut_patten[junke_reslut_value]);
    
   printf("もう一度行いますか\nはい(1)...いいえ(0):");
    scanf("%d",&retry);
    
  }while(retry == 1);

 return 0;
}
