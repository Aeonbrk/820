/*
设 A 和 B 是两个单链表（带头结点），其中元素递增有序。
设计一个算法从 A 和 B 中的公共元素产生单链表 c ，要求不破坏 A, B 的结点
*/

/*
分析：
1.数据结构：带头结点的递增有序的单链表
2.两个链表且不破坏：双指针，分别指向A和B当前的结点，进行比较的同时找到公共结点
*/

// My Version —— bad
// #include "../include/LinkedList.h"

// void FindPublicAndCombine(const LinkedList* A, const LinkedList* B,
//                           LinkedList* C) {
//   // 如果其中一个或者两个链表为空的话直接复制
//   if (A == nullptr || B == nullptr) {
//     C = B ? A == nullptr : A;
//   }

//   // 否则就开始双指针遍历
//   Node* current_A = A->head;
//   Node* current_B = B->head;
//   int position = 1;

//   while (current_A != nullptr && current_B != nullptr) {
//     if (current_A->data == current_B->data) {
//       ListInsert(C, position, current_A->data);
//       position++;
//     } else if (current_A->data > current_B->data) {
//       current_B = current_B->next;
//     } else {
//       current_A = current_A->next;
//     }
//   }
//   // 愚蠢的想法
//   if (current_A != nullptr) {
//   } else if (current_B != nullptr) {
//   }
// }

// GPT4o polished
// TODO: 学学人家的代码
#include "../include/LinkedList.h"

void FindPublicAndCombine(const LinkedList* A, const LinkedList* B,
                          LinkedList* C) {
  // 如果A或B为空，直接返回空链表C
  if (A == nullptr || B == nullptr) {
    InitList(C);  // 初始化C为空链表
    return;
  }

  // 初始化链表C
  InitList(C);

  // 获取链表A和B的头节点
  Node* current_A = A->head;
  Node* current_B = B->head;

  // 指向C链表的当前尾部节点
  // 这里就是优化点，将我的 position insert 方案改为更简单的尾插法
  Node* tail_C = C->head;

  // 双指针遍历链表A和B
  while (current_A != nullptr && current_B != nullptr) {
    if (current_A->data == current_B->data) {
      // 找到公共元素，插入C链表尾部
      Node* new_node = new Node;
      new_node->data = current_A->data;
      new_node->next = nullptr;

      // 将新节点接入C链表
      tail_C->next = new_node;
      tail_C = new_node;

      // 移动指针
      current_A = current_A->next;
      current_B = current_B->next;
    } else if (current_A->data > current_B->data) {
      // 当前A元素大于B元素，移动B的指针
      current_B = current_B->next;
    } else {
      // 当前B元素大于A元素，移动A的指针
      current_A = current_A->next;
    }
  }
  // 如果退出循环了表明至少其中一方空了，那也就没有所谓的 “公共结点” 了
}
