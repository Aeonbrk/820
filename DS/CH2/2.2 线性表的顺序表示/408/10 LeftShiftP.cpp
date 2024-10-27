/*
【2010统考真题】
设将 n （ n > 1 ）个整数存放到一维数组 R 中。
设计一个在时间和空间两方面都尽可能高效的算法。将 R 中保存的序列循环左移 p
（ 0 < P < n) 个位置，即将 R 中的数据由 (X0, X1,..., Xn-1) 变换为
(Xp, Xp+1, ..., Xn-1, X0, X1, X2,..., Xp-1)
要求:
1) 给出算法的基本设计思想。
2）根据设计思想，采用 c 或 C++ 或 Java 语言描述算法，关键之处给出注释。
3）说明你所设计算法的时间复杂度和空间复杂度。
*/

// TODO: review this
// like 7 ReverseInline.cpp
/**
 * @brief
 * 反转法：通过三次反转实现左移。这个方法避免了使用额外的空间，只需要在原数组上进行操作。
 * 首先反转前 p 个元素。
 * 然后反转后 n−p 个元素。
 * 最后反转整个数组。
 */

/**
 * 时间复杂度：O(n)
 * 每次反转操作的时间复杂度是 O(k)，其中 k
 是反转部分的长度。因为我们进行了三次反转操作，所以总的时间复杂度是 O(n)。

 * 空间复杂度：O(1)
 * 我们只使用了常数级别的额外空间来存储临时变量（例如用于交换的变量），因此空间复杂度是 O(1)。
 */

#include <algorithm>
#include <iostream>

#include "../include/SqList.h"

void Reverse(SqList& L, int start, int end) {
  while (start < end) {
    std::swap(L.data[start], L.data[end]);
    start++;
    end--;
  }
}

bool LeftShiftP(SqList& R, int p) {
  int n = R.length;
  if (p < 0 || p > n) return false;

  Reverse(R, 0, p);
  Reverse(R, p, n - 1);
  Reverse(R, 0, n - 1);
}
