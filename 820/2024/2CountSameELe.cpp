/*
输入 n 个元素的序列，每个元素是
1-10^6的整数，要求你统计序列中每个元素出现次数。（题目
都是以字符串的形式输入，并且要求你以一定格式的字符串形式输出）——2017题目累类似
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
