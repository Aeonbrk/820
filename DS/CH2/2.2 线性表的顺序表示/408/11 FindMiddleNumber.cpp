/*
【2011统考真题】
一个长度为L（L≥1）的升序序列 S，处在第[L/2]个位置的数称为
S的中位数。例如，若序列 S1=（11，13，15，17，19），则 S1的中位数是
15，两个序列的中位数是含它们所有元素的升序序列的中位数。例如，若S2=（2，4，6，8，20），则S1和S2的中位数是11。
现在有两个等长升序序列A和B，试设计一个在时间和空间两方面都尽可能高效的算法
找出两个序列A和B的中位数。
要求：
1）给出算法的基本设计思想。
2）根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
3）说明你所设计算法的时间复杂度和空间复杂度。
*/

/**
 * @brief
 * 利用归并排序的思想。在归并排序的过程中，
 * 逐步合并两个序列，并保持结果的有序性。通过跟踪已合并的元素数量，当达到中位数位置时即可停止
 */

/**
 * 算法复杂度
 * 时间复杂度：O(n)，其中 n
 * 是单个序列的长度。我们只需要线性时间遍历一次两个序列。
 * 空间复杂度：O(1)。除了输入序列外，我们只使用了常数空间来存储临时变量。
 */

#include <iostream>

#include "../include/SqList.h"

bool FindMiddleNumber(const SqList& L1, const SqList& L2, int& x) {
  if (L1.length != L2.length || L1.length == 0 || L2.length == 0) return false;

  int n = L1.length;
  int middle = n;  // 两个序列合并后的中位数位置是 n
  int i = 0, j = 0, count = 0;
  int last = 0;

  // 使用归并排序的思想，直到找到中位数
  while (i < n && j < n && count < middle) {
    if (L1.data[i] < L2.data[j]) {
      last = L1.data[i];
      i++;
    } else {
      last = L2.data[j];
      j++;
    }
    count++;
  }

  // 处理剩余的元素
  while (i < n && count < middle) {
    last = L1.data[i];
    i++;
    count++;
  }

  while (j < n && count < middle) {
    last = L2.data[j];
    j++;
    count++;
  }

  x = last;
  return true;
}

/**
 * 王道的版本
 * 算法的时间复杂度为O(logn)，空间复杂度为O(1)


算法的基本设计思想是寻找两个升序序列A和B的中位数。具体步骤如下：

1. **求中位数**：首先分别计算序列A和B的中位数，分别记为α和b。
2. **比较中位数**：然后进行以下判断：
**1**：如果α等于b，那么α或b就是所求的中位数，算法结束。
**2**：如果α小于b，需要舍弃序列A中较小的一半，同时舍弃序列B中较大的一半，并且要求这两次舍弃的长度相等。
**3**：如果α大于b，需要舍弃序列A中较大的一半，同时舍弃序列B中较小的一半，同样要求这两次舍弃的长度相等。
3. **重复过程**：在保留下来的两个升序序列中，重复执行步骤1,2,3
4.
**结束条件**：当两个序列中都只剩下一个元素时，取这两个元素中的较小者作为所求的中位数。

这种算法利用了两个序列都是有序的特性，通过逐步缩小搜索范围来高效地找到中位数。


int Search(int A[], int B[], int n) {
  int sl, dl, ml, s2, d2, m2;
  sl = 0;
  dl = n - 1;  // 初始化A数组的搜索范围
  s2 = 0;
  d2 = n - 1;  // 初始化B数组的搜索范围
  while (sl != dl && s2 != d2) {
    ml = (sl + dl) / 2;  // A数组的中间索引
    m2 = (s2 + d2) / 2;  // B数组的中间索引

    if (A[ml] == B[m2]) {
      return A[ml];  // 找到匹配元素，返回
    }

    // 条件①：如果A中的元素小于B中的元素
    if (A[ml] < B[m2]) {
      if ((sl + dl) % 2 == 0) {
        sl = ml;  // 保留A的中间点
        d2 = m2;  // 保留B的中间点
      } else {
        sl = ml + 1;  // 舍弃A的前半部分
        d2 = m2;      // 舍弃B的后半部分
      }
    }
    // 条件③：如果A中的元素大于B中的元素
    else {
      if ((sl + dl) % 2 == 0) {
        dl = ml;  // 保留A的中间点
        s2 = m2;  // 保留B的中间点
      } else {
        dl = ml;      // 舍弃A的后半部分
        s2 = m2 + 1;  // 舍弃B的前半部分
      }
    }
  }

  // 循环结束后，需要处理两种数组的边界情况
  return (A[sl] < B[s2]) ? A[sl] : B[s2];
}
 */

int main() {
  // 示例测试
  SqList L1 = {new int[5]{11, 13, 15, 17, 19}, 5};
  SqList L2 = {new int[5]{2, 4, 6, 8, 20}, 5};
  int median;

  if (FindMiddleNumber(L1, L2, median)) {
    std::cout << "The median is " << median << std::endl;
  } else {
    std::cout << "Error finding the median." << std::endl;
  }

  delete[] L1.data;
  delete[] L2.data;
  return 0;
}
