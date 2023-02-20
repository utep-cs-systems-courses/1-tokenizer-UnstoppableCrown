#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

//returns 1 if c is a white space
int space_char(char c)
{
  if(c == ' ' || c == '\t')
    {
      return 1;
    }
  return 0;
}
//returns 1 if c is a non white space, non zero character
int non_space_char(char c)
{
  if(space_char(c) == 1 || c == '\0')
    {
      return 0;
    }
  return 1;
}
//returns a pointer to the first character of the next word 
char *word_start(char *str)
{
  //printf("I start\n");
  while(space_char(*str))
    {
      //  printf("i get to here\n");
      str += 1;
    }
  // printf("i get out of the loop\n");
  if(non_space_char(*str))
    {
      // printf(str);
      return str;
    }
  return 0;
}

char *word_terminator(char *word)
{

  while(non_space_char(*word))
    {
      word += 1;
    }
  
  if(space_char(*word))
    {
      return word;
    }
  return 0;
}

int count_words(char *str)
{
  int escape = 0;
  int count = 0;
  //printf("%d\n", count);
  while(str)
    {
      str = word_start(str);
      if(str)
	{
	  count += 1;
	  str = word_terminator(str);
	  //printf("count is at: %d\n", count);
	  //printf(&(*str));
	  
	}
    }
  
  return count;
}

char *copy_str(char *inStr, short len)
{

}

char **tokenize(char* str)
{

}

void print_tokens(char **tokens)
{

}

void free_tokens(char **tokens)
{

}
