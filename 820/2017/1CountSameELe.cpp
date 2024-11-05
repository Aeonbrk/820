/*
给定一个顺序表L1, 设计一个算法以统计其中的相同元素的个数。
要求时间复杂度和空间复杂度尽量低。程序设计语言可以选用C、C++、Java。（7分）
*/

#define EleType int

#include <iostream>
#include <unordered_map>

int CountSameELe(EleType a[], int size) {
  std::unordered_map<EleType, int> countMap;  // 使用哈希表存储每个元素的计数

  // 统计每个元素的出现次数
  for (int i = 0; i < size; ++i) {
    countMap[a[i]]++;
  }

  int sameCount = 0;  // 相同元素的总数

  // 计算出现次数大于1的元素的总数
  for (const auto& pair : countMap) {
    if (pair.second > 1) {
      sameCount += pair.second;
    }
  }

  return sameCount;
}

/*
时间复杂度: 总体时间复杂度为 O(n)，其中 n 是数组的大小。
空间复杂度: 空间复杂度为 O(m)，其中 m 是数组中唯一元素的数量
*/
