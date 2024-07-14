// 己知在一维数组， A[m + n]中依次存放两个线性表
// a1,a2,a3......am和b1,b2,b3......bn
// 编写一个函数，将数组中两个顺序表的位置互换，即将b1,b2,b3......bn放在a1,a2,a3......am的前面

// TODO: review this
#include <iostream>

#include "../include/SqList.h"

// Swap the positions of two elements in the array
void Swap(ElemType &a, ElemType &b) {
  ElemType temp = a;
  a = b;
  b = temp;
}

// Reverse the elements in the specified range of the array
void Reverse(SqList &L, int start, int end) {
  while (start < end) {
    Swap(L.data[start], L.data[end]);
    start++;
    end--;
  }
}

void ReverseInline(SqList &L, int m, int n) {
  int totalLength = m + n;
  // Check the validity of input parameters
  if (m < 0 || n < 0 || totalLength > L.length) {
    std::cerr << "Invalid input parameters" << std::endl;
    return;
  }

  // Reverse the entire array
  Reverse(L, 0, totalLength - 1);
  // Reverse the first n elements
  Reverse(L, 0, n - 1);
  // Reverse the last m elements
  Reverse(L, n, totalLength - 1);
}
