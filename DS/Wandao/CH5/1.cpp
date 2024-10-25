/*
已知一棵二叉树按顺序存储结构进行存储,设计一个算法,求编号分别为𝑖和𝑗的两个结点的
最近的公共祖先结点的值
*/

void findRecentAncestor(int a[], int n, int i, int j) {
  // 确保i和j在有效范围内
  if (i < 1 || i > n || j < 1 || j > n) {
    cout << "Invalid node indices" << endl;
    return;
  }

  // 将i和j转换为数组索引（数组从0开始）
  i--;
  j--;

  // 从下往上查找公共祖先
  while (i != j) {
    if (i > j) {
      // i向上移动到其父节点
      i = (i - 1) / 2;
    } else {
      // j向上移动到其父节点
      j = (j - 1) / 2;
    }
  }

  // 输出最近公共祖先节点的值
  cout << "The value of the recent common ancestor is: " << a[i] << endl;
}
