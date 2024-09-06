#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define ElemType int
#define InitSize 100

// 定义链表节点的结构
/**
 * Node - 表示链表中的一个节点。
 * @data: 节点中存储的数据。
 * @next: 指向下一个节点的指针。
 */
typedef struct Node {
  ElemType data;
  struct Node* next;
} Node;

// 定义链表的结构
typedef struct {
  Node* head;
  int size;
} LinkedList;

// 初始化链表的函数
/**
 * InitList - 初始化链表。
 * @list: 指向要初始化的链表的指针。
 */
void InitList(LinkedList* list) { list->head = NULL; };

// 在特定位置插入元素的函数
/**
 * ListInsert - 在链表的特定位置插入一个元素。
 * @list: 指向链表的指针。
 * @position: 要插入元素的位置。假设从1开始。
 * @element: 要插入的元素。
 * @return: 成功返回0，位置无效返回-1。
 */
int ListInsert(LinkedList* list, int position, ElemType element) {
  if (position < 1 || position > list->size + 1) {
    return -1;  // 位置无效
  }

  Node* newNode = new Node();
  newNode->data = element;

  if (position == 1) {
    list->head = newNode;
    newNode->next = NULL;
    list->size++;
    return 0;
  } else {
    Node* p = list->head;
    for (int i = 1; i < position - 1; i++) {
      p = p->next;
    }
    newNode->next = p->next;
    p->next = newNode;
    list->size++;
    return 0;
  }
};

// 头插法建立链表的函数
/**
 * CreateListByHeadInsert - 使用头插法建立链表。
 * @list: 指向链表的指针。
 * @arr: 存储元素的数组。
 * @n: 数组中元素的数量。
 */
void CreateListByHeadInsert(LinkedList* list, ElemType arr[], int n) {
  for (int i = 0; i < n; i++) {
    Node* newNode = new Node();
    if (newNode == nullptr) {
      // 处理内存分配失败的情况
      // 可以选择抛出异常或返回错误码
      throw std::runtime_error("Memory allocation failed");
    }
    newNode->data = arr[i];
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
  }
}

// 尾插法建立链表的函数
/**
 * CreateListByTailInsert - 使用尾插法建立链表。
 * @list: 指向链表的指针。
 * @arr: 存储元素的数组。
 * @n: 数组中元素的数量。
 */
void CreateListByTailInsert(LinkedList* list, ElemType arr[], int n) {
  Node* tail = list->head;
  for (int i = 0; i < n; i++) {
    Node* newNode = new Node();
    if (newNode == nullptr) {
      // 处理内存分配失败的情况
      throw std::runtime_error("Memory allocation failed");
    }

    newNode->data = arr[i];
    newNode->next = nullptr;
    if (tail == nullptr) {
      list->head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    list->size++;
  }
}

// 删除特定位置元素的函数
/**
 * ListDelete - 删除链表中特定位置的元素。
 * @list: 指向链表的指针。
 * @position: 要删除元素的位置。
 * @element: 指向存储删除值的元素的指针。
 * @return: 成功返回0，位置无效返回-1。
 */
int ListDelete(LinkedList* list, int position, ElemType* element) {
  // 检查位置是否有效
  if (position < 1 || position > list->size) {
    return -1;  // 位置无效
  }

  // 如果删除的是第一个节点
  if (position == 1) {
    Node* p = list->head;  // 获取头节点
    list->head = p->next;  // 更新头节点为下一个节点
    *element = p->data;    // 获取被删除节点的数据

    delete p;      // 释放被删除节点的内存
    list->size--;  // 更新链表大小

    return 0;  // 删除成功
  } else {
    // 找到要删除节点的前一个节点
    Node* p = list->head;
    for (int i = 1; i < position - 1; i++) {
      p = p->next;
    }
    Node* q = p->next;   // 获取要删除的节点
    p->next = q->next;   // 更新前一个节点的next指针
    *element = q->data;  // 获取被删除节点的数据

    delete q;      // 释放被删除节点的内存
    list->size--;  // 更新链表大小

    return 0;  // 删除成功
  }
}

// 搜索元素并返回其位置的函数
/**
 * LocateElem - 在链表中搜索一个元素并返回其位置。
 * @list: 指向链表的指针。
 * @element: 要搜索的元素。
 * @return: 找到元素返回其位置，未找到返回-1。
 */
int LocateElem(LinkedList* list, ElemType element) {
  Node* p = list->head;
  int currentPosition = 1;

  while (p != NULL) {
    if (p->data == element) {
      return currentPosition;
    } else {
      currentPosition++;
      p = p->next;
    }
  }
  return -1;
}

// 获取特定位置元素的函数
/**
 * GetElem - 获取链表中特定位置的元素。
 * @list: 指向链表的指针。
 * @position: 要获取元素的位置。
 * @element: 指向存储获取值的元素的指针。
 * @return: 成功返回0，位置无效返回-1。
 */
int GetElem(LinkedList* list, int position, ElemType* element) {
  if (position < 1 || position > list->size) {
    return -1;  //
  }
  Node* p = list->head;
  for (int i = 1; i < position; i++) {
    p = p->next;
  }
  *element = p->data;
  return 0;
}

// 销毁链表的函数
/**
 * DestroyList - 销毁链表并释放所有节点的内存。
 * @list: 指向链表的指针。
 */
void DestroyList(LinkedList* list) {
  Node* current = list->head;
  while (current != nullptr) {
    Node* next = current->next;
    delete current;
    current = next;
  }
  list->head = nullptr;
  list->size = 0;
}

#endif  // LINKEDLIST_H
