/*
设 C={a_1, b_1, a_2, b_2,......, a_n, b_n}
为线性表，采用带头结点的单链表存放，设计一个就地算法，将其拆分为两个线性表，使得
A={a_1, a_2,......, a_n}, B={b_n,......, b_2, b_1}
*/

/*
分析：
1.观察数据结构：C是线性表也就是数组，A 和 B 都是带头结点的单链表
2.遍历链表 C：从头到尾遍历链表 C，依次取出元素。
3.构建链表 A：将 a_i 元素依次插入到链表 A 的尾部。
4.构建链表 B：将 b_i 元素依次插入到链表 B 的头部（使用头插法），这样 B
的元素顺序会自动反转
5.其实就是考察了遍历以及初始化链表的两种方法——头插法和尾插法
*/

#include "LinkedList.h"

void SplitList(LinkedList* C, LinkedList* A, LinkedList* B) {
  // 初始化链表 A 和 B
  InitList(A);
  InitList(B);

  Node* current = C->head;
  int index = 1;

  while (current != nullptr) {
    if (index % 2 == 1) {
      // 插入到链表 A 的尾部
      Node* newNode = new Node();
      newNode->data = current->data;
      newNode->next = nullptr;

      if (A->head == nullptr) {
        A->head = newNode;
      } else {
        Node* tail = A->head;
        // 因为是单链表......
        while (tail->next != nullptr) {
          tail = tail->next;
        }
        tail->next = newNode;
      }
      A->size++;
    } else {
      // 插入到链表 B 的头部
      Node* newNode = new Node();
      newNode->data = current->data;
      newNode->next = B->head;
      B->head = newNode;
      B->size++;
    }

    current = current->next;
    index++;
  }
}
