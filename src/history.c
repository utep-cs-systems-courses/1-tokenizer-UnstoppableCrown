#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List *init_history()
{
  List *list = malloc(sizeof(List));
  list->root = malloc(sizeof(Item));
  return list;
}

void add_history(List *list, char *str)
{
  int id = 1;
  Item *temp = list->root; 
  while (temp->next) {
    temp = temp->next;
    id++;
  }
  //printf("%d", id);
  temp->next = malloc(sizeof(Item));
  temp->next->str = str;
  temp->next->id = id;
  //printf("\n%s", temp->next->str);
  
}

char *get_history(List *list, int id)
{
  Item *temp = list->root;
  while (temp) {
    if(temp->id == id) {
      return temp->str;
    }
    temp = temp->next;
  }
}

void print_history(List *list)
{
  Item *temp = list->root->next;
  while(temp) {
    printf("%d. %s", temp->id, temp->str);
    temp = temp->next;
  }
}

void free_history(List *list)
{

}
