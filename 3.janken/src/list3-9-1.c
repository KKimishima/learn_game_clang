// じゃんけんゲーム改良
// 自分なりにソースを書く
// 関数テーブルを実装

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//定数
#define PATTEN_MIN 0    // じゃんけんの表示最小
#define PATTEN_MAX 3    // じゃんけんの表示最大

// 列挙体
enum{
  F_INPUT = 0,
  F_RANDOM,
  F_WIN,
  F_LOSE,
  F_DRAW
};

// 構造体
typedef struct{       // じゃんけん入力構造体
  int input;          // ユーザ入力
  int random;         // ランダム入力
  int win;            // 勝ちフラグ
  int lose;           // 負けフラグ
  int draw;           // 引き分けフラグ
}junken_value;

// インプット関数
// 構造体にポインタで紐付けて引数にする
void input_func(junken_value *value){
  int i;

  value->random = rand() % 3; // 1から2まで生成
//void input_func(int x){                       //構造体抜き
//  printf("関数呼び出しテスト%d\n",value->input);
  do{
    printf("じゃんけんぽん...\n");
    for(i = PATTEN_MIN;i < PATTEN_MAX;i++){
      printf("(%d)%s");
    }
  }while();
//  printf("関数呼び出しテスト%d",x);           //構造体抜き
  value->input = 10;
  return;
};

// コールバック関数
// コールバック関数に構造体ポインタに紐付け
 typedef void (*callback)(junken_value *value);
//typedef void (*callback)(int);                // 構造体抜き

//コールバック 関数テーブル
callback (func_table[]) = {
  input_func
 //  random_func,
 //  win_func,
 //  lose_func,
 //  doraw_func
};

// メイン関数
int main(){
  
  // 初期化処理
  junken_value value = {0,0,0,0,0};   // 構造体宣言と初期化
  int retry = 0;                      // リトライフラグ作成
  srand(time(NULL));                  // ランダム種生成

  puts("じゃんけんゲームスタート");

  // 名処理開始
  do{

    (*func_table[F_INPUT])(&value);
//    (*func_table[0])(1);                      // 構造体抜き
       printf("構造体返り値確認:%d\n",value.input);
//  }while(retry == 0);               //こっちが正しいコード
  }while(retry == 1);

  return 0;
}
