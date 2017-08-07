// じゃんけんゲーム改良
// 自分なりにソースを書く
//

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//定数
#define PATTEN_MIN 0  // じゃんけんの表示最小
#define PATTEN_MAX 3  // じゃんけんの表示最大

// 構造体
typedef struct{       // じゃんけん入力構造体
  int input;
  int random;
  int win;
  int lose;
  int draw;
}junken_value;

// メイン関数
int main(){
  
  // 構造体宣言と初期化
  junken_value  value   = {0,0,0,0,0};    // 入力の値の初期化

  srand(time(NULL));                // ランダム種生成



  puts("じゃんけんゲームスタート");

  do{
  
  }while();

  return 0;
}
