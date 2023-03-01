#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int debug = 0;

//returns 1 if c is a white space
int space_char(char c)
{
  return (c == ' ' || c == '\t');
}
//returns 1 if c is a non white space, non zero character
int non_space_char(char c)
{
  return !(space_char(c) == 1 || c == '\0');
}
//returns a pointer to the first character of the next word 
char *word_start(char *str)
{
  //printf("I start\n");
  while (space_char(*str)) {
    if (debug) printf("i get to here\n");
      str += 1;
  }
  if (debug) printf("i get out of the loop\n");
  if(non_space_char(*str))  {
    // printf(str);
    return str;
  }
  return 0;
}

char *word_terminator(char *word)
{

  while(non_space_char(*word)) 
    word ++;
  return word;
}

int count_words(char *str)
{
  int count = 0;
  //printf("%d\n", count);
  while (str) {
    str = word_start(str);
    if (str) {
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
  char *newStr = malloc((len+1) * sizeof(char));
  char *newStrCursor = newStr;
  for (int i = 0; i < len; i++) {
    *newStrCursor = *inStr;
    newStrCursor++; inStr++;  
  }
  *newStrCursor = '\0';
  return newStr;
}

char **tokenize(char *str)
{
  //printf("Tokenize runs");
  int word_count = count_words(str);
  char **tokens = (char**)malloc((word_count+1) * sizeof(char*));
  char **tokensCursor = tokens;
  char *end = str;
  //printf("before for loop");
  for (int i = 0; i < word_count; i++) {
      //printf("start\n");
      str = word_start(end);
      //printf("word\n");
      end = word_terminator(str);
      //printf("end\n");
      //tokens[i] = copy_str(str, end-str);
      //printf(tokens[i]);
      *tokensCursor = copy_str(str, end-str);
      *tokensCursor++;
    }
  *tokensCursor = '\0';
  //tokens[word_count] = '\0';
  return tokens;
}

void print_tokens(char **tokens)
{
  for(int i = 0; tokens[i]; i++) {
    printf("\n%s", tokens[i]);
  }
}

void free_tokens(char **tokens)
{
  for (int i = 0; tokens[i]; i++) {
    free(tokens[i]);
  }
  free(tokens);
}
