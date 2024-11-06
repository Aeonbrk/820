/*
1.(7分)假设有两个按元素值递增次序排列的线性表,均以单链表形式存储。
请编写算法将这两个单链表归并为一个按元素值递减次序排列的单链表，
并要求利用原来两个单链表的结点存放归并后的单链表。
*/

typedef struct LinkedList {
  int data;
  LinkedList* next;
} LinkedList;

LinkedList* CombineAndRevert(LinkedList* A, LinkedList* B) {
  if (A == nullptr && B == nullptr) {
    return nullptr;
  }

  LinkedList* result = nullptr;
  LinkedList* temp;

  while (A != nullptr && B != nullptr) {
    if (A->data <= B->data) {
      temp = A;
      A = A->next;
    } else {
      temp = B;
      B = B->next;
    }
    // 将当前节点插入到 result 链表的头部(头插法)
    temp->next = result;
    result = temp;
  }

  // 处理剩余的节点
  while (A != nullptr) {
    temp = A;
    A = A->next;
    temp->next = result;
    result = temp;
  }

  while (B != nullptr) {
    temp = B;
    B = B->next;
    temp->next = result;
    result = temp;
  }

  return result;
}
