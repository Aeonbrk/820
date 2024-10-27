/*
设在一个带表头结点的单链表中，所有元素结点的数据值无序，试编写一个函数，删除表中所有介于给定的两个值
（作为函数参数给出）之间的元素的元素（若存在）
*/

/*
分析：
1.遍历链表，检查每个节点的数据值是否在给定的两个值之间
2.如果节点的数据值在范围内，则删除该节点
3.删除节点时，需要调整前驱节点的指针，使其跳过当前节点，直接指向后继节点所以需要设置
prev 指针
*/

#include "../include/LinkedList.h"

void DeleteRange(LinkedList* L, int min, int max) {
  if (L == nullptr || L->head == nullptr) {
    return;  // 链表为空，直接返回
  }

  Node* current = L->head;
  Node* prev = nullptr;

  while (current != nullptr) {
    if (current->data >= min && current->data <= max) {
      // 当前节点在范围内，删除该节点
      Node* toDelete = current;
      current = current->next;

      if (prev == nullptr) {
        // 删除的是头节点
        L->head = current;
      } else {
        prev->next = current;
      }

      delete toDelete;
      L->size--;
    } else {
      // 当前节点不在范围内，继续遍历
      prev = current;
      current = current->next;
    }
  }
}

// TODO: 自己写一遍要写得出来
// void delete(LinkedList* L int min, int max) {
//   if (L == nullptr || L->head == nullptr) {
//     return;
//   }

//   Node* current = L->head;
//   Node* prev = nullptr;

//   while (current != nullptr) {
//     if (current->data <= max && current->data >= min) {
//       Node* toDelete = current;
//       current = current->next;

//       if (prev == nullptr) {
//         L->head = nullptr;
//       } else {
//         prev->next = current;
//       }

//       L->size--;
//       delete toDelete;
//     } else {
//       prev = current;
//       current = current->next;
//     }
//   }
// }
