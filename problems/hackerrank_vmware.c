#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  char ch;
  char prevChar;
  bool singleLineComment = false;
  bool multiLineComment = false;
  while((ch=getchar())!=EOF){

    if(singleLineComment){
      printf("%c ",ch);            
      if(ch == '\n'){singleLineComment = false;
      }
      continue;
    } 

    if(multiLineComment){
      if(ch == '*'){
        prevChar = ch;
        printf("%c ",ch);
        continue;
      }else{
        if(ch == '/' && prevChar == '*'){
          multiLineComment = false;
          printf("/\n");
          continue;
        }
      }
      printf("%c ",ch);
      continue;
    }        

    if(ch == '/'){

      char tempchar = ch;
      ch=getchar();            

      if(ch == '/'){
        singleLineComment = true;
        printf("//");
        continue;
      }

      if(ch == '*'){
        multiLineComment = true;
        printf("/*");
        continue;
      }                               
    }        
  }
  return 0;
}
