/*
试编写在带头结点的单链表
L中删除一个最小值结点的高效算法（假设最小值结点是唯一的）
*/

/*
分析：
1：对于单链表找到最小就是循环遍历
2：主要是删除，需要记录最小节点的前一个结点，为此至少需要准备两个变量 —— preminp
和 minp
  2.1：
  由于最小节点是唯一的，那么有可能一个节点和后面的系欸但比较多次，所以还需要两个节点
  —— pre 和 p 来 “移动” 节点位置
*/

#include "../include/LinkedList.h"

void DeleteMin(LinkList &L) {
  // 如果链表为空，直接返回
  if (L->next == NULL) return;

  // 初始化指针：pre指向当前结点的前一个结点，p指向当前结点
  // minpre指向最小值结点的前一个结点，minp指向最小值结点
  LNode *pre = L, *p = L->next;
  LNode *minpre = pre, *minp = p;

  // 遍历链表
  while (p != NULL) {
    // 如果当前结点的值小于最小值结点的值，更新minpre和minp
    if (p->data < minp->data) {
      minp = p;
      minpre = pre;
    }
    // 移动pre和p到下一个结点
    pre = p;
    p = p->next;
  }

  // 删除最小值结点
  minpre->next = minp->next;
  free(minp);
  return;
}

/*
时间复杂度:
该算法需要遍历整个链表一次，以找到最小值结点。假设链表的长度为 n，则时间复杂度为
O(n)

空间复杂度：
该算法仅使用了常数级别的额外空间（几个指针变量），因此空间复杂度为 O(1)
*/
