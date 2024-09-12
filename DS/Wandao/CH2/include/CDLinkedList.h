#ifndef CIRCULARDOUBLYLINKEDLIST_H
#define CIRCULARDOUBLYLINKEDLIST_H

#define ElemType int

// 定义循环双链表节点的结构
/**
 * Node - 表示循环双链表中的一个节点。
 * @data: 节点中存储的数据。
 * @prev: 指向前一个节点的指针。
 * @next: 指向下一个节点的指针。
 */
typedef struct Node {
  ElemType data;
  struct Node* prev;
  struct Node* next;
} Node;

// 定义循环双链表的结构
typedef struct {
  Node* head;
  int size;
} CircularDoublyLinkedList;

// 初始化循环双链表的函数
/**
 * InitList - 初始化循环双链表。
 * @list: 指向要初始化的循环双链表的指针。
 */
void InitList(CircularDoublyLinkedList* list) {
  list->head = nullptr;
  list->size = 0;
}

// 在特定位置插入元素的函数
/**
 * ListInsert - 在循环双链表的特定位置插入一个元素。
 * @list: 指向循环双链表的指针。
 * @position: 要插入元素的位置。假设从1开始。
 * @element: 要插入的元素。
 * @return: 成功返回0，位置无效返回-1。
 */
int ListInsert(CircularDoublyLinkedList* list, int position, ElemType element) {
  if (position < 1 || position > list->size + 1) {
    return -1;  // 位置无效
  }

  Node* newNode = new Node();
  newNode->data = element;

  if (list->size == 0) {
    newNode->prev = newNode;
    newNode->next = newNode;
    list->head = newNode;
  } else {
    Node* p = list->head;
    for (int i = 1; i < position - 1; i++) {
      p = p->next;
    }
    newNode->next = p->next;
    newNode->prev = p;
    p->next->prev = newNode;
    p->next = newNode;
    if (position == 1) {
      list->head = newNode;
    }
  }
  list->size++;
  return 0;
}

// 头插法建立循环双链表的函数
/**
 * CreateListByHeadInsert - 使用头插法建立循环双链表。
 * @list: 指向循环双链表的指针。
 * @arr: 存储元素的数组。
 * @n: 数组中元素的数量。
 */
void CreateListByHeadInsert(CircularDoublyLinkedList* list, ElemType arr[],
                            int n) {
  for (int i = 0; i < n; i++) {
    Node* newNode = new Node();
    if (newNode == nullptr) {
      throw std::runtime_error("Memory allocation failed");
    }
    newNode->data = arr[i];
    if (list->size == 0) {
      newNode->prev = newNode;
      newNode->next = newNode;
      list->head = newNode;
    } else {
      newNode->next = list->head;
      newNode->prev = list->head->prev;
      list->head->prev->next = newNode;
      list->head->prev = newNode;
      list->head = newNode;
    }
    list->size++;
  }
}

// 尾插法建立循环双链表的函数
/**
 * CreateListByTailInsert - 使用尾插法建立循环双链表。
 * @list: 指向循环双链表的指针。
 * @arr: 存储元素的数组。
 * @n: 数组中元素的数量。
 */
void CreateListByTailInsert(CircularDoublyLinkedList* list, ElemType arr[],
                            int n) {
  Node* tail = list->head;
  if (tail != nullptr) {
    while (tail->next != list->head) {
      tail = tail->next;
    }
  }
  for (int i = 0; i < n; i++) {
    Node* newNode = new Node();
    if (newNode == nullptr) {
      throw std::runtime_error("Memory allocation failed");
    }
    newNode->data = arr[i];
    if (tail == nullptr) {
      newNode->prev = newNode;
      newNode->next = newNode;
      list->head = newNode;
    } else {
      newNode->prev = tail;
      newNode->next = list->head;
      tail->next = newNode;
      list->head->prev = newNode;
    }
    tail = newNode;
    list->size++;
  }
}

// 删除特定位置元素的函数
/**
 * ListDelete - 删除循环双链表中特定位置的元素。
 * @list: 指向循环双链表的指针。
 * @position: 要删除元素的位置。
 * @element: 指向存储删除值的元素的指针。
 * @return: 成功返回0，位置无效返回-1。
 */
int ListDelete(CircularDoublyLinkedList* list, int position,
               ElemType* element) {
  if (position < 1 || position > list->size) {
    return -1;  // 位置无效
  }

  Node* p = list->head;
  for (int i = 1; i < position; i++) {
    p = p->next;
  }
  *element = p->data;

  if (list->size == 1) {
    list->head = nullptr;
  } else {
    p->prev->next = p->next;
    p->next->prev = p->prev;
    if (position == 1) {
      list->head = p->next;
    }
  }

  delete p;
  list->size--;
  return 0;
}

// 搜索元素并返回其位置的函数
/**
 * LocateElem - 在循环双链表中搜索一个元素并返回其位置。
 * @list: 指向循环双链表的指针。
 * @element: 要搜索的元素。
 * @return: 找到元素返回其位置，未找到返回-1。
 */
int LocateElem(CircularDoublyLinkedList* list, ElemType element) {
  if (list->size == 0) {
    return -1;
  }

  Node* p = list->head;
  int currentPosition = 1;
  do {
    if (p->data == element) {
      return currentPosition;
    }
    currentPosition++;
    p = p->next;
  } while (p != list->head);

  return -1;
}

// 获取特定位置元素的函数
/**
 * GetElem - 获取循环双链表中特定位置的元素。
 * @list: 指向循环双链表的指针。
 * @position: 要获取元素的位置。
 * @element: 指向存储获取值的元素的指针。
 * @return: 成功返回0，位置无效返回-1。
 */
int GetElem(CircularDoublyLinkedList* list, int position, ElemType* element) {
  if (position < 1 || position > list->size) {
    return -1;  // 位置无效
  }

  Node* p = list->head;
  for (int i = 1; i < position; i++) {
    p = p->next;
  }
  *element = p->data;
  return 0;
}

// 销毁循环双链表的函数
/**
 * DestroyList - 销毁循环双链表并释放所有节点的内存。
 * @list: 指向循环双链表的指针。
 */
void DestroyList(CircularDoublyLinkedList* list) {
  if (list->size == 0) {
    return;
  }

  Node* current = list->head;
  do {
    Node* next = current->next;
    delete current;
    current = next;
  } while (current != list->head);

  list->head = nullptr;
  list->size = 0;
}

#endif  // CIRCULARDOUBLYLINKEDLIST_H
