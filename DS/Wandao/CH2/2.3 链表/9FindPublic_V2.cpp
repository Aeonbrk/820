/*
己知两个链表 A 和 B 分别表示两个集合，其元素递增排列。
编制函数，求 A 与 B 的交集，并存放于 A 链表中。
*/

/*
分析：
1.数据结构：（有头结点的）递增有序的单链表
2.思想：和 8FindPublicAndCombine.cpp 类似，找公共结点，但不同的是存放在 A 中
  - 双指针，遍历比较（都是递增）
  - 若不同，则当场就把比较的 A 的结点删掉
*/

#include "../include/LinkedList.h"

// GPT add comments...
void FindPublic_V2(const LinkedList* B, LinkedList* A) {
  // 边界条件检查：如果 A 或 B 为 nullptr，直接返回
  if (A == nullptr || B == nullptr) {
    return;
  }

  // 初始化指针
  Node* current_A = A->head->next;  // 指向 A 的第一个节点
  Node* current_B = B->head->next;  // 指向 B 的第一个节点
  Node* pre_A = A->head;  // 用于追踪 A 中前一个节点，用于删除操作

  // 开始遍历两个链表，直到其中一个链表遍历结束
  while (current_A != nullptr && current_B != nullptr) {
    if (current_A->data == current_B->data) {
      // 如果 A 和 B 的当前节点值相等，移动 A 和 B 的指针
      pre_A = current_A;
      current_A = current_A->next;
      current_B = current_B->next;
    } else if (current_A->data < current_B->data) {
      // 如果 A 的当前节点值小于 B 的当前节点值，说明 A
      // 的该节点不在交集中，需要删除
      pre_A->next = current_A->next;  // 跳过 current_A 节点
      delete current_A;               // 删除当前节点
      current_A = pre_A->next;        // 更新 current_A 为下一个节点
    } else {
      // 如果 A 的当前节点值大于 B 的当前节点值，说明 B 的该节点不在交集中，移动
      // B 的指针
      current_B = current_B->next;
    }
  }

  // 当遍历结束时，如果 A 链表仍然有剩余节点，它们不属于交集，需要逐一删除
  while (current_A != nullptr) {
    pre_A->next = current_A->next;  // 跳过 current_A 节点
    delete current_A;               // 删除当前节点
    current_A = pre_A->next;        // 更新 current_A 为下一个节点
  }
}
