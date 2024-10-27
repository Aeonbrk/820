/*
写出折半查找的递归算法。初始调用时,low 为 1,high 为 ST.length
*/

#include <iostream>
using namespace std;

// 定义一个结构体来表示顺序表
struct SeqList {
  int *data;   // 数据数组
  int length;  // 顺序表长度
};

// 折半查找的递归算法
int BinarySearch(SeqList ST, int key, int low, int high) {
  // 如果 low 大于 high，说明查找失败，返回 -1
  if (low > high) {
    return -1;
  }

  // 计算中间位置
  int mid = (low + high) / 2;

  // 如果中间位置的值等于 key，返回中间位置
  if (ST.data[mid] == key) {
    return mid;
  }
  // 如果中间位置的值大于 key，在左半部分继续查找
  else if (ST.data[mid] > key) {
    return BinarySearch(ST, key, low, mid - 1);
  }
  // 如果中间位置的值小于 key，在右半部分继续查找
  else {
    return BinarySearch(ST, key, mid + 1, high);
  }
}

int BinarySearch_NoRecur(SeqList ST, int key, int low, int high) {
  if (low > high) return -1;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (ST.data[mid] == key) {
      return mid;
    } else if (ST.data[mid] > key) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return -1;
}
