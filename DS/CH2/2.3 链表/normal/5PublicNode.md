# FindPublicNode

## 问题

- 给定两个单链表，如何找出它们的公共结点？（不需要编写代码）

## 分析

### 公共结点的定义

在两个单链表中，公共结点是指两个链表从某个结点开始，后续的所有结点都是相同的，也就是说，从这个公共结点开始，两个链表的结构和值完全一致。公共结点之后的部分在两个链表中是共享的。

### 解决办法

为了解决找公共结点的问题，可以使用以下几种常见的算法思想：

1. **双指针法**：
   - **步骤**：
     1. 首先遍历两个链表，分别计算它们的长度，记为 `lenA` 和 `lenB`。
     2. 比较两个链表的长度差 `|lenA - lenB|`，让较长的链表先移动这个差值的步数，使两个链表剩余部分的长度相等。
     3. 接着，两个指针同时从当前结点开始遍历链表，逐个比较结点，直到找到第一个相同的结点，即为公共结点。
   - **优点**：时间复杂度为 O(n)，空间复杂度为 O(1)，高效且不需要额外的存储空间。

2. **哈希表法**：
   - **步骤**：
     1. 遍历第一个链表，将每个结点的地址存储在哈希表中。
     2. 然后遍历第二个链表，对于每个结点，检查其地址是否存在于哈希表中。如果存在，则该结点就是公共结点。
   - **优点**：时间复杂度为 O(n)，空间复杂度为 O(n)，适合在需要快速查找的情况下使用。
   - **缺点**：需要额外的存储空间。

3. **栈法**：
   - **步骤**：
     1. 分别遍历两个链表，将每个链表的结点依次压入两个栈中。
     2. 然后同时从两个栈的栈顶开始比较，找到第一个不同的结点，最后一个相同的结点就是公共结点。
   - **优点**：通过逆向比较，可以很快找到公共结点。
   - **缺点**：需要额外的存储空间，时间复杂度为 O(n)。

4. **拼接法**：
   - **步骤**：
     1. 将两个链表拼接，分别形成新的链表 `A + B` 和 `B + A`，即将链表 A 的结尾接上链表 B，将链表 B 的结尾接上链表 A。
     2. 通过遍历这两个新的链表，找到第一个相同的结点即为公共结点。
   - **优点**：通过拼接保证两个链表的总长度相同，从而可以同步查找。
   - **缺点**：虽然思想巧妙，但拼接操作可能增加时间和空间开销。

### show me the code

```cpp
Node* FindPublicNode_TwoPointer(LinkedList* listA, LinkedList* listB) {
  if (listA->head == nullptr || listB->head == nullptr) return nullptr;

  Node* pA = listA->head;
  Node* pB = listB->head;

  // 计算两个链表的长度
  int lenA = listA->size;
  int lenB = listB->size;

  // 调整两个链表的起始点，使得剩余长度相等
  if (lenA > lenB) {
    for (int i = 0; i < lenA - lenB; i++) {
      pA = pA->next;
    }
  } else {
    for (int i = 0; i < lenB - lenA; i++) {
      pB = pB->next;
    }
  }

  // 同时遍历，找到第一个相同的节点
  while (pA != nullptr && pB != nullptr) {
    if (pA == pB) return pA;
    pA = pA->next;
    pB = pB->next;
  }

  return nullptr;  // 没有找到公共节点
}
```

---

```cpp
#include <unordered_set>

Node* FindPublicNode_HashTable(LinkedList* listA, LinkedList* listB) {
  if (listA->head == nullptr || listB->head == nullptr) return nullptr;

  std::unordered_set<Node*> nodeSet;

  // 遍历第一个链表，将节点存入哈希表
  Node* pA = listA->head;
  while (pA != nullptr) {
    nodeSet.insert(pA);
    pA = pA->next;
  }

  // 遍历第二个链表，检查是否有节点在哈希表中
  Node* pB = listB->head;
  while (pB != nullptr) {
    if (nodeSet.find(pB) != nodeSet.end()) return pB;
    pB = pB->next;
  }

  return nullptr;  // 没有找到公共节点
}
```

---

```cpp
#include <stack>

Node* FindPublicNode_Stack(LinkedList* listA, LinkedList* listB) {
  if (listA->head == nullptr || listB->head == nullptr) return nullptr;

  std::stack<Node*> stackA, stackB;

  // 分别遍历两个链表，将所有节点压入栈中
  Node* pA = listA->head;
  while (pA != nullptr) {
    stackA.push(pA);
    pA = pA->next;
  }

  Node* pB = listB->head;
  while (pB != nullptr) {
    stackB.push(pB);
    pB = pB->next;
  }

  // 比较栈顶的节点，直到找到第一个不同的节点
  Node* lastCommonNode = nullptr;
  while (!stackA.empty() && !stackB.empty() && stackA.top() == stackB.top()) {
    lastCommonNode = stackA.top();
    stackA.pop();
    stackB.pop();
  }

  return lastCommonNode;  // 返回最后一个相同的节点
}
```

---

```cpp
Node* FindPublicNode_Splicing(LinkedList* listA, LinkedList* listB) {
  if (listA->head == nullptr || listB->head == nullptr) return nullptr;

  Node* pA = listA->head;
  Node* pB = listB->head;

  // 将两个链表拼接
  while (pA != pB) {
    pA = (pA == nullptr) ? listB->head : pA->next;
    pB = (pB == nullptr) ? listA->head : pB->next;
  }

  return pA;  // 返回第一个相同的节点，或 nullptr（无公共节点）
}
```
