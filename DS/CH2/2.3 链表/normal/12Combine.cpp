/*
有两个循环单链表，链表头指针分别为 h1 和 h2 ，编写一个函数将链表 h2 链接到链表
h1 之后，要求链接后的链表仍保持循环链表形式
*/

#include "../include/LinkedList.h"

void Combine(Node* h1, Node* h2) {
  // 如果任一链表为空，则无需合并
  if (h1 == nullptr || h2 == nullptr) {
    return;
  }

  // 找到 h1 的尾节点
  Node* rear_h1 = h1;
  while (rear_h1->next != h1) {  // 循环链表的尾节点的 next 指向头节点
    rear_h1 = rear_h1->next;
  }

  // 找到 h2 的尾节点
  Node* rear_h2 = h2;
  while (rear_h2->next != h2) {  // 循环链表的尾节点的 next 指向头节点
    rear_h2 = rear_h2->next;
  }

  // 将 h2 链接到 h1 之后
  rear_h1->next = h2;  // h1 的尾节点指向 h2 的头节点
  rear_h2->next = h1;  // h2 的尾节点指向 h1 的头节点，形成循环
}
