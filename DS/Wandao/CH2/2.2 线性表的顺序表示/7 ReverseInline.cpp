// 己知在一维数组， A[m + n]中依次存放两个线性表
// a1,a2,a3......am和b1,b2,b3......bn
// 编写一个函数，将数组中两个顺序表的位置互换，即将b1,b2,b3......bn放在a1,a2,a3......am的前面

#include <iostream>

#include "../include/SqList.h"

// TODO: review this
void ReverseInline(SqList& L, int m, int n) {
  // First, reverse the entire array
  for (int i = 0; i < (m + n) / 2; i++) {
    ElemType temp = L.data[i];
    L.data[i] = L.data[m + n - 1 - i];
    L.data[m + n - 1 - i] = temp;
  }

  // Then, reverse the first n dataents
  for (int i = 0; i < n / 2; i++) {
    ElemType temp = L.data[i];
    L.data[i] = L.data[n - 1 - i];
    L.data[n - 1 - i] = temp;
  }

  // Finally, reverse the last m dataents
  for (int j = n; j < n + m / 2; j++) {
    ElemType temp = L.data[j];
    L.data[j] = L.data[m + n - 1 - (j - n)];
    L.data[m + n - 1 - (j - n)] = temp;
  }
}
