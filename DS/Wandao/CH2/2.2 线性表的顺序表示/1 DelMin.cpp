// 从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。
// 空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。

#include <cassert>
#include <iostream>

#include "../include/SqList.h"

ElemType DelMin(SqList &L) {
  if (L.length == 0) {
    std::cerr << "Error: Sequence list is empty." << std::endl;
    exit(0);
  }

  ElemType min = L.data[0];
  int pos = 0;

  for (int i = 1; i < L.length; i++) {
    if (min < L.data[i]) {
      min = L.data[i];
      pos = i;
    }
  }

  L.data[pos] = L.data[L.length - 1];
  L.length--;

  return min;
}
