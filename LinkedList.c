#include <stdio.h>
#include <string.h>

typedef struct item {
  int id;
  char *name;
  struct item *next;
} Item;

typedef struct list {
  struct item *last;
} List;

void addToList(List *list, char name[]) {
  int id = 0;
  Item *last = list->last;
  Item *item = (Item *)malloc(sizeof(Item));

  item->id = 0;
  item->name = name;

  if (last)
    item->id = last->id + 1;

  if (!last) {
    list->last = item;
    return;
  }

  item->next = last;
  list->last = item;
}

void showItem(Item *item) {

  printf("\nid - %i", item->id);
  printf("\nnome - %s\n", item->name);

  if (!item->next)
    return;
  return showItem(item->next);
}

void showList(List *list) {
  Item *last = list->last;
  if (!last) {
    printf("Lista vazia\n");
    return;
  }

  showItem(last);
}

void removeItem(List *list, Item *item) {
  if (!item) {
    printf("Lista vazia\n");
    return;
  }

  Item *next = item->next;

  if (!next) {
    list->last = NULL;
    return;
  }

  if (!next->next) {
    free(next);
    item->next = NULL;
    return;
  }

  return removeItem(list, next);
}

int main() {
  List *list = (List *)malloc(sizeof(List));

  addToList(list, "Guilherme");

  removeItem(list, list->last);
  removeItem(list, list->last);

  showList(list);

  printf("\n");
  return 0;
}