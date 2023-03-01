#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  printf("Hello, ");
  
  List *history = init_history();
  char line[100];
  char sentence[100];
  while(1) {
    printf("please enter the action you would like to take:\nTokenize(T)\nCheck History(H)\nAccess a specific history(!id) id is the id of the specific item\nQuit(Q)\n> ");
    fgets(line, sizeof(line), stdin);

    //printf("tests for word_terminator\n");
    //printf( &(*word_terminator(line)));
    //printf("after word_terminator");
    //count_words(line);
    //printf("there are: ");
    //int c = count_words(line);
    //printf("there are %d",c);
    //printf(" words\n");
    //char *out = copy_str(line, 5);
    //printf(out);
    //char** tokens = tokenize(line);
    //print_tokens(tokens);
    //puts(line);
    if(line[0] == 'T' || line[0] == 't') {
      printf("Please enter your sentence\n> ");
      fgets(sentence, sizeof(sentence), stdin);
      char **tokens = tokenize(sentence);
      print_tokens(tokens);
      add_history(history, sentence);
      printf("\n%sadded to history\n", sentence);
      free_tokens(tokens);
    }
    if(line[0] == 'H' || line[0] == 'h') {
      print_history(history);
    }
    if(line[0] == '!') {
      int id = atoi(line+1);
      char *hist = get_history(history, id);
      char **tokens = tokenize(hist);
      printf("You picked ID: %d\n", id);
      printf("History retrieved: %s\n", hist);
      printf("History tokenized: \n");
      print_tokens(tokens);
      free_tokens(tokens);
    }
    if(line[0] == 'Q' || line[0] == 'q') {
      goto done;
    }
    printf("\nWhat would you like to do next, ");
  }
 done:
  return 0;
}
