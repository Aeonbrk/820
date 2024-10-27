// 对长度为 n 的顺序表 L ，编写一个时间复杂度为 O (n) 、空间复杂度为 O(1）的算法
// 该算法删除线性表中所有值为 x 的数据元素。

#include <iostream>

#include "../include/SqList.h"

bool DelAllX(SqList& L, int x) {
  if (L.length == 0) return false;

  int temp = 0;

  for (int i = 0; i < L.length; i++) {
    // if L.data[i] == x, then skip this element
    if (L.data[i] != x) {
      L.data[temp] = L.data[i];
      temp++;
    }
  }

  L.length = temp;

  return true;
}
