/*
Q 是一个队列,S 是一个空栈,实现将队列中的元素逆置的算法
*/

#include "../include/queue.h"
#include "../include/stack.h"

void InverseQueue(Queue* Q, Stack* S) {
  // Step 1: Dequeue all elements from the queue and push them onto the stack
  while (!isEmpty(Q)) {
    int data = dequeue(Q);  // Dequeue element from the queue
    push(S, data);          // Push the element onto the stack
  }

  // Step 2: Pop all elements from the stack and enqueue them back into the
  // queue
  while (!isStackEmpty(S)) {
    int data = pop(S);  // Pop element from the stack
    enqueue(Q, data);   // Enqueue the element back into the queue
  }
}
