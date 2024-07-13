// 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表

#include <iostream>

#include "../include/SqList.h"

// TODO: review this
SqList Merge(SqList& L1, SqList& L2) {
  SqList L;
  InitList(L);

  int i = 0;
  int j = 0;

  // Merge
  while (i < L1.length && j < L2.length) {
    if (L1.data[i] <= L2.data[j]) {
      ListInsert(L, L.length++, L1.data[i]);
      i++;
    } else {
      ListInsert(L, L.length++, L2.data[j]);
      j++;
    }
  }

  // Copy the remaining elements
  while (i < L1.length) {
    L.data[L.length++] = L1.data[i++];
  }

  while (j < L2.length) {
    L.data[L.length++] = L2.data[j++];
  }

  return L;
}
