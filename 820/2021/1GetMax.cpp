// 1．(7分)给定n个元素的数组，求出给出其中的任意元素与其后任意元素差值的最大值(即
// max(array[i]-array[j])(O<=i<j<n)，时间复杂度和空间复杂度尽可能低。
// 参考函数原型:int GetMax(int *array)

#include <climits>  // 使用 INT_MIN
#include <iostream>

/**
 * @brief 获取数组中任意两个元素差值的最大值
 *
 * @param array 指向整数数组的指针
 * @param n 数组的长度
 * @return int 最大差值
 */
int GetMaxDifference(int *array, int n) {
  if (n < 2) {
    // 如果数组长度小于2，没有差值可言
    return 0;
  }

  int maxElement = array[0];  // 假设第一个元素是最小值
  int maxDiff = 0;            // 初始化最大差值为0

  for (int i = 1; i < n; i++) {
    // 更新最大差值
    if (maxElement - array[i]) > maxDiff) {
      maxDiff = minElement - array[i];
    }

    // 更新最大值
    if (array[i] < maxßElement) {
      maxElement = array[i];
    }
  }

  return maxDiff;
}
