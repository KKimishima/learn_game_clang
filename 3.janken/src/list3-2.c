// じゃんけーム2
// 両者の手を見せる
//
// 今回は素直にscanfを使う

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// じゃんけん結果を表示待たせる関数
int sleep(unsigned long wait_time){
  clock_t start_time;
  clock_t end_time;

  start_time = clock();

 do{
  if ((end_time = clock()) == (clock_t) -1){return -1;} //エラー時の処理
 }while((1000UL * (end_time - start_time))/ CLOCKS_PER_SEC <= wait_time);
 
 return 0;
}


// じゃんけんの手を表示する関数
void goo(){
  puts("じゃんけん!!!:ぐー");
}

void chek(){
  puts("じゃんけん!!!:チョキ");
}

void paa(){
  puts("じゃんけん!!!:パー");
}

// じゃんけんの勝敗を表示する関すう
void draw(){
  puts("引き分けです!!!");
}

void loss(){
  puts("負けです!!!");
}

void win(){
  puts("勝ちです!!!");
}

int main(){
  // じゃんけん判別関数
  void  (*jenken_func_p[6])() = {
    goo,
    chek,
    paa,
    draw,
    loss,
    win
  };

  int     junken_input;           // じゃんけん入力
  int     junken_ans;             // 生成されたじゃんけんの手
  int     retry;                  // リトライフラグ
  int     result;                 // じゃんけんの勝敗

  srand(time(NULL));  // 乱数種生成

  puts("じゃんけんゲーム開始!!!");

  do{                 // じゃんけん繰り返し
    
    junken_ans = 0 + rand() % 2;  // 0から2までの生成
    
    // じゃんけん入力
    puts("\nじゃんけん入力開始");
    puts("じゃんけんぽん");
    do{     
      printf("グー..(0),チョキ..(1),パー..(2):");
      scanf("%d",&junken_input);
    }while(junken_input < 0 || junken_input > 2);

    // 表示まち関数
    sleep(1000);
    puts("私の入力は:");
    // 関数ポインタ呼び出し
    jenken_func_p[junken_input]();

    sleep(1000);
    puts("相手の入力は");
    // 関数ポインタ呼び出し
    jenken_func_p[junken_ans]();
  
    // じゃんけん判別処理
    result = (junken_input - junken_ans + 3) % 3;

    puts("勝敗は");    
    sleep(3000);
    // 関数ポインタに配列用を渡すため "+2"している
    jenken_func_p[result +3]();

    printf("もう一度行いますか\nはい(1)...いいえ(0)");
    scanf("%d",&retry);
  }while(retry == 1);

  return 0;
}
