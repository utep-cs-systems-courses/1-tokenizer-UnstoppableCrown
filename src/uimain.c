#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char line[100];
  printf("Hello\n> ");
  fgets(line, sizeof(line), stdin);
  puts(line);
 done:
  return 0;
}
