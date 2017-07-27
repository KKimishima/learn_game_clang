// C言語の時間処理

#include<stdio.h>
#include<time.h>

// 停止関数(xミリ秒待つ)
int sleep(unsigned long wait_time){
  clock_t start_time;
  clock_t end_time;  // 終わりの始まりの宣言
  
  start_time = clock();  // 始まりの初期化
  
  //【戻り値】: clock()
  // 正常時   ：  プログラム実行開始からの経過時間（プロセッサ時間）
  // エラー時 ：  (clock_t)-1 (clock_t)型でキャストされた-1
  do{
    if((end_time = clock()) == (clock_t)-1){ return -1; } // エラーの際の処理
    // 引数の単に合わせてるために1000をかけている
    // ULをつけて"double"型であることをキャストしておく
  } while ((1000UL * (end_time - start_time) / CLOCKS_PER_SEC) <= wait_time);
  //} while (((double) (end_time - start_time) / CLOCKS_PER_SEC) <= wait_time);
  return 0;
}

int main(){
  int i;
  clock_t time;           //時間のデータ型

  for(i = 10;i > 0;i--){  //カウントダウン
    printf("\r%2d",i);    //"\r"前の表示を書き換え
    fflush(stdout);       //"\r"で溜まったバッファを初期化
    sleep(1000);          // 一秒ごと
  }
  
  printf("\r処理終了\n");
  
  time = clock();

  printf("clockの中身:%f\n",(double)time);
  // CPUの時間を使用した時間を求める
  // プログラムが起動してからの経過時間を返す
  printf("CLOCKS_PER_SECの中身:%d\n",CLOCKS_PER_SEC);
  // CLOCKS_PER_SECは割ると秒数が算出できる定数である
  // OSによって定数が異なるみたいだが,UNIXでは1000000と定義されている
  printf("終了までに%.1fかかりました\n",(double)time / CLOCKS_PER_SEC);
  
  printf("Enterｷｰを押下して下さい。\n");
  getchar(); /* エンターキー押下待機 */

  return 0;
}
