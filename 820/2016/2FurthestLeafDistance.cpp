/**
 * 二叉树用二叉链表结构进行存储。
 * 请编写算法求二叉树根节点左右子树相隔最远的叶子节点之间距离。
 */

#include <algorithm>
#include <iostream>

typedef struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;
} TreeNode;

// 求二叉树最大深度
int getDepth(TreeNode* node) {
  if (node == nullptr) {
    return 0;
  }
  return std::max(getDepth(node->left), getDepth(node->right)) + 1;
}

/**
 * 求二叉树根节点左右子树相隔最远的叶子节点之间的距离
 * @param node 二叉树的根节点
 * @return 最远叶子节点之间的距离
 */
int c(TreeNode* node) {
  if (node == nullptr) {
    return 0;
  }
  // 计算左子树的最大深度
  int left_depth = getDepth(node->left);
  // 计算右子树的最大深度
  int right_depth = getDepth(node->right);
  // 计算当前节点下的最远叶子节点距离
  int distance = left_depth + right_depth + 1;
  return distance;
}

/*
getDepth 函数: 时间复杂度 O(n)，空间复杂度 O(h)。
FurthestLeafDistance 函数: 时间复杂度 O(n)，空间复杂度 O(h)
*/
