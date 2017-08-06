// じゃんけんゲーム改良
// 関数の分離と成績表示
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 定数
#define PATTEN_MAX 3           // じゃんけんの表示最大
#define PATTEN_MIN 0           // じゃんけんの表示最初

// グローバ変数
int input_value_junken;         // 入力する数値
int auto_value_junken;          // ランダム生成される数値
int win_no;                     // 勝利回数
int lose_no;                    // 敗北回数
int draw_no;                    // 引き分け回数

char *input_patten_junken[] = {  // 入力された手の表示
  "グー",
  "チョキ",
  "パー"
};

char *result_patten_junken[] = {
  "引き分け",
  "負け",
  "勝ち",
};

// 再挑戦フラグ
int contfim_retry(){
  int retry_value;

  printf("再挑戦しますか\nはい...(1)いいえ...(0)");
  scanf("%d",&retry_value);

  return retry_value;
}

// カウント関数
void count_result(int result){
  
  switch(result){
    case 0: draw_no++;  break;
    case 1: lose_no++;  break;
    case 2: win_no++;   break;
  }
  return;
}

// 結果表示関数
void print_result(int result){
  
  switch(result){
    case 0: puts("引き分けです"); break;
    case 1: puts("負けです");     break;
    case 2: puts("勝ちです");     break;
  }
  return;
}

// じゃんけん関数
void junken(){
  int i;

  auto_value_junken = PATTEN_MIN + rand() % PATTEN_MAX; // 0から２までの乱数生成

  do{
    printf("じゃんけんぽん\n");
    
    for(i = PATTEN_MIN;i < PATTEN_MAX;i++){
      printf("%s(%i)...",input_patten_junken[i],i);     // 表示するパターンを表示
    }
    printf(":");
    
    scanf("%d",&input_value_junken);                    // じゃんけんの数値を入力

  }while (input_value_junken < PATTEN_MIN || input_value_junken > PATTEN_MAX -1 ); // 0から2での入力でループを抜ける
                                                                                   // 配列のため"-1"する
  return;
}

// 初期化関数
void initialize(){
  // まとめて初期化
  input_value_junken= 0;
  auto_value_junken = 0;
  win_no            = 0;
  lose_no           = 0;
  draw_no           = 0;

  srand(time(NULL));      // 乱数の種を創る
  
  puts("じゃんけんゲームスタート");

  return;
}

// メイン関数
int main(){
  int result_junken;  // じゃんけん結果
  int retry;          // 再挑戦フラッグ

  initialize();       // 初期化関数呼び出し

  // メインループ開始
  do{
    junken();         // じゃんけん関数呼び出し
  
    printf("入力:%s相手:%s\n",input_patten_junken[input_value_junken],input_patten_junken[auto_value_junken]);
    
    result_junken = (input_value_junken - auto_value_junken + PATTEN_MAX) % PATTEN_MAX; // 勝敗判定


    count_result(result_junken);  // カウント関数

    print_result(result_junken);  // 結果表示関数
   
    retry = contfim_retry();  // 再戦フラグ関数
  }while(retry == 1); // リトライフラグ1のとき終了
  
  printf("結果:%d勝%d敗%d引き分け \n",win_no,lose_no,draw_no);

  return 0;
}
