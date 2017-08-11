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
  F_INIT  = 0,
  F_INPUT,
  F_GAME,
  F_RETRY
};

// 構造体
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
char *juken_hand[] = {
  "グー",
  "チョキ",
  "パー"
};

void retry_func(junken_value *value){
  printf("もう一度挑戦しますか:");
  scanf("%d",&value->retry);
  return;
}

void doraw_func(junken_value *value){
  value->draw++;
  puts("引き分けです");
  return;
};

void lose_func(junken_value *value){
  value->lose++;
  puts("負けです");
  return;
};

void win_func(junken_value *value){
  value->win++;
  puts("勝ちです");
  return;
};

// じゃんけんゲームの勝敗処理
void game_func(junken_value *value){
  value->result = (value->input - value->random + 3) % 3;
  value->result += 4; // 関数ポインタ呼び出しのため+3する
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


void init_func(junken_value *value){
  value->input  = 0;
  value->random = 0;
  value->win    = 0;
  value->lose   = 0;
  value->draw   = 0;
  value->result = 0;
  value->retry  = 0;
}
  // コールバック関数
// コールバック関数に構造体ポインタに紐付け
 typedef void (*callback)(junken_value *value);

//コールバック 関数テーブル
callback (func_table[]) = {
  init_func,
  input_func,
  game_func,
  retry_func,
  win_func,
  lose_func,
  doraw_func
};

// メイン関数
int main(){
  
  srand(time(NULL));                  // ランダム種生成

  puts("じゃんけんゲームスタート");
  
  junken_value value;
  // 名処理開始
  do{
    // 初期化処理
//    junken_value value = {0,0,0,0,0,0,0};   // 構造体宣言と初期化

    (*func_table[F_INIT])(&value);

    (*func_table[F_INPUT])(&value);
    
    (*func_table[F_GAME])(&value);

    (*func_table[value.result])(&value);

    (*func_table[F_RETRY])(&value);
//  }while(retry == 0);               //こっちが正しいコード
  }while(value.retry == 0);

  return 0;
}
