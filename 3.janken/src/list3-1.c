// じゃんけんゲームのその一
// 簡単な実装
//

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define INPUT_DIGITST 2 // 入力桁数('\0')を含めて
#define INPUT_MAX     3 // 最大数
#define INPUT_MIN     1 // 最小数

// 結果のフラグ
// 入力判定で0を使ってしまったので,
// 自動振り分けでなく手動で1,2,3にしている
enum input_enum{
  junken_goo = 1,         //グー
  junken_cho = 2,         // チョキ
  junken_paa = 3,         // パー
};

enum result_enum{
  draw,
  loss,
  win,
};
// 入力関数
int input_func(){
  char  input_str[INPUT_DIGITST];
  int   input_number;

  while(1){
    printf("じゃんけん:");
  
    fgets(input_str,sizeof(input_str),stdin);             // キーボードからの文字列入力

    input_number = atoi(input_str);
  
    if(input_number == 0){
      puts("入力エラー\n整数を入力してください");
      while(getchar() != '\n');                           // 空になるまで読み飛ばし
      } else if(input_number >= 1 && input_number <= 3){  // 1から3までの入力判別
        return input_number;
      } else {
      puts("入力範囲外です\n入力範囲内で入力してください");
      while(getchar() != '\n');                           // 空になるまで読み飛ばし
    }

//    if(input_number == 0){
//      puts("入力エラー\n整数を入力してください");
//      while(getchar() != '\n');               // 空になるまで読み飛ばし
//      } else if(input_number >= 0 && input_number <= 3){
//      puts("入力範囲外です\n入力範囲内で入力してください");
//      while(getchar() != '\n'); 
//    } else {
//      return input_number;
//    }
  }
}

int main(){
  int junken_input;   // 人間が入力
  int junke_ans;      // コンピュータが生成する答え
  int junke_result;   // 勝敗結果
  int retry;          // 再戦フラグ

  srand(time(NULL));  // ランダムの種生成

  // メッセージ
  puts("じゃんけんゲームを開始致します");
  puts("最初はグー、じゃんけんポイ!!!");
  puts("グー....(1)\nチョキ...(2)\nパー....(3)\n");
  
  junken_input = input_func();

  puts("");           // わかりやすいように改行
  // じゃんけん入力表示
  switch (junken_input){
    case junken_goo:
      puts("じゃんけん入力:グー");
      break;
    case junken_cho:
      puts("じゃんけん入力:グー");
      break;
    case junken_paa:
      puts("じゃんけん入力:グー");
      break;
    default:
      puts("入力失敗");
      exit(1);
      break;
  }

  junke_ans = 1 + rand() % 3;                       //答えの生成
  junke_result = (junken_input - junke_ans + 3) % 3;//答えの判定
  
  // じゃんけん結果表示
  switch (junke_result){
    case draw:
      puts("引き分けです");
      break;
    case loss:
      puts("負けです");
      break;
    case win:
      puts("勝ちです");
      break;
    default:
      puts("結果エラー");
      break;
  }

  return 0;
}
