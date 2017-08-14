// マインドゲームを作成する
// ルール
// 1.出題者が数字0~9までの数値を4つの重複ない任意の数字選択(生成)
//  - 下記のような数値を選択(生成)
//    例.5736
// 2.回答者が任意の４つの数値(推測)を質問する
//  - 下記のような形式で質問する
//    例.5761ですか?
// 3.出題者が質問に対して下記の回答を行う
//  - 出題者が任意に選択した数値に該当している答える
//    例.それらの数字中に3の数字が含まれます
//       ただし、そのうち3は、位置もあっています
// 4,これら繰り返していき正解を行うまで繰り返す。
//   そのかで、正解までの時間を測定して速さを競う
//
// 20170812 基礎部分の作成
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define NUBER_MAX 10  // 生成されるランダム数の限界(9だが+1)
#define DIGITS 4      // 出題数列の最大

//typedef struct{
//  int   random_num[DIGITS];
  //  input_str
//} game_value;

//typedef struct{
//  int   input_num[DIGITS];
//  char  input_str[DIGITS + 2]; 
//} input_value;
// ゲームの判定関数

//void  value_init(game_value *values);
//void  input_init(input_value *inputs);
//void  random_init(game_value *values);
//void  input_interface(input_value *inputs);
//int   input_func(input_value *inputs);

  //数値を入力
int input_func(input_value *inputs){
  int   i,j;
  // 初期化
//  input_init(&inputs);

  puts("四桁の数値を入力してください");
  puts("四桁以上の文字は無効になります!!!");
  printf("数値:");
  fgets(inputs->input_str,sizeof(inputs->input_str) + 1,stdin); // 文字オーバを収納するため+1
 
  // 文字数が少ない場合
  if(strlen(inputs->input_str) <= 4){  //
    return 1;
   }

  // 文字数が多い場合
  if(strlen(inputs ->input_str) > 5){  //
    while ( getchar()  !=  '\n'  );             // 入力バッファから,\nまで読み飛ばし
    return 2;
  }
  
  // 文字が含まれいないか確認
  for(i = 0;i < DIGITS;i++){
    if(!isdigit(inputs->input_str[i])){                 // 文字が含まれるとfalse(0)がかえされる
      return 3;
    }
  }

  // 同じ文字があるか確認
  for(i = 0;i < DIGITS;i++){
    inputs->input_num[i] = inputs->input_str[i]  - '0';
 //   input_num[i] = input_str[i] - '0';          // `0`を引いて数字キャストする
    for(j = 0;j< i ;j++){
      if(inputs->input_str[i] == inputs->input_str[j]){
        return 4;
      }
    }
  }

  return 0;
}

// 入力インターフェイス関数
void input_interface(input_value *inputs){
  int input_frag;
  do{
    input_frag =  input_func(&inputs);
    switch(input_frag){
      case  0:  puts("***OK***");                       break;
      case  1:  puts("***文字数が少なすぎ***");         break;
      case  2:  puts("***文字数が多すぎです***");       break;
      case  3:  puts("***文字に間違いがあります***");   break;
      case  4:  puts("***同じ文字が含まれています***"); break;
      default:  puts("***入力エラー***"); exit(1);      break;
    }
  }while(input_frag != 0);
  return;
}

// ランダム生成の関数
void random_init(int random_num[]){
  int i,j;
  int random_comp;            // 乱数の比較用変数

  puts("ランダム数値の生成");
  
  // 重複のないランダムな数値の入力
  for(i = 0;i <= sizeof(random_num) / sizeofa(random_num[0]);i++){ // 一重目のループ:配列の数だけ繰り返す
    do{                                                             // 二重目のループ:基本配列数と検証入れうすう
      random_comp = 0 + rand() % NUBER_MAX;                         // 0~9までの乱数を比較用一時変数に収める
      for(j = 0;j < i;j++){                                         // 三重ループ:0(j)かカレント配列数(i)まで
        if(values->random_num[j] == random_comp){                          // すでにデータが得られているか調べる
          break;                                                    // ブレイクするとwhileの条件で必ず弾かれるので
        }                                                           // 正常な数値が入れまで繰り返される
      }
    }while(j < i);
    values->random_num[i] = random_comp;
  }
  return ;
}


int main(){
  int i;                                  // デバッグ用
  int   random_num[DIGITS];
  int retry;
  time_t start,end;

  srand(time(NULL));

  retry = 0;
  do{
    //  ランダム生成関数
    random_init(random_num);                 

    puts("ランダムテスト");               // デバッグ用
    for(i = 0;i < DIGITS;i++){            // デバッグ用
      printf("%d",values.random_num[i]);  // デバッグ用
    }                                     // デバッグ用
    puts("");                             // デバッグ用

    // 入力インターフェイス関数
    input_interface(&inputs);

//    hitblow_func();
  }while(retry == 1);
//  }while(retry == 0); // こっちが正しい
  

  return 0;
}
