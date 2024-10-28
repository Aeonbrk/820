#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

// Define the structure for a queue node
typedef struct QueueNode {
  int data;
  struct QueueNode* next;
} QueueNode;

// Define the structure for the queue
typedef struct {
  QueueNode* front;
  QueueNode* rear;
  int size;
} Queue;

// Function prototypes
Queue* createQueue();
bool isEmpty(Queue* queue);
void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
int peek(Queue* queue);
void destroyQueue(Queue* queue);

#endif  // QUEUE_H
