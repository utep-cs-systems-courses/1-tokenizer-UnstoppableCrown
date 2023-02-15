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
  if(space_char(c) == 1 || c == '0')
    {
      return 0;
    }
  return 1;
}
//returns a pointer to the first character of the next word 
char *word_start(char *str)
{
  for(int i = 0; *(str +1) != '\0'; i++)
    {
      if(non_space_char(*str))
	{
	  return &*str;
	}
      *str = *(str + i);
    }
      return 0;
}

char *word_terminator(char *word)
{

}

int count_words(char *str)
{

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
