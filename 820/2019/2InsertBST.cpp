// (8分)对于链式存储的二叉排序树，在该二叉排序树中插入元素:
// 若二叉排序树存在该元素则函数结束,否则插入该元素。
// 试用C、C++或JAVA的程序设计语言编写插入元素至该二叉排序树的函数。

#include <iostream>

// 定义二叉树节点结构体
struct Tree {
  int data;     // 节点存储的数据
  Tree* left;   // 左子树指针
  Tree* right;  // 右子树指针

  // 构造函数，用于初始化节点
  Tree(int _data, Tree* _left = nullptr, Tree* _right = nullptr)
      : data(_data), left(_left), right(_right) {}
};

// 插入元素至二叉排序树的函数
void InsertBST(Tree*& root, int k) {
  // 如果根节点为空，直接创建新节点作为根节点
  if (root == nullptr) {
    root = new Tree(k);
    return;
  }

  // 如果当前节点的数据等于要插入的元素，直接返回（元素已存在）
  if (root->data == k) {
    return;
  }
  // 如果要插入的元素大于当前节点的数据
  else if (root->data < k) {
    // 如果右子树不为空，递归插入到右子树
    if (root->right != nullptr) {
      InsertBST(root->right, k);
    }
    // 如果右子树为空，创建新节点并插入到右子树
    else {
      root->right = new Tree(k);
    }
  }
  // 如果要插入的元素小于当前节点的数据
  else {
    // 如果左子树不为空，递归插入到左子树
    if (root->left != nullptr) {
      InsertBST(root->left, k);
    }
    // 如果左子树为空，创建新节点并插入到左子树
    else {
      root->left = new Tree(k);
    }
  }
}
