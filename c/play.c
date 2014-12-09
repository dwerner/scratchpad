#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


typedef struct {
  long *id;
  void *data;
} Message;

Message * message_create() {
  Message *message = (Message*) malloc( sizeof(Message ) );
  return message;
}

void message_destroy( Message * message ) {
  if ( message != NULL ) {
    free( message );
  }
}

typedef struct LinkedNode {
  struct LinkedNode *link;
  Message *message;
} LinkedNode;

LinkedNode * node_create(Message *message) {
  LinkedNode *node = (LinkedNode*) malloc( sizeof(LinkedNode) );
  node->message = message;
  return node;
}

void node_destroy( LinkedNode* node ) {
  if ( node != NULL ) {
    message_destroy( node->message );
    free( node );
  }
}

typedef struct {
  LinkedNode *head;
  long length;
} LinkedQueue;

LinkedQueue * queue_create() {
  LinkedQueue *queue = (LinkedQueue*) malloc( sizeof(LinkedQueue) );
  return queue;
}

void queue_destroy_nodes( LinkedNode *head ) {
  if ( head != NULL ) {
    LinkedNode *parent = head;
    while ( parent->link != NULL ) {
      LinkedNode *link = parent->link;
      node_destroy( parent );
      parent = link;
    }
  }
}

void queue_destroy( LinkedQueue *queue ) {
  if ( queue != NULL ) {
    queue_destroy_nodes( queue->head );
  }
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
  Mailbox *mailbox = (Mailbox*) malloc( sizeof(Mailbox) );
  mailbox->queue = queue_create();
  return mailbox;
}

void mailbox_put( Mailbox *mailbox, Message *message ) {
  pthread_mutex_lock( &mailbox->lock );
  LinkedNode *node = node_create( message );
  queue_enqueue( mailbox->queue, node );
  pthread_mutex_unlock( &mailbox->lock );
}

Message * mailbox_get( Mailbox *mailbox ) {
  pthread_mutex_lock( &mailbox->lock );
  LinkedNode *node = queue_dequeue( mailbox->queue );
  pthread_mutex_unlock( &mailbox->lock );
  return node->message;
}

void mailbox_destroy(Mailbox *mailbox) {
  if ( mailbox != NULL ) {
    queue_destroy( mailbox->queue );
    pthread_mutex_destroy( &mailbox->lock );
    free( mailbox );
  }
}

void lock( pthread_mutex_t *mutex ){
  if ( pthread_mutex_trylock(mutex) ) {

  }
}

typedef struct {
  void *data;
} Future;

typedef struct {
  Mailbox *mailbox;
  Future(*send)(Message*);
} Actor;


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

