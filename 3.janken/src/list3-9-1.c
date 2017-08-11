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
  F_INIT  = 0,          // init_funcに紐づく列挙体
  F_INPUT,              // init_funcに紐づく列挙体
  F_GAME,               // game_funcに紐づく列挙体
  F_RETRY,              // retry_funcに紐づく列挙体
  F_SCORE               // score_funcに紐づく列挙体
};

// 構造体
// ここに処理内で使う変数をすべて定義
typedef struct{       // じゃんけん入力構造体
  int input;          // ユーザ入力
  int random;         // ランダム入力
  int win;            // 勝ちフラグ
  int lose;           // 負けフラグ
  int draw;           // 引き分けフラグ
  int result;         // 結果の収納
  int retry;          // リトライフラグ
}junken_value;

// ポインタを使った二次元配列
// メッセージに使う文字列を収納
char *juken_hand[] = {
  "グー",
  "チョキ",
  "パー"
};

// 呼び出さる関数を一覧
// スコア表示関数
void score_func(junken_value *value){
  puts("ゲームスコア!!!");
  printf("勝利回数(%d)...負け回数(%d)..引き分け回数(%d)\n",value->win,value->lose,value->draw);
  return;
}

// リトライ処理関数
void retry_func(junken_value *value){
  printf("もう一度挑戦しますか\n挑戦..(1)/終了...(0):");
  scanf("%d",&value->retry);
  return;
}

// 勝利関数
void doraw_func(junken_value *value){
  value->draw += 1;                     // 引き分けフラブをプラスする
  puts("***引き分けです***");
  return;
};

void lose_func(junken_value *value){
  value->lose += 1;                     // 負けフラグをプラスする
  puts("***負けです***");
  return;
};

void win_func(junken_value *value){
  value->win += 1;                      // 勝ちフラグをプラスする
  puts("***勝ちです***");
  return;
};

// じゃんけんゲームの勝敗処理
void game_func(junken_value *value){
  value->result = (value->input - value->random + 3) % 3; //
  printf("じゃんけん計算結果:%d\n",value->result);
  value->result += 5; // 関数ポインタ呼び出しのため+3する
  printf("計算結果関数呼び出し:%d\n",value->result);
  return;
};

// インプット関数
// 構造体にポインタで紐付けて引数にする
void input_func(junken_value *value){
  int i;
  value->random = rand() % 3; // 1から2まで生成

    do{
      // 二次元配列から文字のよびだし
      printf("じゃんけんぽん...\n");
      for(i = PATTEN_MIN;i < PATTEN_MAX;i++){
        printf("(%d)%s",i,juken_hand[i]);
      }

      printf(":");
      scanf("%d",&value->input);
    
  }while(value->input < 0 || value->input > 2);
  
  printf("私の手は:%sで、自動生成の手は:%sです\n",juken_hand[value->input],juken_hand[value->random]);

  return;
};

// 初期化関数
// すべての構造体変数をの初期化
void init_func(junken_value *value){
  value->input  = 0;
  value->random = 0;
  value->retry  = 0;
  value->result = 0;
  return;
};
  // コールバック関数
// コールバック関数に構造体ポインタに紐付け
 typedef void (*callback)(junken_value *value);

//コールバック 関数テーブル
callback (func_table[]) = {
  init_func,
  input_func,
  game_func,
  retry_func,
  score_func,
  doraw_func,
  lose_func,
  win_func
};

// メイン関数
int main(){
  
  srand(time(NULL));                  // ランダム種生成

  puts("じゃんけんゲームスタート");
  
  junken_value value;                 // 変数構造体宣言
 
  // 結果の初期化
  value.lose   = 0;
  value.draw   = 0;
  value.win    = 0;
 
  // 名処理開始
  do{

    // 初期化関数呼び出し
    (*func_table[F_INIT])(&value);

    // 入力関数呼び出し
    (*func_table[F_INPUT])(&value);
    
    (*func_table[F_GAME])(&value);

    (*func_table[value.result])(&value);

    (*func_table[F_RETRY])(&value);
//  }while(retry == 0);               //こっちが正しいコード
  }while(value.retry == 1);
    
    (*func_table[F_SCORE])(&value);

  return 0;
}
