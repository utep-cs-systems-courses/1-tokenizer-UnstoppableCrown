#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

//returns 1 if c is a white space
int space_char(char c)
{
  if(c == " " || c == "\t")
    {
      return 1;
    }
  return 0;
}

int non_space_char(char c)
{
  
}

char *word_start(char *str)
{
  
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