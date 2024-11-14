/*
给出二叉树的后序和中序遍历结果，求最短路径径值叶子节点值。结点个数范围为
0-25；结点取值范围为 0-250。（路径指从根节点到叶子节点的值之和）
*/

#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>

// 定义二叉树结构
typedef struct Tree {
  int data;
  Tree* left;
  Tree* right;
} Tree;

// 根据后序和中序遍历结果构建二叉树
Tree* buildTree(const std::vector<int>& postorder,
                const std::vector<int>& inorder, int postStart, int postEnd,
                int inStart, int inEnd,
                std::unordered_map<int, int>& inorderMap) {
  if (postStart > postEnd || inStart > inEnd) {
    return nullptr;
  }

  // 后序遍历的最后一个元素是根节点
  int rootVal = postorder[postEnd];
  Tree* root = new Tree{rootVal, nullptr, nullptr};

  // 在中序遍历中找到根节点的位置
  int rootIndex = inorderMap[rootVal];

  // 递归构建左子树和右子树
  root->left = buildTree(postorder, inorder, postStart,
                         postStart + rootIndex - inStart - 1, inStart,
                         rootIndex - 1, inorderMap);
  root->right = buildTree(postorder, inorder, postStart + rootIndex - inStart,
                          postEnd - 1, rootIndex + 1, inEnd, inorderMap);

  return root;
}

// 计算从根节点到叶子节点的最短路径值
void findMinPathSum(Tree* root, int currentSum, int& minSum) {
  if (!root) {
    return;
  }

  // 更新当前路径的和
  currentSum += root->data;

  // 如果是叶子节点，更新最小路径和
  if (!root->left && !root->right) {
    minSum = std::min(minSum, currentSum);
  }

  // 递归遍历左子树和右子树
  findMinPathSum(root->left, currentSum, minSum);
  findMinPathSum(root->right, currentSum, minSum);
}
