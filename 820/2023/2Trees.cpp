// b 二叉树

// (1) 递归地对两个数组分别建立二叉排序树 T1,T2，数组p长度为k1，数组q长度为k2.
// (2) 对 p 和 q 建立的二叉排序树进行合并为新二叉排序树

#include <stdio.h>
#include <stdlib.h>

// 定义二叉排序树节点结构
typedef struct bstree {
  int data;
  struct bstree* left;
  struct bstree* right;
} bstree;

/**
 * 创建一个新的二叉排序树节点
 * @param value 节点值
 * @return 指向新节点的指针
 */
bstree* createNode(int value) {
  bstree* newNode = (bstree*)malloc(sizeof(bstree));
  if (newNode == NULL) {
    printf("内存分配失败\n");
    exit(1);
  }
  newNode->data = value;
  newNode->left = newNode->right = NULL;
  return newNode;
}

/**
 * 将值插入到二叉排序树中
 * @param T 当前树的根节点
 * @param value 要插入的值
 * @return 更新后的树的根节点
 */
bstree* insert(bstree* T, int value) {
  if (T == NULL) {
    // 如果当前节点为空，创建一个新节点
    return createNode(value);
  }
  if (value < T->data) {
    // 插入到左子树
    T->left = insert(T->left, value);
  } else if (value > T->data) {
    // 插入到右子树
    T->right = insert(T->right, value);
  }
  // 如果值已存在，不插入重复值
  return T;
}

/**
 * 递归地根据数组创建二叉排序树
 * @param T 当前树的根节点（通过指针传递）
 * @param L 输入数组
 * @param N 数组长度
 */
void Createbstree(bstree** T, int L[], int N) {
  if (N <= 0) return;  // 基本情况：数组为空
  for (int i = 0; i < N; i++) {
    *T = insert(*T, L[i]);
  }
}

/**
 * 中序遍历二叉排序树并将元素插入到目标树中
 * @param source 源树
 * @param target 目标树
 */
void inorderMerge(bstree* source, bstree** target) {
  if (source == NULL) return;
  inorderMerge(source->left, target);
  *target = insert(*target, source->data);
  inorderMerge(source->right, target);
}

/**
 * 合并两个二叉排序树为一个新的二叉排序树
 * @param T1 树1的根节点
 * @param T2 树2的根节点
 * @return 新合并的树的根节点
 */
bstree* mergebstree(bstree* T1, bstree* T2) {
  bstree* merged = NULL;
  // 将T1的所有元素插入到merged中
  inorderMerge(T1, &merged);
  // 将T2的所有元素插入到merged中
  inorderMerge(T2, &merged);
  return merged;
}

/*
时间复杂度分析
创建二叉排序树 (Createbstree)

每次插入操作的平均时间复杂度为 O(log N)，最坏情况下为 O(N)（当树退化为链表）。
对于 k1 个元素，平均时间复杂度为 O(k1 log k1)，最坏时间复杂度为 O(k1²)。
合并二叉排序树 (mergebstree)

中序遍历每棵树的时间复杂度为 O(N)。
插入所有元素到新树中，平均每次插入为 O(log N)，总时间复杂度为 O(N log N)。
对于两棵树，时间复杂度为 O((k1 + k2) log (k1 + k2))。
空间复杂度分析
创建与合并树

每棵树需要存储所有节点，空间复杂度为 O(k1 + k2)。
递归调用栈的空间复杂度为 O(H)，其中 H 为树的高度。对于不平衡树，H = O(N)。
额外空间

mergebstree 函数创建了一个新的树，额外空间为 O(k1 + k2)。
*/
