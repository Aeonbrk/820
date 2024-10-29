/*
【2014 统考真题】二叉树的带权路径长度(WPL)是二叉树中所有叶结点的带权路径长度之
和。给定一棵二叉树𝑇,采用二叉链表存储,结点结构为
| left | weight | right |
其中叶结点的 weight 域保存该结点的非负权值。设 root
为指向 𝑇 的根结点的指针,请设计求 𝑇 的 WPL 的算法,要求:
1)给出算法的基本设计思想。
2)使用C或C++语言,给出二叉树结点的数据类型定义。
3)根据设计思想,采用 C 或 C++语言描述算法,关键之处给出注释
*/

#include <iostream>
using namespace std;

// 二叉树结点的数据类型定义
struct TreeNode {
  int weight;       // 结点的权值
  TreeNode* left;   // 左子树指针
  TreeNode* right;  // 右子树指针
  TreeNode(int w) : weight(w), left(nullptr), right(nullptr) {}
};

// 计算二叉树的带权路径长度（WPL）
int calculateWPL(TreeNode* root, int depth) {
  if (root == nullptr) {
    return 0;  // 空节点不计算WPL
  }

  // 如果是叶子节点，返回其带权路径长度
  if (root->left == nullptr && root->right == nullptr) {
    return root->weight * depth;
  }

  // 递归计算左右子树的WPL
  int leftWPL = calculateWPL(root->left, depth + 1);
  int rightWPL = calculateWPL(root->right, depth + 1);

  // 返回左右子树WPL之和
  return leftWPL + rightWPL;
}

// 计算二叉树的WPL
int WPL(TreeNode* root) {
  return calculateWPL(root, 0);  // 从根节点开始，初始深度为0
}
