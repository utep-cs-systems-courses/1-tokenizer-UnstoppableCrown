#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char line[100];
  printf("Hello\n> ");
  fgets(line, sizeof(line), stdin);

  printf("tests for word_terminator\n");
  printf( &(*word_terminator(line)));
  printf("after word_terminator");
  //count_words(line);
  //printf("there are :");
  //int c = count_words(line);
  //printf("%d",c);
  //printf("words\n");
  puts(line);
 done:
  return 0;
}
