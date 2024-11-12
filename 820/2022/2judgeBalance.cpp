// 用分治思想,判断二叉树是否平衡?请写出判断二叉树是否平衡的递归函数。
// 判断二叉树是否平衡的函数原型如下:
// 是平衡二叉树返回 1,否则返回 0.

// 时间复杂度O(n^2)
#include <algorithm>
#include <iostream>

// 定义二叉树节点的结构体
typedef struct node {
  int data;                   // 节点存储的数据
  struct node *left, *right;  // 指向左子节点和右子节点的指针
} node, *ptr, *BiTree;

// 获取二叉树的深度
int getDepth(BiTree root) {
  if (root == nullptr) {  // 如果节点为空，深度为0
    return 0;
  }
  // 递归获取左子树和右子树的深度，取最大值并加1
  return std::max(getDepth(root->left), getDepth(root->right)) + 1;
}

// 判断二叉树是否平衡
int judgeBalance(BiTree root) {
  if (root == nullptr) {  // 如果节点为空，认为是平衡的
    return 1;
  }

  int leftDepth = getDepth(root->left);    // 获取左子树的深度
  int rightDepth = getDepth(root->right);  // 获取右子树的深度

  // 如果左右子树的深度差不超过1，则继续判断左右子树是否平衡
  if (std::abs(leftDepth - rightDepth) <= 1) {
    return judgeBalance(root->left) && judgeBalance(root->right);
  }

  return 0;  // 如果不平衡，返回0
};
}

// 时间复杂度O(n)
// 空间复杂度为O(h),h为树的高度(递归栈深度)
// 采用自底向上的方法,只需要遍历一次树
// 使用-1作为特殊标记表示非平衡子树
// 在计算树高的同时判断是否平衡
// 一旦发现不平衡,通过返回-1快速结束递归
/*
#include <algorithm>
#include <iostream>

typedef struct node {
  int data;
  struct node *left, *right;
} node, *ptr, *BiTree;

// 使用-1标记非平衡子树
// 返回值: -1表示非平衡树,>=0表示树的高度
int isBalanced(BiTree root) {
  // 空节点高度为0
  if (root == nullptr) {
    return 0;
  }

  // 递归获取左子树高度
  int leftHeight = isBalanced(root->left);
  // 如果左子树不平衡,直接返回-1
  if (leftHeight == -1) {
    return -1;
  }

  // 递归获取右子树高度
  int rightHeight = isBalanced(root->right);
  // 如果右子树不平衡,直接返回-1
  if (rightHeight == -1) {
    return -1;
  }

  // 检查当前节点是否平衡
  if (std::abs(leftHeight - rightHeight) > 1) {
    return -1;  // 高度差大于1,不平衡
  }

  // 返回当前树的高度
  return std::max(leftHeight, rightHeight) + 1;
}

// 包装函数,返回1表示平衡,0表示不平衡
int judgeBalance(BiTree root) {
  return isBalanced(root) != -1;
}
*/
