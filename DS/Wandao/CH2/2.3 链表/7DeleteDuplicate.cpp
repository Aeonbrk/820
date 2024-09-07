/*
在一个递增有序的单链表中，存在重复的元素。设计一个算法删除重复的元素，例如
（ 7， 10 ，10 ， 21 ， 30 ， 42 ， 42 ， 42 ， 51 ， 70 ）将变为
（ 7 ， 10 ， 21， 30 ， 42 ， 51 ， 70 ）。
*/

/*
分析：
1.数据结构：单调有序增加的单链表 （假设有头结点，没有头结点思想类似）
2.遍历链表，使用两个指针：current 和 prev。
3.current 指向当前节点，prev 指向前一个节点。
  如果 current 的值与 prev 的值相同，则删除 current 节点。
  如果 current 的值与 prev 的值不同，则继续遍历
*/

#include "../include/LinkedList.h"

void DeleteDuplicate(LinkedList* L) {
  if (L == nullptr || L->head == nullptr) {
    return;  // 链表为空或链表头为空，直接返回
  }

  Node* current = L->head->next;  // 当前节点从第二个节点开始
  Node* prev = L->head;           // 前一个节点从第一个节点开始

  while (current != nullptr) {
    if (current->data == prev->data) {
      // 发现重复元素，删除当前节点
      prev->next = current->next;
      delete current;
      current = prev->next;
      L->size--;  // 更新链表大小
    } else {
      // 没有重复元素，继续遍历
      prev = current;
      current = current->next;
    }
  }
}
