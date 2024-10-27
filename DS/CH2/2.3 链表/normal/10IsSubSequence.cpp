/*
两个整数序列 A=a_1, a_2, ..., a_m 和 B=b_1, b_2, ..., b_n 已经存入两个单链表中
设计一个算法，判断序列 B 是否是序列 A 的连续子序列。
*/

/*
分析：
1.数据结构：（带头结点）的单链表
2.依旧是双指针进行遍历
3.(key note)回溯机制：在每次匹配失败后，不再重置
current_B，而是通过回溯机制继续尝试匹配。这样可以避免重复遍历链表 B，提高效率
*/

#include "../include/LinkedList.h"

/**
 * 判断链表 B 是否是链表 A 的连续子序列
 * @param A 链表 A
 * @param B 链表 B
 * @return 如果 B 是 A 的连续子序列，返回 true；否则返回 false
 */
bool IsSubSequence(const LinkedList* A, const LinkedList* B) {
  // 如果链表 A 或 B 为空，直接返回 false
  if (A->head == nullptr || B->head == nullptr) {
    return false;
  }

  // 初始化指针，分别指向链表 A 和 B 的第一个节点
  Node* current_A = A->head->next;
  Node* current_B = B->head->next;

  // 遍历链表 A
  while (current_A != nullptr) {
    // 保存当前指针位置，用于回溯
    Node* temp_A = current_A;
    Node* temp_B = current_B;

    // 尝试匹配链表 B 的子序列
    while (temp_A != nullptr && temp_B != nullptr &&
           temp_A->data == temp_B->data) {
      temp_A = temp_A->next;
      temp_B = temp_B->next;
    }

    // 如果链表 B 的所有节点都匹配成功，则返回 true
    if (temp_B == nullptr) {
      return true;
    }

    // 否则，继续遍历链表 A
    current_A = current_A->next;
  }

  // 如果遍历完链表 A 仍未找到匹配的子序列，返回 false
  return false;
}
