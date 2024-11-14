// 2.（(8分)所谓镜像二叉树就是以根结点做铅垂线，左右子树关于该铅垂线对称。试设计一个算法判断给定二叉树是否为镜像二叉树。
// 参考函数原型：int IsSymmetricTree(BiTreeNode*root)

#include <stdbool.h>

struct BiTreeNode {
  int data;
  struct BiTreeNode *left;
  struct BiTreeNode *right;
};

// 辅助函数，用于递归地检查两棵树是否镜像对称
bool isMirror(struct BiTreeNode *tree1, struct BiTreeNode *tree2) {
  if (tree1 == NULL && tree2 == NULL) return true;   // 两棵树都为空
  if (tree1 == NULL || tree2 == NULL) return false;  // 仅有一棵树为空

  // 检查当前节点值是否相同，以及子树是否镜像对称
  return (tree1->data == tree2->data) && isMirror(tree1->left, tree2->right) &&
         isMirror(tree1->right, tree2->left);
}

// 主函数，用于判断二叉树是否为镜像二叉树
int IsSymmetricTree(struct BiTreeNode *root) {
  if (root == NULL) return 1;  // 空树被认为是镜像对称的
  return isMirror(root->left, root->right);  // 调用辅助函数
}
