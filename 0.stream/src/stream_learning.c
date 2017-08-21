// 標準ストリームの実験

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int main(){
  char  stream_in_str[5];
  int   ch = 1;
  char  *stream_in_str_p;
  int   c = 'a';

  puts("四文字を入力してください");
  do {
    // 文字列の初期化
    memset(stream_in_str,'\0',sizeof(stream_in_str));
    
    printf("入力:");
    fgets(stream_in_str, sizeof(stream_in_str), stdin);
    
    printf("出力:%s\n",stream_in_str);

    stream_in_str_p = strchr(stream_in_str,c);


    while(getchar() == '\0')
    if(stream_in_str_p != NULL){
      puts("ヒット");
      printf("改行までの文字:%ld\n",stream_in_str_p - stream_in_str + 1);
    }else{
      puts("ノーヒット");
    }


    printf("文字カウント:%lu\n",strlen(stream_in_str));
    puts("");
    puts("");

//    if( 3 == strlen(stream_in_str)){
//      puts("バッファ切り捨て");
//      while (getchar() != '\n');
//      puts("");
//    }
    
  } while (ch != 0);
    return 0;
}
