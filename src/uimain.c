#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char line[100];
  printf("Hello\n> ");
  fgets(line, sizeof(line), stdin);

  // printf("tests for word_start\n");
  // printf( &(*word_start(line)));
  // printf("after word_start");
  puts(line);
 done:
  return 0;
}
