// じゃんけーム2
// 両者の手を見せる
//
// 今回は素直にscanfを使う

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 列挙体
// じゃんけんの手
enum junke_patten{
  junken_goo,
  junken_choki,
  junken_paa,
};
// じゃんけん結果
enum junken_result{
  win,
  loss,
  draw,
};


int main(){
  int junken_input;   // じゃんけん入力
  int junken_ans;     // 生成されたじゃんけんの手
  int retry;          // リトライフラグ

  srand(time(NULL));  // 乱数種生成

  puts("じゃんけんゲーム開始!!!");

  do{                 // じゃんけん繰り返し
    
    junken_ans = 0 + rand() % 2;  // 0から2までの生成
    
    // じゃんけん入力
    puts("\nじゃんけん入力開始");
    puts("じゃんけんぽん");
    do{     
      puts("グー..(0),チョキ..(1),パー..(2)");
      scanf("%d",&junken_input);
    }while(junken_input < 0 || junken_input > 2);

    puts("私の入力は");

  }while();

  return 0;
}
