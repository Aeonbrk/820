/*
在带头结点的单链表 L 中，删除所有值为 x 的结点，并释放其空间，假设值为 x
的结点不唯一;
试编写算法以实现上述操作。
*/

#include "../include/LinkedList.h"

// 删除链表中所有值为x的节点
void DelAllX(LinkList &L, ElemType x) {
  // 如果链表为空，直接返回
  if (L == NULL) return;

  // 初始化前驱节点和当前节点
  LNode *pre = L;      // 前驱节点
  LNode *p = L->next;  // 当前节点

  // 遍历链表
  while (p != NULL) {
    // 如果当前节点的值等于x
    if (p->data == x) {
      // 将前驱节点的next指向当前节点的next
      pre->next = p->next;
      // 释放当前节点的内存
      free(p);
      // 更新当前节点为前驱节点的next
      p = pre->next;
    } else {
      // 如果当前节点的值不等于x，更新前驱节点和当前节点
      pre = p;
      p = p->next;
    }
  }
}
