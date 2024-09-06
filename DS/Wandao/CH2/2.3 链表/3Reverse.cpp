/*
试编写算法将带头结点的单链表就地逆置，所谓“就地”是指辅助空间复杂度为 O(I)
*/

#include "../include/LinkedList.h"

void Reverse(LinkedList* list) {
  // 如果链表为空或链表头为空，直接返回
  if (list == NULL || list->head == NULL) return;

  Node* prev = NULL;                 // 前一个节点
  Node* current = list->head->next;  // 当前节点
  Node* next = NULL;                 // 下一个节点

  while (current != NULL) {
    next = current->next;  // 存储下一个节点
    current->next = prev;  // 反转当前节点的指针
    prev = current;        // 向前移动指针
    current = next;
  }
  list->head->next = prev;  // 更新链表头
}
