/**
 * 设规模n=3m, m≥1的顺序表存储在一维数组int array[n]中，它含有的元素为
 * (a1, a2, ..., am, b1, b2, ..., bm, c1, c2, ..., cm)。
 * 请编写算法将上述顺序表改造成为
 * (c1, c2, ..., cm, bm,...,b2, b1, a1, a2, ..., am)，
 * 要求时间复杂度和空间复杂度尽可能低。
 * 程序设计语言可以选用 C、C++、Java。
 */

// 原地反转
void reverse(int array[], int start, int end) {
  while (start < end) {
    int temp = array[start];
    array[start] = array[end];
    array[end] = temp;
    start++;
    end--;
  }
}

void ChangeFrontAndTail(int array[], int n) {
  int m = n / 3;

  // 反转整个数组
  reverse(array, 0, n - 1);

  // 反转前 m 个元素
  reverse(array, 0, m - 1);

  // 反转中间 m 个元素
  reverse(array, m, 2 * m - 1);

  // 反转最后 m 个元素
  reverse(array, 2 * m, n - 1);
}

/*
时间复杂度为 O(n)，空间复杂度为 O(1)
*/
