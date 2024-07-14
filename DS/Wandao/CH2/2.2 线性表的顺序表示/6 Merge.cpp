// 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表

#include <iostream>

#include "../include/SqList.h"

// TODO: review this
bool Merge(SqList L1, SqList L2, SqList& L3) {
  if (L1.length + L2.length > L3.length) return false;

  int i = 0, j = 0, k = 0;

  // Merge
  while (i < L1.length && j < L2.length) {
    if (L1.data[i] <= L2.data[j]) {
      L3.data[k++] = L1.data[i++];
    } else {
      L3.data[k++] = L2.data[j++];
    }
  }

  // Copy the remaining elements
  while (i < L1.length) {
    L3.data[k++] = L1.data[i++];
  }
  while (j < L2.length) {
    L3.data[k++] = L2.data[j++];
  }

  L3.length = k;

  return true;
}
