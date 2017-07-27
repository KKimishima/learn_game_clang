// 時間処理も用いた,暗記トレーニンぐ
// 3三桁の整数を３つ加える
//
// gccでは、clockはcpuの実行時間なので
// 入力まち時間は含まれないので今回のプログラム
// timeでやること

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SUM_ELEMENT 3               // 足し算する要素数
#define SUM_DIGITST 5               // 足し算の桁数
#define SUM_MIN     300             // 足し算の最小値
#define SUM_MAX     2700            // 足し算の最大
#define SUM_CALC(x,y,z)(x + y + z)  // 足し算マクロ

// 入力関数A
int input_value(){                
  int     input_number;             // 変換数値
  char    input_str[SUM_DIGITST];     // 入力文字列
  time_t start_time,end_time;

  start_time = time(NULL);

  puts("合計数値を入力してください");
  while(1){
    printf("合計値:");
    fgets(input_str,sizeof(input_str),stdin);

    input_number = atoi(input_str); // 文字列から数値に変換

    if(input_number == 0){
      puts("入力エラーです");
      while(getchar() != '\n');      // 空になるまで読み飛ばし
    }else if(input_number <= SUM_MIN && input_number >= SUM_MIN){
      puts("異常な数値です");
      while(getchar() != '\n');      // 空になるまで読み飛ばし
    }else{
      return input_number;  
    }
  }
}

int main(){
  int     add_number;           // 加算する数値
  int     read_value,i;         // 読み込み値
  int     *add_number_p;        // 動的配列用ポインタ
  time_t  start_time,end_time;  // 開始時刻,終了時刻
  double  lapsed_time;          // 経過時間

  add_number_p = (int *)malloc(sizeof(int) * SUM_ELEMENT);
  if(add_number_p == NULL){
    puts("メモリ確保失敗!!!");
    exit(1);
  }

  srand(time(NULL));            // 乱数の種の生成

  for(i = 0;i < SUM_ELEMENT;i++){
   add_number_p[i] = 100 + rand() % 900; //100~900までの乱数作成
   }

  printf("%d + %d + %d の合計はなんですか\n",add_number_p[0],add_number_p[1],add_number_p[2]);

  start_time = time(NULL);      // 測定開始

  while(1){                     // 正解判別関数
    read_value = input_value(); // 入力関数呼び出し
    if(read_value == SUM_CALC(add_number_p[0],add_number_p[1],add_number_p[2])){
      break;
    }else{
      puts("違います!!!\n再度入力してください");
    }
  }

  end_time = time(NULL);        // 測定終了
  
  lapsed_time = (double)(end_time - start_time); // キャストして時間を実数

  printf("%.1f秒かかりました\n",lapsed_time);
  
  if(lapsed_time > 30){
    puts("遅すぎです!!!");
  }else if(lapsed_time > 17){
    puts("なかなかの結果です");
  }else{
    puts("早いです");
  }

 free(add_number_p);
 return 0;
}

