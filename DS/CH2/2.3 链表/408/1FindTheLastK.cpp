/*
(2009)已知一个带有表头结点的单链表，结点结构为丨 data 丨 link丨，假设
该链表只给出了头指针list。在不改变链表的前提下,请设计一个尽可能高效的算法,查找链
表中倒数第𝑘个位置上的结点(𝑘为正整数)。若查找成功，算法输出该结点的 data
域的值，并返回 1;否则，只返回 0。
要求:
1)描述算法的基本设计思想。
2)描述算法的详细实现步骤。
3)根据设计思想和实现步骤,采用程序设计语言描述算法(使用 C、C++或 Java
语言实现)，关 键之处请给出简要注释。
*/

#include <iostream>

// 定义链表结构
typedef struct LinkedList {
  int data;
  LinkedList* link;
} LinkedList;

// 查找链表中倒数第k个结点的函数
int FindTheLastK(const LinkedList* list, int k) {
  // 如果链表为空或k小于等于0，直接返回0
  if (list == nullptr || k <= 0) {
    return 0;
  }

  // 使用双指针法
  LinkedList* fast = list->link;  // 快指针从第一个结点开始
  LinkedList* slow = list->link;  // 慢指针也从第一个结点开始

  // 先将快指针移动k步
  for (int i = 0; i < k; ++i) {
    if (fast == nullptr) {
      // 如果快指针已经到达链表末尾，说明链表长度小于k
      return 0;
    }
    fast = fast->link;
  }

  // 然后同时移动快指针和慢指针，直到快指针到达链表末尾
  while (fast != nullptr) {
    fast = fast->link;
    slow = slow->link;
  }
  // 相当于我提前空出了末尾k个位置，那只要最后fast指针指向nullptr，slow就指向了倒数第k个位置

  // 此时慢指针指向倒数第k个结点
  std::cout << "The data of the last " << k << "th node is: " << slow->data
            << std::endl;
  return 1;
}

/*
算法的时间复杂度为 O(n)，空间复杂度为 O(1)
*/
