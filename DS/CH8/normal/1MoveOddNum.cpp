/*
已知线性表按顺序存储,且每个元素都是不相同的整数型元素,设计把所有奇数移动到所有
偶数前边的算法(要求时间最短,辅助空间最小)
*/

#include <iostream>

#include "../CH2/include/LinkedList.h"

void MoveOddNum(int L[], int length) {
  // 使用双指针法，一个指针从前往后找偶数，另一个指针从后往前找奇数
  int left = 0;
  int right = length - 1;

  while (left < right) {
    // 从左往右找第一个偶数
    while (left < right && L[left] % 2 != 0) {
      left++;
    }

    // 从右往左找第一个奇数
    while (left < right && L[right] % 2 == 0) {
      right--;
    }

    // 如果左指针小于右指针，交换两个指针所指的元素
    if (left < right) {
      std::swap(L[left], L[right]);
      // 交换后，左指针右移，右指针左移
      left++;
      right--;
    }
  }
}

/*
如果是链表形式的数据结构

void MoveOddNum(LinkedList* L) {
  // 检查链表是否为空
  if (L == nullptr || L->head == nullptr) {
    return;
  }

  // 定义两个指针，分别指向链表的头节点和尾节点
  Node* left = L->head;
  Node* right = L->head;

  // 将right指针移动到链表的尾节点
  while (right->next != nullptr) {
    right = right->next;
  }

  // 定义一个临时指针，用于交换节点
  Node* temp = nullptr;

  // 使用双指针法，将奇数移动到偶数前边
  while (left != right) {
    // 如果left指针指向的节点是奇数
    if (left->data % 2 != 0) {
      // 移动left指针到下一个节点
      left = left->next;
    } else {
      // 如果left指针指向的节点是偶数
      // 将left指针指向的节点移动到right指针指向的节点后边
      temp = left->next;
      left->next = right->next;
      right->next = left;
      left = temp;
    }
  }

  // 如果链表的最后一个节点是偶数，将其移动到right指针指向的节点后边
  if (right->data % 2 == 0) {
    temp = L->head;
    while (temp->next != right) {
      temp = temp->next;
    }
    temp->next = nullptr;
    right->next = L->head;
    L->head = right;
  }
}
* /

/*
该算法的时间复杂度为 O(n)，其中 n 是数组的长度。因为每个元素最多被访问一次。
该算法的空间复杂度为 O(1)，因为只使用了常数级别的额外空间。
*/
