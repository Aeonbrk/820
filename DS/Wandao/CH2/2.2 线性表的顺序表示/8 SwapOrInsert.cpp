// 线性表a1,a2,a3,......,an中的元素递增有序且按顺序存储于计算机内。
// 要求设计一个算法，完成用最少时间在表中查找数值为 x 的元素
// 若找到，则将其与后继元素位置相交换，若找不到，则将其插入表中并使表中元素仍递增有序。

#include <iostream>

#include "../include/SqList.h"

// TODO: review this

/**
int BinarySearch(const SqList& L, ElemType x) {
  int low = 0, high = L.length - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (L.data[mid] == x) {
      return mid;
    } else if (L.data[mid] < x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

void SwapOrInsert(SqList& L, ElemType x) {
  int pos = BinarySearch(L, x);
  if (pos != -1) {
    // 找到了，交换该元素与后继元素的位置
    if (pos < L.length - 1) {
      ElemType temp = L.data[pos];
      L.data[pos] = L.data[pos + 1];
      L.data[pos + 1] = temp;
    }
  } else {
    // 未找到，找到插入的位置
    int i;
    for (i = L.length - 1; i >= 0 && L.data[i] > x; i--) {
      L.data[i + 1] = L.data[i];
    }
    L.data[i + 1] = x;
    L.length++;
  }
}
*/

void SwapOrInsert(SqList& L, ElemType x) {
  ElemType temp;
  // 初始化为 -1，以防止所有元素都大于 x
  // 这里一开始没考虑到，下次注意
  int posMin = -1;

  for (int i = 0; i + 1 < L.length; i++) {
    if (L.data[i] == x) {
      temp = L.data[i];
      L.data[i] = L.data[i + 1];
      L.data[i + 1] = temp;

      break;  // 找到并交换后立即退出循环
    }
    if (L.data[i] < x) {
      posMin = i;  // 更新插入位置
    }
  }

  ListInsert(L, posMin + 1, x);
}
