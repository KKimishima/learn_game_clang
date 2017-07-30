// 文字列を一文字ずつ表示して,
// 後ろから一文字ずつ消す
// それを繰り返す.
//
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define SLEEP_TIME_CONST 500                    // 表示を切り替える時間

// スリープタイム関数
int sleep_time(unsigned int wait_time){
  clock_t start_time;                           // スリープの始まり
  clock_t end_time;                             // スリープの終わり

  start_time = clock();                         // スリープ始まりの収納

  do{
    if((end_time = clock()) == ((clock_t) -1)){ // clock関数の失敗戻り値"((clock_t)-1)"が来たら終了
      puts("スリープタイム処理失敗");
      return -1;
    }
  }while((1000UL * (end_time - start_time)/CLOCKS_PER_SEC)  <= wait_time);  // 秒に変換して定数をかけて比較
  return 0;                                                                 // 最後の符号に注意"=<"
}

int main(){
  int i;
  int     display_index = 0;                      // 表示文字列の先頭
  char    display_str[] = "123456789 ";           // 表示する文字"判別のため空文字を最後入れる"
  int     display_str_len = strlen(display_str);  // 表示文字数

  while(1){
    putchar('\r');                              // カソールを行の頭に

    for(i = 0;i < display_str_len;i++){
      if(display_index + i < display_str_len){  // 文字数が先頭文字列より小さきとき
        putchar(display_str[i + display_index]);// 折り返しをせずに表示
      }else{
        putchar(display_str[(i + display_index) - display_str_len]);  //折り返して表示
      }
    }

      fflush(stdout);                           // 出力文字列の初期化
      sleep_time(SLEEP_TIME_CONST);             // スリープ関数

   if(display_index < display_str_len - 1){     // 先頭文字列が文字数("先頭分マイナス")と比較
    display_index++;                            // 先頭文字列をプラスして開始位置をずらす
   }else{
    display_index = 0;                          // 先頭文字列の初期化をおこない、一回目と同じ
   }                                            // 状態に戻す
  }
  return 0;
}
