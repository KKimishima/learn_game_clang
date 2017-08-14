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

#define NUBER_MAX 9
#define DIGITS 4  // 出題数列の最大

// ゲームの判定関数


//数値を入力
int input_func(){
  int   input_num[DIGITS] = {0,0,0,0};
  char  input_str[DIGITS + 2];                  // 文字列のため+1と必ず改行コードを入れるため+1
  int   i,j;

  puts("四桁の数値を入力してください");
  puts("四桁以上の文字は無効になります!!!");
  printf("数値:");
  fgets(input_str,sizeof(input_str) + 1,stdin); // 文字オーバを収納するため+1
 
  // 文字数が少ない場合
  if(strlen(input_str) <= 4){  //
    return 1;
   }

  // 文字数が多い場合
  if(strlen(input_str) > 5){  //
    while ( getchar()  !=  '\n'  );             // 入力バッファから,\nまで読み飛ばし
    return 2;
  }
  
  // 文字が含まれいないか確認
  for(i = 0;i < DIGITS;i++){
    if(!isdigit(input_str[i])){                 // 文字が含まれるとfalse(0)がかえされる
      return 3;
    }
  }

  // 同じ文字があるか確認
  for(i = 0;i < DIGITS;i++){
    input_num[i] = input_str[i] - '0';          // `0`を引いて数字キャストする
    for(j = 0;j< i ;j++){
      if(input_str[i] == input_str[j]){
        return 4;
      }
    }
  }

  return 0;
}

// インプットチェック関数
void inputcheck_func(){
  int input_frag;
  do{
    input_frag =  input_func();
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

// ランダム生成の初期化
void random_init(){
  int i,j;
  int random_test[DIGITS];
  int random_temp;
  puts("ランダム数値の生成");
  
  // 重複のないランダムな数値の入力
  for(i = 0;i <= sizeof(random_test) / sizeof(random_test[0]);i++){ // 一重目のループ:配列の数だけ繰り返す
    do{                                                             // 二重目のループ:基本配列数と検証入れうすう
      random_temp = 0 + rand() % NUBER_MAX + 1;                     // 0~9までの乱数を比較用一時変数に収める+1する
      for(j = 0;j < i;j++){                                         // 三重ループ:0(j)かカレント配列数(i)まで
        if(random_test[j] == random_temp){                          // すでにデータが得られているか調べる
          break;                                                    // ブレイクするとwhileの条件で必ず弾かれるので
        }                                                           // 正常な数値が入れまで繰り返される
      }
    }while(i < j );
    random_test[i] = random_temp;
    printf("%d",random_test[i]);
  }
  printf("\n");
  return ;
}

// 初期化関数
void value_init(){
  return;
}

int main(){
  int random_num;
  int ans_num;
  int retry;
  time_t start,end;

  srand(time(NULL));

  retry = 0;
  do{
    value_init();

    random_init();
 
    inputcheck_func();

  }while(retry == 1);
//  }while(retry == 0); // こっちが正しい
  

  return 0;
}
