// 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。

#include <iostream>

#include "../include/SqList.h"

bool DelSame(SqList& L) {
  if (L.length == 0) return false;

  int temp = 0;

  for (int i = 0; i < L.length; i++) {
    // if L.data[i] == L.data[i + 1], then skip this element
    if (L.data[i] != L.data[i + 1]) {
      L.data[temp] = L.data[i];
      temp++;
    }
  }

  L.length = temp;

  return true;
}
