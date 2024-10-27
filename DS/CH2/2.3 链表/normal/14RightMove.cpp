/*
设将𝑛(𝑛 > 1)个整数存放到不带头结点的单链表𝐿中,设计算法将𝐿中保存的序列循环右移
𝑘(0 < 𝑘 < 𝑛)个位置。例如,若𝑘 = 1,则将链表{0,1,2,3}变为{3,0,1,2}。要求:
1)给出算法的基本设计思想。
2)根据设计思想,采用 C 或 C++语言描述算法,关键之处给出注释。
3)说明你所设计算法的时间复杂度和空间复杂度。
*/

#include "../include/LinkedList.h"

void RightMove(LinkedList* L, int k, int n) {
  // 如果链表为空，直接返回
  if (L == nullptr) {
    return;
  }

  // 计算实际需要移动的步数
  k = k % n;
  if (k == 0) {
    return;  // 不需要移动
  }

  // 初始化两个指针 p 和 q
  Node* p = L;
  Node* q = L;

  // 将 p 指针移动到第 n-k 个节点
  for (int i = 0; i < n - k; i++) {
    p = p->next;
  }

  // 将 q 指针移动到第 n-k-1 个节点
  while (q->next != p) {
    q = q->next;
  }

  // 将 p 指针之后的节点连接到链表头部
  Node* newHead = p;
  while (p->next != nullptr) {
    p = p->next;
  }
  p->next = L;

  // 将 q 指针的 next 设为 nullptr，断开循环
  q->next = nullptr;

  // 更新链表头指针
  L = newHead;
}

/*
### 算法的基本设计思想：
1. **计算链表长度**：首先遍历链表，计算链表的长度 `n`。
2. **计算实际移动步数**：由于 `k` 可能大于 `n`，所以需要对 `k`
取模，得到实际需要移动的步数。
3. **找到分割点**：使用两个指针 `p` 和 `q`，将 `p` 移动到第 `n-k` 个节点，将 `q`
移动到第 `n-k-1` 个节点。
4. **重新连接链表**：将 `p` 之后的节点连接到链表头部，并将 `q` 的 `next` 设为
`nullptr`，断开循环。
5. **更新链表头指针**：将链表头指针更新为 `newHead`。

### 时间复杂度：
- 计算链表长度：O(n)
- 移动指针：O(n)
- 重新连接链表：O(n)

总的时间复杂度为 O(n)。

### 空间复杂度：
- 只使用了常数级别的额外空间，空间复杂度为 O(1)。
*/
