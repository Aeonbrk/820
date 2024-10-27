/*
设单链表的表头指针为𝐿,结点结构由 data 和 next 两个域构成,
其中 data 域为字符型。试设计算法判断该链表的全部n个字符是否中心对称。
例如xyx、xyyx都是中心对称
*/

#include "../../CH2/include/LinkedLisy.h"
#include "../include/stack.h"

bool isSymmetry(LinkedList* L, int n) {
  int len = n / 2;
  Node* p = L;
  Stack S;
  initStack(S);

  while (len > 0) {
    push(S, p->data);
    p = p->next;
    len--;
  }
  if (n % 2 == 1) {
    p = p->next;
  }

  while (p) {
    if (pop(S) != p->data) {
      return false;
    }
  }

  return true;
}

/*
算法思想：
快慢指针定位中间节点：

使用快慢指针找到链表的中间位置。快指针每次移动两步，慢指针每次移动一步。当快指针到达链表末尾时，慢指针正好在链表的中间位置。
如果链表长度为奇数，慢指针会指向中间节点；如果链表长度为偶数，慢指针会指向中间两个节点中的后一个节点。
栈存储前半部分字符：

在快慢指针移动的过程中，将慢指针指向的字符依次压入栈中。这样，栈中存储的就是链表前半部分的字符。
比较后半部分字符与栈中字符：

从中间位置开始，依次比较后半部分的字符与栈中弹出的字符。如果所有字符都匹配，则链表是中心对称的；否则，链表不是中心对称的。
处理奇偶长度链表：

如果链表长度为奇数，跳过中间节点，直接从中间节点的下一个节点开始比较。


// 定义链表节点结构
struct ListNode {
  char data;
  ListNode* next;
  ListNode(char c) : data(c), next(nullptr) {}
};

// 判断链表是否中心对称的函数
bool isSymmetry(ListNode* L) {
  if (L == nullptr || L->next == nullptr) {
    // 空链表或只有一个节点的链表视为中心对称
    return true;
  }

  // 快慢指针初始化
  ListNode* slow = L;
  ListNode* fast = L;
  Stack<char> s;  // 使用栈来存储前半部分的字符

  // 使用快慢指针找到链表的中间位置
  while (fast != nullptr && fast->next != nullptr) {
    s.push(slow->data);       // 将慢指针指向的字符压入栈中
    slow = slow->next;        // 慢指针每次移动一步
    fast = fast->next->next;  // 快指针每次移动两步
  }

  // 如果链表长度为奇数，跳过中间节点
  if (fast != nullptr) {
    slow = slow->next;
  }

  // 从中间位置开始，比较后半部分的字符与栈中的字符
  while (slow != nullptr) {
    char top = s.pop();  // 弹出栈顶字符
    if (slow->data != top) {
      // 如果字符不匹配，链表不是中心对称的
      return false;
    }
    slow = slow->next;  // 继续比较下一个字符
  }

  // 如果所有字符都匹配，链表是中心对称的
  return true;
}
* /
