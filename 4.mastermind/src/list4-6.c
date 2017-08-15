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
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define NUBER_MAX 10  // 生成されるランダム数の限界(9だが+1)
#define DIGITS 4      // 出題数列の最大

void print_result(int *hit,int *blow){
  if(*hit == 4){
    puts("");
    puts("======================================");
    puts("--------------------------------------");
    puts("*************完全正解!!!**************");
    puts("************ゲームクリア**************");
    puts("--------------------------------------");
    puts("======================================");
    puts("");
  }else if(*hit == 0 && *blow == 0){
    puts("--------------------------------------");
    puts("************一致なし!!!***************");
    puts("--------------------------------------");
    puts("");
  }else {
    puts("--------------------------------------");
    printf("*****一致する数値:%d個があります******\n",*hit + *blow);
    if(*hit == 0){
      puts("**位置まで合っている数値がありません**");
      puts("--------------------------------------");
      puts("");
    }else{
      printf("**位置まで合っている数値%d:個あります**\n",*hit);
      puts("--------------------------------------");
      puts("");
    }
  }

  return;
}

// ヒットアンドブローチェック関数
void hitblow_check(const int *random_num,const int *input_num,int  *hit,int *blow){
  int i,j;
  
  //  ヒットアンドブローを初期化
  *hit  = 0;
  *blow = 0;

  for(i = 0;i < DIGITS;i++){              // 一重ループ:メイン.ランダム数値側
    for(j = 0;j < DIGITS;j++){            // 二重ループ:サブル.入力数側
      if(random_num[i] == input_num[j]){  // ランダムと入力比較
        if(i == j){
          *hit  += 1;
        }else{
          *blow += 1;
        }
      }
    }
  }


  return;
}

//数値を入力
int input_check(int *input_num,char *input_str){
  int   i,j;

  memset(input_num,0,DIGITS);
  memset(input_str,'0',strlen(input_str));
  
  puts("");
  puts("*====================================*");
  puts("四桁の数値を入力してください");
  puts("四桁以上の文字は無効になります!!!");
  puts("*====================================*");
  printf("数値:");
  fgets(input_str,sizeof(input_str) + 1,stdin); // 文字オーバを収納するため+1
 
  // 文字数が少ない場合
  if(strlen(input_str) <= 4){  //
    return 1;
   }

  // 文字数が多い場合
  if(strlen(input_str) > 5){  //
    while ( getchar()  !=  '\n');             // 入力バッファから,\nまで読み飛ばし
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
    input_num[i] = input_str[i]  - '0';
 //   input_num[i] = input_str[i] - '0';          // `0`を引いて数字キャストする
    for(j = 0;j< i ;j++){
      if(input_str[i] == input_str[j]){
        return 4;
      }
    }
  }

  return 0;
}

// インプットチェック関数
void input_value(int *input_num,char *input_str){
  int input_frag;                                // 判別フラグ変数

  do{
    input_frag =  input_check(input_num,input_str);
    puts("");
    switch(input_frag){
      case  0:  puts("*************入力成功*****************"); break;
      case  1:  puts("************文字数が少なすぎ**********"); break;
      case  2:  puts("**********文字数が多すぎです**********"); break;
      case  3:  puts("********文字に間違いがあります********"); break;
      case  4:  puts("*******同じ文字が含まれています*******"); break;
      default:  puts("**************入力エラー**************"); exit(1);  break;
    }
  }while(input_frag != 0);
    puts("");
  return;
}

// ランダム生成の初期化
void random_init(int *random_num){
  int i,j;
  int random_comp;                              // 比較変数を一時保存

  memset(random_num,0,DIGITS);                  // 0で初期化

  puts("ランダム数値の生成");
  // 重複のないランダムな数値の入力
  for(i = 0;i <= DIGITS ;i++){                  // 一重目のループ:配列の数だけ繰り返す
    do{                                         // 二重目のループ:基本配列数と検証入れうすう
      random_comp = 0 + rand() % NUBER_MAX; // 0~9までの乱数を比較用一時変数に収める+1する
      for(j = 0;j < i;j++){                     // 三重ループ:0(j)かカレント配列数(i)まで
        if(random_num[j] == random_comp){       // すでにデータが得られているか調べる
          break;                                // ブレイクするとwhileの条件で必ず弾かれるので
        }                                       // 正常な数値が入れまで繰り返される
      }
    }while(i > j );
    random_num[i] = random_comp;                // 確定した値を比較変数からぶっこむ
  }
}

int main(){
  int     random_num[DIGITS];
  int     input_num[DIGITS];
  char    input_str[DIGITS + 2];                  // 文字列のため+1と必ず改行コードを入れるため+1
  int     retry;
  int     count_turn;
  int     i;
  int     hit,blow;
  time_t  start,end;

  srand(time(NULL));


  start = time(NULL);
  retry = 0;
  count_turn =0;

  puts("######################################");
  puts("======================================");
  puts("-------マインド・ゲームスタート-------");
  puts("======================================");
  puts("######################################");

  do{

    start = time(NULL);
    retry = 0;
    count_turn =0;

    // ランダム生成関数
    random_init(random_num);
 
    // デバッグ用
    for(i = 0;i < DIGITS;i++){
      printf("%d",random_num[i]);
    }
    puts("");

    do{
      // 入力関数
      input_value(input_num,input_str);

      // ヒットアンドブロー確認チェック関数
      hitblow_check(random_num,input_num,&hit,&blow);
    
      // デバッグ用
//      printf("ヒット:%d,ブロー:%d\n",hit,blow);
      // 結果の表示関数
      print_result(&hit,&blow);

      count_turn++;
    }while(hit != 4);
    end =time(NULL);
    puts("================結果===================");
    printf("回答回数:%d回,経過時間:%ld秒***\n",count_turn,(end-start));
    printf("再度挑戦しますか\nリトライ...(1),ギブアップ...(0):");
    scanf("%d",&retry);
  }while(retry == 1);
//  }while(retry == 0); // こっちが正しい
  puts("======================================");
  puts("--------------ゲーム終了--------------");
  puts("---------------またね!!!--------------");
  puts("======================================");

//  end =time(NULL);

//  printf("***回答回数:%d回,経過時間:%ld秒***\n",count_turn,(end-start));

  return 0;
}
