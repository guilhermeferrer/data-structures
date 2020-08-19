#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct item {
  int id;
  char *name;
} Item;

typedef struct queue {
  int first;
  int last;
  int size;
  Item **items;
} Queue;

Queue *initQueue(int QUEUE_SIZE) {
  Queue *queue = (Queue *)malloc(sizeof(queue));

  queue->first = 0;
  queue->last = 0;
  queue->size = QUEUE_SIZE;
  queue->items = (Item *)malloc(QUEUE_SIZE * sizeof(Item *));
  *(queue)->items = (Item **)malloc(QUEUE_SIZE * sizeof(Item **));

  return queue;
}

void pause() {
  printf("\n");
  system("read -n 1 -s -p \"Press any key to continue...\"");
}

bool isFull(Queue *queue) {

  int last = queue->last;
  int size = queue->size;

  if (last != size)
    return false;

  system("clear");
  printf("\nThe queue is full!\n");
  pause();
  return true;
}

bool isEmpty(Queue *queue) {

  int last = queue->last;
  int first = queue->first;

  if (last != first)
    return false;

  system("clear");
  printf("\nThe queue is empty!\n");
  pause();
  return true;
}

void addToQueue(Queue *queue) {
  Item *item = (Item *)malloc(sizeof(Item));
  item->name = (char *)malloc(sizeof(char) * 255);

  system("clear");
  printf("What's the name? ");
  scanf("%s", item->name);

  item->id = 0;
  if (queue->last)
    item->id = queue->items[queue->last - 1]->id + 1;

  queue->items[queue->last++] = item;
  system("clear");
  printf("%s added to queue!\n", item->name);
  pause();
}

void removeFromQueue(Queue *queue) {
  system("clear");
  Item *first = queue->items[queue->first];
  queue->items[queue->first++] = NULL;

  printf("%s removido com sucesso!\n", first->name);
  pause();
}

void listQueue(Queue *queue) {
  int last = queue->last;
  int first = queue->first;

  system("clear");
  printf("Queue description\n");

  for (int i = first; i < last; i++) {
    Item *item = queue->items[i];

    printf("\nName: %s\n", item->name);
    printf("Id: %i\n", item->id);
  }
  pause();
}

void menu(Queue *queue) {
  bool exit = false;

  while (!exit) {
    int op = 0;

    system("clear");
    printf("Menu\n\n");
    printf("1 - Add to Queue\n");
    printf("2 - Remove from Queue\n");
    printf("3 - List Queue\n");
    printf("Press any other key to exit\n");
    printf("\n");
    printf("Choose an option: ");
    scanf("%i", &op);

    switch (op) {
    case 1:
      if (!isFull(queue))
        addToQueue(queue);
      break;
    case 2:
      if (!isEmpty(queue))
        removeFromQueue(queue);
      break;
    case 3:
      if (!isEmpty(queue))
        listQueue(queue);
      break;
    default:
      exit = true;
      break;
    }
  }
}

int main() {
  int QUEUE_SIZE = 0;

  system("clear");
  printf("What's the queue size? ");
  scanf("%i", &QUEUE_SIZE);

  Queue *queue = initQueue(QUEUE_SIZE);

  menu(queue);

  printf("\n");
  return 0;
}