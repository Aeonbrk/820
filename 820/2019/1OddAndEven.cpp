// 1.(7分)将一个线性表中的数据按奇数在前，偶数在后的顺序排列，要求时间复杂度与空间复杂度尽量小。

void OddAndEven(int a[], int size) {
  int low = 0;          // 初始化低位指针
  int high = size - 1;  // 初始化高位指针
  int temp;             // 用于交换的临时变量

  while (low < high) {  // 当低位指针小于高位指针时继续循环
    //注意细节，是a[]%2，别搞成low和high%2了
    while (low < high && a[high] % 2 == 0) {  // 从高位向低位寻找第一个奇数
      high--;
    }
    while (low < high && a[low] % 2 != 0) {  // 从低位向高位寻找第一个偶数
      low++;
    }
    if (low < high) {  // 如果低位指针仍然小于高位指针，交换两个元素
      temp = a[low];
      a[low] = a[high];
      a[high] = temp;
    }
  }
}

/*
时间复杂度为 O(n)，空间复杂度为 O(1)
*/
