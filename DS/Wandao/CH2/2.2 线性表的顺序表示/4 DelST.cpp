// 从顺序表中删除其值在给定值 s 与 t 之间（包含 s 和 t ，要求 s < t ）的所有元素
// 若 s 或 t 不合理或顺序表为空，则显示出错信息并退出运行。

#include <iostream>

#include "../include/SqList.h"

bool DelST(SqList& L, int s, int t) {
  // Not allowed conditions
  if (s >= t || L.length == 0) return false;

  int temp = 0;

  for (int i = 0; i < L.length; i++) {
    // Same idea equal to quesion 3
    if (L.data[i] < s || L.data[i] > t) {
      L.data[temp] = L.data[i];
      temp++;
    }
  }

  L.length = temp;

  return true;
}
