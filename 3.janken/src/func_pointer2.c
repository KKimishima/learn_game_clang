// 関数ポインタの引数を使った
// 網羅的な練習
//

#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int (*add)      (int,int);
  int (*plus)       (int,int);
  int (*multiplied) (int,int);
  int (*divided)    (int,int);
}calc;

typedef struct{
  int value1;
  int value2;
  int (*calc_func_p) (int value1,int value2);
} calc_menber;


int add(int value1,int value2){
  return value1 + value2;
}

int plus(int value1,int value2){
  return value1 + value2;
}

int minus(int value1,int value2){
  return value1 - value2;
}

int multiplied(int value1,int value2){
  return value1 * value2;
}

int divided(int value1,int value2){
  return value1 / value2;
}

// 関数ポインタから呼び出される
void hello(){
  puts("hello関数呼び出し");
  return;
}

// 関数ポインタ練習６(構造体メンバ)
void func_ponter6(){
  // 構造体宣言
  calc_menber data_value;
  // 戻り値
  int re_value;
  // スイッチ
  int sw;

  puts("演算を行う数値入力");
  printf("左辺:");  scanf("%d",&data_value.value1);
  printf("右辺:");  scanf("%d",&data_value.value2);

  puts("演算を行う数値入力");
  printf("足し算(0),引き算(1),掛け算(2),割り算(3):");
  scanf("%d",&sw);

  switch(sw){
    case 0:
      data_value.calc_func_p = plus;
      break;
    case 1:
      data_value.calc_func_p = minus;
      break;
    case 2:
      data_value.calc_func_p = multiplied;
      break;
    case 3:
      data_value.calc_func_p = divided;
      break;
    default:
      exit(1);
      break;
  }

  re_value = data_value.calc_func_p(data_value.value1,data_value.value2);

  printf("結果:%d\n",re_value);
}

// 関数ポインタ練習5(構造体)
void func_ponter5(){
  // 構造体の宣言
  calc data;
  // 戻り値
  int re_value;
  // 関数にスイッチする値
  //int sw;
  // 計算する数値
  int value1,value2;
  
  puts("演算を行う数値入力");
  printf("左辺:");  scanf("%d",&value1);
  printf("右辺:");  scanf("%d",&value2);

  // 配列は後でやる
  //printf("足し算(0),引き算(1),掛け算(2),割り算(3):");
  // scanf("%d",&sw);
  
  data.add = plus;
  // これだとぐっと理解しやすいな
  re_value = data.add(value1,value2);

  printf("結果:%d",re_value);

  return;
 
}

// 関数ポインタ練習4(配列)
void func_ponter4(){
  int (*func_p[])(int,int) = {plus,minus,multiplied,divided};
  // 戻り値
  int re_value;
  // 関数にスイッチする値
  int sw;
  // 計算する数値
  int value1,value2;
  
  puts("演算を行う数値入力");
  printf("左辺:");  scanf("%d",&value1);
  printf("右辺:");  scanf("%d",&value2);

  printf("足し算(0),引き算(1),掛け算(2),割り算(3):");
  scanf("%d",&sw);
  
  // 配列なんで引き渡ししなくてもOK
  re_value = (func_p[sw])(value1,value2);

  printf("結果:%d",re_value);

  return;
}

// 関数ポインタ練習3(仮引数あり)
void func_ponter3(){
  //int型の返り値と仮引数を持たせる
  int (*func_p)(int,int);
  // 返り値
  int re_value;
  // 仮引数
  int dummy_arg1 = 1;
  int dummy_arg2 = 2;

  // 参照関数引き渡し
  func_p = add;

  // 参照監修呼び出し
  re_value = (func_p)(dummy_arg1,dummy_arg2);
  printf("re_value = %d",re_value);

  return;
}
// 関数ポインタ練習2(省略)
void func_ponter2(){
  // いきなり宣言
  void (*func_p)() = hello;
  func_p();
  return;
}

int main(){
  // 関数ポインタ練習1(構文)
  //型(*変数名)(仮引数)
  void (*func_ponter1)();
  
  // 関数ポインタに参照関数引き渡し
  func_ponter1 = hello;

  // 関数ポインタにアクセス
  puts("関数ポインタ練習1(構文)");
  func_ponter1();
  
  puts("関数ポインタ練習2(省略)");
  func_ponter2();

  puts("関数ポインタ練習3(仮引数)");
  func_ponter3();

  puts("関数ポインタ練習4(配列)");
  func_ponter4();

  puts("関数ポインタ練習5(構造体)");
  func_ponter5();

  puts("関数ポインタ練習6(構造体メンバ)");
  func_ponter6();

  return 0;
}
