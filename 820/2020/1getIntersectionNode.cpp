/*
设计一个 O(n)的算法，求给出的两个链表是否为交叉链表，即两个物理地址中
都有一个结点的物理存储地址。若无返回NULL，若存在返回这个结点的地址。
*/

#include <iostream>

// 定义链表节点结构
struct ListNode {
  int val;         // 节点的值
  ListNode* next;  // 指向下一个节点的指针

  // 构造函数
  ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * @brief 判断两个链表是否相交，并返回相交的第一个节点
 *
 * 算法步骤：
 * 1. 分别计算两个链表的长度，并找到它们的尾节点。
 * 2. 如果两个链表的尾节点不同，则它们不相交，返回nullptr。
 * 3. 如果尾节点相同，则存在相交。找出较长链表与较短链表之间的长度差。
 * 4. 将较长链表的指针先移动长度差步，使两链表剩余长度相同。
 * 5. 同时遍历两个链表，找到第一个相同的节点，即为相交节点。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 *
 * @param headA 第一个链表的头节点
 * @param headB 第二个链表的头节点
 * @return ListNode* 相交的节点地址，如果不相交则返回nullptr
 */
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
  // 如果任意一个链表为空，则不可能相交
  if (headA == nullptr || headB == nullptr) {
    return nullptr;
  }

  // 初始化指针和长度变量
  ListNode* currentA = headA;
  ListNode* currentB = headB;
  int lengthA = 0;
  int lengthB = 0;

  // 计算链表A的长度，并找到其尾节点
  while (currentA->next != nullptr) {
    lengthA++;
    currentA = currentA->next;
  }
  lengthA++;  // 包括最后一个节点

  // 计算链表B的长度，并找到其尾节点
  while (currentB->next != nullptr) {
    lengthB++;
    currentB = currentB->next;
  }
  lengthB++;  // 包括最后一个节点

  // 如果两个链表的尾节点不同，则不相交
  if (currentA != currentB) {
    return nullptr;
  }

  // 重置指针到各自的头节点
  currentA = headA;
  currentB = headB;

  // 计算长度差
  int diff = (lengthA > lengthB) ? (lengthA - lengthB) : (lengthB - lengthA);

  // 移动较长链表的指针，使两链表剩余长度相同
  if (lengthA > lengthB) {
    for (int i = 0; i < diff; ++i) {
      currentA = currentA->next;
    }
  } else {
    for (int i = 0; i < diff; ++i) {
      currentB = currentB->next;
    }
  }

  // 同时遍历两个链表，寻找相交节点
  while (currentA != nullptr && currentB != nullptr) {
    // 判断当前节点是否相同（即内存地址相同）
    if (currentA == currentB) {
      return currentA;  // 找到相交节点
    }
    currentA = currentA->next;
    currentB = currentB->next;
  }

  return nullptr;  // 没有相交节点
}
