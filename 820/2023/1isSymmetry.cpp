/*
判断一个数组是否是对称数组，例如 2442, 13431。要求使用栈实现，已经给出栈 sq
和入栈函数 push(sq, data)、出栈函数 pop(sq, data)。
*/

#include <iostream>
#include <stack>

bool isSymmetry(const int arr[], int size) {
  std::stack<int> sq;  // 定义栈对象

  // 将数组前半部分元素入栈
  for (int i = 0; i < size / 2; i++) {
    sq.push(arr[i]);
  }

  // 判断数组后半部分元素是否与栈中元素对称
  for (int i = size / 2 + size % 2; i < size; i++) {
    if (sq.top() != arr[i]) {
      return false;
    }
    sq.pop();
  }

  return true;
}
