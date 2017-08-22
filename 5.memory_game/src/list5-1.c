/*  0.5秒だけ4文字を表示し,
    その値をキーボードから打ち込む
    これを10回繰り替えて、正しく正解でききた回数と時間を表示する
*/

#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define NUMBER_MAX  4
#define INPUT_MAX   254

enum input_stauts {
  SMALL_VALUE = 0,
  OVER_VALUE,
  EXCE_VALUE,
  OK,
};

int input_check(char input_str[]){
  int i;

 if (INPUT_MAX -1 == strlen(input_str)){
    puts("オーバフローの危険検出\n強制終了");
    exit(1);
  }

  for (i = 0;i < NUMBER_MAX;i++) {
   if(0 == isdigit(input_str[i])){
     return EXCE_VALUE;
   }
  }
 
  if(4 >= strlen(input_str)){
    return SMALL_VALUE;
  }

  if(6 <= strlen(input_str)){
    return OVER_VALUE;
  }

  return OK;
}

void player_input(int input_value[]){
  int i;
  char input_str[INPUT_MAX];
  int input_frag;

  do {
    memset(input_str,'\0',strlen(input_str));
    memset(input_value,0,NUMBER_MAX);
 
    fgets(input_str,sizeof(input_str),stdin);
  
    input_frag = input_check(input_str);
  
    switch (input_frag) {
      case SMALL_VALUE: printf("判別:小さすぎ\n入力は:");            break;
      case OVER_VALUE:  printf("判別:大きすぎです\n入力は:");        break;
      case EXCE_VALUE:  printf("判別:文字が入力されまいた\n入力は:");break;
      case OK:          puts("判別:OK");                  break;
      default:          puts("異常な値です");             break;
    }

  } while (input_frag != OK);
  
  for(i = 0;i < NUMBER_MAX;i++){
    input_value[i] = input_str[i] -'0';
  }

  return;
}

int sleep(unsigned long sleep_time){
  clock_t star_clock,end_clock;
  
  star_clock = clock();
 
  do {
    if( (end_clock = clock()) == ((clock_t) -1) ){return -1;}
  } while ( (1000UL *( (end_clock -star_clock) / CLOCKS_PER_SEC) ) < sleep_time );

  return 0;
}

void display(int display_num[]){
  int i;

  for (i = 0;i < NUMBER_MAX;i++ ) {
    display_num[i] = 0 + rand() % 10;
  }

  return;
}

int main(){
  int     i;
  int     count_stage;
  time_t  start_time,end_time;
  int     display_num[NUMBER_MAX];
  int     sleep_check;
  int     input_value[NUMBER_MAX];

  time(&start_time);
  srand(time(NULL));
  
  puts("単純記憶トレーニンゲーム");
  puts("スタート");
  
  
  count_stage = 0;
  do {
    printf("%d回目表示\n",count_stage + 1);
    display(display_num);

    for (i = 0;i < NUMBER_MAX;i++) {
      printf("%d",display_num[i]);
    }
    fflush(stdout);
    
    sleep_check =sleep(500);
    if(sleep_check == -1){
      puts("スリープ処理失敗\n強制終了");
      exit(1);
    }
  
    printf("\r入力は:");

    player_input(input_value);
    
    puts("入力テスト");
    for(i = 0;i < NUMBER_MAX;i++){
      printf("%d",input_value[i]);
    }
    puts("");

    count_stage++;
  } while (count_stage !=  10);
  
  time(&end_time);
  printf("結果...時間:%d秒\n",(int)difftime(end_time,start_time));
  return 0;

}
