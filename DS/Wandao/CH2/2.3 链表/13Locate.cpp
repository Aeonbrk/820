/*
设有一个带头结点的非循环双链表L，其每个结点中除有pre、data和next域外，
还有一个访问频度域freq，其值均初始化为零。
每当在链表中进行一次Locate(L，x)运算时，令值为x的结点中freq域的值增1，
并使此链表中的结点保持按访问频度递减的顺序排列，且最近访问的结点排在频度相同的结点之前，
以便使频繁访问的结点总是靠近表头。试编写符合上述要求的Locate(L，x)函数，返回找到结点的地址，类型为指针型。
*/
#include <iostream>

// 定义双链表结点结构
struct DNode {
  int data;
  int freq;
  DNode* pre;
  DNode* next;
};

// 定义链表结构
struct DList {
  DNode* head;
};

// 初始化链表
void InitList(DList& L) {
  L.head = new DNode;
  L.head->next = nullptr;
  L.head->pre = nullptr;
}

// Locate函数
DNode* Locate(DList& L, int x) {
  DNode* p = L.head->next;
  while (p != nullptr && p->data != x) {
    p = p->next;
  }

  if (p == nullptr) {
    // 如果未找到结点，返回nullptr
    return nullptr;
  }

  // 找到结点，更新freq
  p->freq++;

  // 将p结点从链表中移除
  if (p->pre != nullptr) {
    p->pre->next = p->next;
  }
  if (p->next != nullptr) {
    p->next->pre = p->pre;
  }

  // 找到p应该插入的位置
  DNode* q = L.head->next;
  while (q != nullptr && q->freq > p->freq) {
    q = q->next;
  }

  // 插入p结点
  p->next = q;
  p->pre = q->pre;
  if (q->pre != nullptr) {
    q->pre->next = p;
  }
  q->pre = p;

  // 如果p插入到表头
  if (p->pre == nullptr) {
    L.head->next = p;
  }

  return p;
}
