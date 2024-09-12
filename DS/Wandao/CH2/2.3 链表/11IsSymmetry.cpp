/*
设计一个算法用于判断带头结点的循环双链表是否对称
*/

/*
分析：
1. 显然头尾各一个指针分别向前向后遍历比对
*/

#include "../include/CDLinkedList.h"

/**
 * IsSymmetry - 判断循环双链表是否对称。
 * @L: 指向循环双链表的指针。
 * @return: 如果对称返回true，否则返回false。
 */
bool IsSymmetry(const CircularDoublyLinkedList* L) {
  if (L->head == nullptr) {
    return true;  // 空链表视为对称
  }

  Node* front = L->head;
  Node* rear = L->head->prev;

  // 遍历链表，直到两个指针相遇
  while (front != rear && front->prev != rear) {
    if (front->data != rear->data) {
      return false;  // 发现不对称元素
    }
    front = front->next;
    rear = rear->prev;
  }

  return true;  // 所有元素对称
}
