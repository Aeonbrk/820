/*
【2020 统考真题】
定义三元组 (a, b, c) (a, b, c 均为正数) 的距离 D =
|a - b| + |b - c| + |c - a|。 给定 3 个非空整数集合 S1、S2 和
S3，按升序分别存储在 3 个数组中。
请设计一个尽可能高效的算法，计算并输出所有可能的三元组 (a, b, c) (a ∈ S1, b ∈
S2, c ∈ S3) 中的最小距离。 例如 S1 = {-1, 0, 9}，S2 = {-25, -10, 10, 11}，S3 =
{2, 9, 17, 30, 41}，则最小距离为 2， 相应的三元组为 (9, 10, 9)。
要求：
1)给出算法的基本设计思想。
2) 根据设计思想，采用 C 语言或 C++ 语言描述算法，关键之处给出注释。
3) 说明你所设计算法的时间复杂度和空间复杂度。
*/

/**
 * 思路：
 * 若放在 X 轴上，那这个距离就是最大减去最小的2倍，也就是我们只用关心最大和最小
 * 因为已经是升序了，遍历的同时找到最小，最小的那个跳过到下一个数，与此同时记录
 * distance
 */

/**
 * Time: O(n)
 * Space: O(1)
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

#define Elemtype int

// 判断是否是最小值
bool IsMin(Elemtype a, Elemtype b, Elemtype c) { return (a <= b && a <= c); }

// 找到三元组的最小距离
Elemtype FindMinDistance(const std::vector<Elemtype>& S1,
                         const std::vector<Elemtype>& S2,
                         const std::vector<Elemtype>& S3) {
  size_t i = 0, j = 0, k = 0;
  int minDis = INT_MAX;

  while (i < S1.size() && j < S2.size() && k < S3.size()) {
    int a = S1[i], b = S2[j], c = S3[k];
    int currentDis = std::abs(a - b) + std::abs(b - c) + std::abs(c - a);

    minDis = std::min(minDis, currentDis);

    // 移动最小值对应的指针
    if (IsMin(a, b, c)) {
      ++i;
    } else if (IsMin(b, a, c)) {
      ++j;
    } else {
      ++k;
    }
  }

  return minDis;
}
