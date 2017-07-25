// ランダムに数を当てさせるプログラム
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DIGITS_MAX  3   // 文字列には一個分確保しておく
#define NUMBER_MAX  10  // 入力数値の最大
#define NUMBER_MIN  1   // 入力数値の最小
#define STAGE_MAX    3   // 入力回数の最大

// 入力用関数
int input(){
  char  input_str[DIGITS_MAX];  // 入力のバッファ文字列
  int   input_number;           // 入力数値

  while(1){
    puts("1~10までの数値を入力してください");
    printf("数値の入力:"); 
    fgets(input_str,sizeof(input_str),stdin);

    // 入力範囲の判定
    input_number = atoi(input_str);

    if (input_number == 0) {
      puts("入力エラーです\n強制終了します。");
      exit(1);
    } else if( (input_number >= NUMBER_MIN) && (input_number <= NUMBER_MAX) ){
     // puts("正常な数値が入力されました");
      return input_number;
    } else{
      puts("異常な数値です\nやり直し!!!!!");
      puts("*********************************");
      // 空読み込み
      // 参考:http://d.hatena.ne.jp/mooz/20070721/p1
      while(getchar() != '\n') ;
    }
  }
}

int main(){
  int   target_number;      // 答え
  int   value_number;       // 入力結果
  int   remain;             // 入力値回数
  int   input_history[STAGE_MAX];       // 入力履歴
  int   i;
  //  ランダム数値生成
  srand(time(NULL));
  target_number = NUMBER_MIN + rand() % NUMBER_MAX;  // 1~10までの乱数

  puts("数あてゲームスタート");

  // 入力回数の初期化
  remain = 0;

  do{
    printf("残り入力回数:%d回\n",STAGE_MAX - remain);
    // 入力関数呼び出し
    value_number = input();
    // 配列に収納して回数を増やす
    input_history[remain++] = value_number; 
    // 入力の判別
    if(target_number < value_number ){
      puts("答えはもっと小さいよ");
    }else if(target_number > value_number){
     puts("答えはもっと大きよ");
    }
  }while((target_number != value_number) && (remain < STAGE_MAX));
  
  if(target_number == value_number) {
   printf("正解!!\n答えは%dです",target_number); 
  }else{
   printf("不正解!!\n答えは%dです",target_number); 
  }

  puts("入力履歴");
  for(i = 0;i < remain;i++){
    printf("%d回目:%d\n",i + 1,input_history[i]);
  }

  return 0;
}
