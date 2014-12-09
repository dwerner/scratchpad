#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


typedef struct {
  long *id;
  void *data;
} Message;

Message * message_create() {
  return (Message*) malloc( sizeof(Message ) );
}

void message_destroy( Message * message ) {
  free( message );
}

typedef struct LinkedNode {
  struct LinkedNode *link;
  struct Message *message;
} LinkedNode;

LinkedNode * node_create() {
  LinkedNode *node = (LinkedNode*) malloc( sizeof(LinkedNode) );
  return node;
}

void node_destroy( LinkedNode* node ) {
  free( node );
}

typedef struct {
  struct LinkedNode *head;
  long length;
} LinkedQueue;

LinkedQueue * queue_create() {
  LinkedQueue *queue = (LinkedQueue*) malloc( sizeof(LinkedQueue) );
  return queue;
}

void queue_destroy( LinkedQueue *queue ) {
  free(queue);
}

void queue_enqueue( LinkedQueue *queue, LinkedNode *item ) {
  if (queue->head != NULL) {
    LinkedNode *head = queue->head;
    head->link = item;
  }
  queue->head = item;
}

LinkedNode * queue_dequeue( LinkedQueue *queue ) {
  LinkedNode *head = queue->head;
  queue->head = head->link;
  return head;
}

typedef struct {
  LinkedQueue *queue;
  pthread_mutex_t lock;
} Mailbox;

Mailbox * mailbox_create() {
  return (Mailbox*) malloc( sizeof(Mailbox) );
}

void mailbox_destroy(Mailbox *mailbox) {
  free( mailbox );
}


void func( void(*fun)() ) {
  fun();
}

void otherfunc() {
  printf("Herro func\n");
}

int main(int argc, const char ** argv) {
  func(&otherfunc);
  const char *one = argv[1];
  printf("%s\n", one);

  pthread_t threads[8];

  for (int i = 0; i < 8; i++) {
    
  }
}

