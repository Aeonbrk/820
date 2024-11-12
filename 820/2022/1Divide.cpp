// 已知有一个可能有重复数字的非递减序列采用带头结点的单链表进行存储，请你将
// 其分割成一个或多个不具有重复数字的递增子序列。假设最多重复的数字次数不超过10，
// 请描述算法思想进行分割。最后通过C/C++编写函数实现算法功能。
// 比如原始序列[1,2,3,3,3,4,5,6,6]则可以分割成3个序列[1,2,3,4,5,6]，[3,6]，[3]。

/*
分组：
  首先，遍历原始链表，将相同的数值分为一组。每组包含一个数值及其出现的次数。
  分配到子链表：
  根据每组中的数值出现次数，依次将这些数值分配到不同的子链表中。确保每个子链表中的数值严格递增且不包含重复数字。

维护子链表的尾节点：
  为每个子链表维护一个尾节点指针，以便高效地向子链表添加新节点。

使用std::vector管理子链表：
  使用std::vector来存储子链表的头节点和尾节点，方便动态管理多个子链表。
*/

#include <iostream>
#include <map>
#include <vector>

// 定义单链表节点结构体
struct LinkedList {
  int data;
  LinkedList* next;

  LinkedList(int val) : data(val), next(nullptr) {}
};

// 定义一个结构体来存储子链表的头节点和尾节点
struct SubList {
  LinkedList* head;
  LinkedList* tail;

  SubList() : head(nullptr), tail(nullptr) {}
};

// 函数：分割链表
std::vector<LinkedList*> Divide(LinkedList* head) {
  if (!head) return {};

  // 首先统计每个数值的出现次数
  std::map<int, int> countMap;
  LinkedList* current = head;
  while (current) {
    countMap[current->data]++;
    current = current->next;
  }

  // 找到出现次数最多的数值，以确定需要多少个子链表
  int maxCount = 0;
  for (const auto& pair : countMap) {
    if (pair.second > maxCount) {
      maxCount = pair.second;
    }
  }

  // 最多10个重复，根据题目假设
  maxCount = (maxCount > 10) ? 10 : maxCount;

  // 初始化子链表
  std::vector<SubList> subLists(maxCount, SubList());

  // 再次遍历原始链表，按顺序分配到子链表
  current = head;
  while (current) {
    int value = current->data;
    // 找到该值在之前已分配到哪个子链表
    // 依次循环分配，确保每个子链表中没有重复
    bool assigned = false;
    for (int i = 0; i < maxCount; ++i) {
      // 如果子链表为空或最后一个值小于当前值，则可以添加
      if (!subLists[i].tail || subLists[i].tail->data < value) {
        LinkedList* newNode = new LinkedList(value);
        if (!subLists[i].head) {
          subLists[i].head = newNode;
          subLists[i].tail = newNode;
        } else {
          subLists[i].tail->next = newNode;
          subLists[i].tail = newNode;
        }
        assigned = true;
        break;
      }
    }
    // 如果所有子链表都已有当前值，无法分配
    // 根据题目假设最多重复10次，不会发生这种情况
    if (!assigned) {
      // 创建新的子链表（不超过10个）
      // 根据题目假设，这里不会超过，即不需要处理
      // 但为了安全，可以处理
      if (subLists.size() < 10) {
        SubList newSubList;
        LinkedList* newNode = new LinkedList(value);
        newSubList.head = newNode;
        newSubList.tail = newNode;
        subLists.push_back(newSubList);
      } else {
        std::cerr << "超过最大允许的子链表数量。" << std::endl;
      }
    }
    current = current->next;
  }

  // 收集所有子链表的头节点
  std::vector<LinkedList*> result;
  for (const auto& subList : subLists) {
    if (subList.head) {
      result.push_back(subList.head);
    }
  }
  return result;
}

/*
数据结构定义：
  LinkedList结构体定义了单链表的节点，包含一个整数数据和指向下一个节点的指针。
  SubList结构体用于存储每个子链表的头节点和尾节点，便于高效地向子链表添加新节点。

Divide函数：
  统计数值频次：首先遍历原始链表，使用std::map统计每个数值的出现次数，以确定需要多少个子链表。
  初始化子链表：根据最大重复次数初始化若干子链表，最多不超过10个（根据题目假设）。
  分配节点：再次遍历原始链表，依次将每个节点分配到适当的子链表中，确保每个子链表中的数值严格递增且不重复。
  收集结果：将所有非空的子链表头节点收集到一个std::vector中并返回。
*/
