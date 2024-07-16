// 设计一个高效算法，将顺序表 L 的所有元素逆置，要求算法的空间复杂度为 O(1)

#include <iostream>

#include "../include/SqList.h"

void Reverse(SqList& L) {
  ElemType temp;
  for (int i = 0; i < L.length / 2; i++) {
    temp = L.data[i];
    L.data[i] = L.data[L.length - i - 1];
    L.data[L.length - i - 1] = temp;
  }
}

// Second Version

// void Reverse(SqList& L) {
//   int start = 0;
//   int end = L.length - 1;
//   while (start < end) {
//     std::swap(L.data[start], L.data[end]);
//     start++;
//     end--;
//   }
// }
