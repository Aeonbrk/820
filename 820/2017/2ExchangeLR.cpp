/*
给对一个采用二叉链表存储的二叉树，设计一个算法以交换二叉树的左右子树，要求：
(1)给出算法的基本思想；
(2)根据设计思想, 选用C、C++、Java程序设计语言以完成该算法的设计;
(3)说明你所设计的算法的时间复杂度。
*/

typedef struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;
} TreeNode;

void ExchangeLR(TreeNode* L) {
  // 边界条件检查
  if (L == nullptr) {
    return;
  }

  // 交换左右子树
  TreeNode* temp = L->left;
  L->left = L->right;
  L->right = temp;

  // 递归交换左子树和右子树
  ExchangeLR(L->left);
  ExchangeLR(L->right);
}
