/*
一个二叉排序树中，如何寻找结点值小于 x 且是所有满足该条件的结点中值最大的结点？
给出你的算法设计思想；采用 C、C++ 或 Java 的程序设计语言完成该算法的设计。
*/

#include <iostream>

typedef struct Tree {
  int data;
  Tree* left;
  Tree* right;
} Tree;

// 查找小于 x 的最大节点
Tree* findMaxLessThanX(Tree* root, int x) {
  Tree* result = nullptr;

  while (root != nullptr) {
    if (root->data < x) {
      // 当前节点小于 x，记录为当前最优解
      result = root;
      // 查找右子树
      root = root->right;
    } else {
      // 当前节点不小于 x，查找左子树
      root = root->left;
    }
  }

  return result;
}

/*
时间复杂度为
O(log⁡n)（对于平衡的二叉排序树），最坏情况为O(n)。
空间复杂度为 O(1)
*/
