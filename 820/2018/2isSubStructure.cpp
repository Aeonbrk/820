/*
2.对于两棵给定的二叉树A和B,判断B是不是A的子结构。(约定空树不是任意一个树的子结构)B是A的子结构,即A中出现和B相同的结构和结点值。
*/

#include <iostream>

// 定义二叉树的节点结构
struct TreeNode {
  int val;          // 节点的值
  TreeNode* left;   // 左子节点
  TreeNode* right;  // 右子节点

  // 构造函数
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 辅助函数：判断从节点 A 开始，是否包含与二叉树 B 相同的结构和节点值
bool doesTreeAHaveTreeB(TreeNode* A, TreeNode* B) {
  if (B == nullptr) {
    // 如果 B 已经遍历完，说明之前的节点都匹配
    return true;
  }
  if (A == nullptr) {
    // 如果 A 先遍历完，而 B 还未遍历完，说明不匹配
    return false;
  }
  if (A->val != B->val) {
    // 如果当前节点的值不相同，直接返回 false
    return false;
  }
  // 递归比较左子树和右子树
  return doesTreeAHaveTreeB(A->left, B->left) &&
         doesTreeAHaveTreeB(A->right, B->right);
}

// 主函数：判断二叉树 B 是否是二叉树 A 的子结构
bool isSubStructure(TreeNode* A, TreeNode* B) {
  if (A == nullptr || B == nullptr) {
    // 根据题目约定，空树不是任意一个树的子结构
    return false;
  }

  // 如果当前A节点和B节点匹配
  if (doesTreeAHaveTreeB(A, B)) {
    return true;
  }

  // 递归检查A的左子树和右子树是否包含B
  return isSubStructure(A->left, B) || isSubStructure(A->right, B);
}

// 辅助函数：手动释放二叉树内存
void freeTree(TreeNode* root) {
  if (root == nullptr) return;
  freeTree(root->left);
  freeTree(root->right);
  delete root;
}

int main() {
  /*
      构建二叉树 A:
           3
          / \
         4   5
        / \
       1   2

      构建二叉树 B:
         4
        /
       1
  */

  // 手动构建二叉树 A
  TreeNode* A = new TreeNode(3);
  A->left = new TreeNode(4);
  A->right = new TreeNode(5);
  A->left->left = new TreeNode(1);
  A->left->right = new TreeNode(2);

  // 手动构建二叉树 B
  TreeNode* B = new TreeNode(4);
  B->left = new TreeNode(1);

  // 调用函数进行判断
  bool result = isSubStructure(A, B);
  std::cout << (result ? "B 是 A 的子结构" : "B 不是 A 的子结构") << std::endl;

  // 释放内存
  freeTree(A);
  freeTree(B);

  return 0;
}
