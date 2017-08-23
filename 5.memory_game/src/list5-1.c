/*  0.5秒だけ4文字を表示し,
    その値をキーボードから打ち込む
    これを10回繰り替えて、正しく正解でききた回数と時間を表示する
*/

#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define STAGE_MAX   10    // ゲームの出題数最大
#define NUMBER_MAX  4     // 出題数値の最大桁数
#define INPUT_MAX   254   // 入力最大数値

enum input_stauts {
  SMALL_VALUE = 0,        // 入力文字の少ないとき
  OVER_VALUE,             // 入力文字が多いとき
  EXCE_VALUE,             // 文字が入力されたとき
  OK,                     // 正常に入力されたとき
};

// 入力数値と生成数値の比較
void comp_value(const int display_num[],const  int input_value[],int *game_score){
  int i;

  for(i = 0;i < NUMBER_MAX;i++){
    if(display_num[i] != input_value[i]){
      puts("違うよ");
      return;
    }
  }
    puts("正解");
    
    // 正解数を増やす
    *game_score +=  1;

  return ;
  
}

// 入力数値のチェック入力数値のチェ増やす
int input_check(char input_str[]){
  int i;

  // 文字配列要素を超えたとき
  if (INPUT_MAX -1 == strlen(input_str)){
    puts("オーバフローの危険検出\n強制終了");
    exit(1);
  }
  
  // 文字が入力されたとき
  for (i = 0;i < NUMBER_MAX;i++) {
   if(0 == isdigit(input_str[i])){
     return EXCE_VALUE;
   }
  }
 
  // 文字が小さきとき
  if(4 >= strlen(input_str)){
    return SMALL_VALUE;
  }

  // 文字数が大きとき
  if(6 <= strlen(input_str)){
    return OVER_VALUE;
  }
  
  // 正常に入力されたとき 
  return OK;
}

// 入力ループ
void player_input(int input_value[]){
  int   i;
  char  input_str[INPUT_MAX];  // 入力文字列
  int   input_frag;             // 文字入力脱出フラグ

  do {
    // 数値配列と文字配列初期化
    memset(input_str,'\0',strlen(input_str));
    memset(input_value,0,NUMBER_MAX);
 
    fflush(stdout);            // 出力バッファクリア
    fgets(input_str,sizeof(input_str),stdin);
    
    // 入力チェック関数を呼び出し
    input_frag = input_check(input_str);
  
    switch (input_frag) {
      case SMALL_VALUE: printf("判別:小さすぎ\n入力は:");            break;
      case OVER_VALUE:  printf("判別:大きすぎです\n入力は:");        break;
      case EXCE_VALUE:  printf("判別:文字が入力されまいた\n入力は:");break;
      case OK:                                                       break;
      default:          puts("異常な値です");exit(2);                break;
    }

  } while (input_frag != OK);
  
  // 文字から数値に変換(- '0'で数値になる)
  for(i = 0;i < NUMBER_MAX;i++){
    input_value[i] = input_str[i] -'0';
  }
  
  return;
}

// 一定時間停止関数
int sleep(unsigned long sleep_time){
  clock_t star_clock,end_clock;
  
  star_clock = clock();
 
  do {
    if( (end_clock = clock()) == ((clock_t) -1) ){return -1;} // エラーのとき
    // これは定型文
  } while ( (1000UL *( (end_clock -star_clock) / CLOCKS_PER_SEC) ) < sleep_time );

  return 0;
}

// ランダムな数値を生成
void display(int display_num[]){
  int i;

  for (i = 0;i < NUMBER_MAX;i++ ) {
    display_num[i] = 0 + rand() % 10;
  }

  return;
}

int main(){
  int     i;
  int     count_stage;            // 問題数のカウント
  time_t  start_time,end_time;    // 経過時間
  int     display_num[NUMBER_MAX];// 問題の数値が収納される
  int     sleep_check;            // 停止時間
  int     input_value[NUMBER_MAX];// 入力数値
  int     game_score;             // 正解回数

  time(&start_time);              // 経過時間測定開始
  srand(time(NULL));              // 乱数の種生成
  
  puts("単純記憶トレーニンゲーム");
  puts("スタート");
  
  // カウント系の変数初期化
  game_score =  0;  
  count_stage = 0;

  // メインループ開始
  do {
    printf("%d回目表示\n",count_stage + 1);
    
    // 乱数生成関数呼び出し
    display(display_num);
  
    // 乱数を画面に表示
    for (i = 0;i < NUMBER_MAX;i++) {
      printf("%d",display_num[i]);
    }
    fflush(stdout);               // 出力バッファをきれいにする
    
    // 一時停止関数呼び出し
    sleep_check =sleep(500);
    if(sleep_check == -1){
      puts("スリープ処理失敗\n強制終了");
      exit(1);
    }
  
    printf("\r入力は:");   

    // 入力関数呼び出し
    player_input(input_value);
    
    // 比較関数呼び出し
    comp_value(display_num,input_value,&game_score);
    
    count_stage++;                // 問題数をカウントアップ
  } while (count_stage !=  STAGE_MAX);
  
  time(&end_time);                // 経過時間測定ストップ
  printf("結果...10問中%d問正解\n所要時時間:%d秒\n",game_score,(int)difftime(end_time,start_time));
  return 0;

}
