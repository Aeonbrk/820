// 给定三个序列 A、B、C，长度均为n
// 且均为无重复元素的递增序列，请设计一个时间上尽可能高效的算法，
// 逐行输出同时存在于这三个序列中的所有元素。
// 例如
// 数组 A 为{ 1, 2, 3 }
// 数组 B 为{ 2, 3, 4 }
// 数组 c 为{-1, 0, 2 }，则输出 2
// 要求：
// 1 ）给出算法的基本设计思想。
// 2 ）根据设计思想，采用C或C++语言描述算法，关键之处给出注释。
// 3 ）说明你的算法的时间复杂度和空间复杂度。

/**
 * @brief
 * 思路：分而治之的思想，分别将A和B进行比较得到其中的元素交集并存入临时变量 temp
 * 然后再将temp与C进行遍历比较得到最终ABC三个序列同时拥有的元素序列存入
 * inter，然后判断输出——若ABC没有交集，则在控制台打印错误信息，否则按照题目要求逐行输出
 */

#include <algorithm>
#include <iostream>

#include "../include/SqList.h"

// My Solution, not good......
void FindIntersection(const SqList& A, const SqList& B, const SqList& C) {
  if (A.length == B.length == C.length == 0) {
    std::cerr << "The input is not legal!" << std::endl;
  }

  SqList inter;
  SqList temp;
  InitList(inter);
  InitList(temp);

  for (int i = 0; i < A.length; i++) {
    if (A.data[i] == B.data[i]) {
      ListInsert(temp, temp.length, A.data[i]);
    }
  }

  for (int j = 0; j < temp.length; j++) {
    if (temp.data[j] == C.data[j]) {
      ListInsert(inter, inter.length, temp.data[j]);
    }
  }

  if (inter.length == 0) {
    std::cerr << " There is no same element in three SqList!" << std::endl;
  } else {
    std::cout << "The same elements are:" << std::endl;
    for (int z = 0; z < inter.length; z++) {
      std::cout << inter.data[z] << std::endl;
    }
  }
}

/**
 * @brief
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

// WanDao`s Solution, better
// TODO: review this
/**
 * @brief
 * 思路：
 * 使用三个下标变量从小到大遍历数组。
 * 当三个下标变量指向的元素相等时，输出并向前推进指针，否则仅移动小于最大元素的下标变量，
 * 直到某个下标变量移出数组范围，即可停止。
 */

void SameKey(int A[], int B[], int C[], int n) {
  int i = 0, j = 0, k = 0;
  while (i < n && j < n && k < n) {
    if (A[i] == B[j] == C[k]) {
      printf("%d\n", A[i]);
      i++;
      j++;
      k++;
    } else {
      int maxNumber = std::max(A[i], std::max(B[j], C[k]));
      if (A[i] < maxNumber) i++;
      if (B[j] < maxNumber) j++;
      if (C[k] < maxNumber) k++;
    }
  }
}

/**
 * @brief
 * 每个指针移动的次数不超过 n 次，且每次循环至少有一个指针后移
 * 所以时间复杂度为 O(n) ，算法只用到了常数个变量，空间复杂度为O(1)
 */
