/**
【2013统考真题】
已知一个整数序列A=（αo，α1，，αn-1)其中0≤α<n（0≤i<n)。若
存在αp1=αp2 =… =αpm=x且m>n/2（O≤pk≤n，1≤k≤m)，则称x为A的主元素。例如 A=（0,
5，5，3，5，7，5，5），则5为主元素；又如A=（0，5，5，3，5，1，5，7），则A中没有主元素。
假设A中的n个元素保存在一个一维数组中，请设计一个尽可能高效的算法，找出
A的主元素。若存在主元素，则输出该元素；否则输出-1。要求：
1）给出算法的基本设计思想。
2）根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
3）说明你所设计算法的时间复杂度和空间复杂度。
*/

/**
 * @brief
 * 桶排序
 */

#include <iostream>
#include <vector>

typedef int ElemType;

struct SqList {
  std::vector<ElemType> data;
  int length;
};

ElemType FindMainEle(const SqList& L) {
  int n = L.length;
  int m = n / 2;
  std::vector<int> bucket(n, 0);  // 使用vector初始化桶数组
  int count = 0;
  int index = 0;

  for (int i = 0; i < n; i++) {
    bucket[L.data[i]]++;
    if (count < bucket[L.data[i]]) {
      count = bucket[L.data[i]];
      index = L.data[i];
    }
  }

  if (count > m) {
    return index;  // 返回主元素
  } else {
    return -1;  // 没有主元素
  }
}

/*
王道的版本


选取候选的主元素。依次扫描所给数组中的每个整数，将第一个遇到的整数Num保存到c中，记录Num的出现次数为l：
若遇到的下一个整数仍等于Num，则计数加1，否则计数减1：当计数减到0时，将遇到的下一个整数保存到c中，计数重新记为1，
开始新一轮计数，即从当前位置开始重复上述过程，直到扫描完全部数组元素。

判断c中元素是否是真正的主元素。再次扫描该数组，统计c中元素出现的次数，若大于n/2，则为主元素；否则，序列中不存在主元素。

int Majority(int A[], int n) {
    int i, c, count = 1; // c用来保存候选主元素，count用来计数
    c = A[0];             // 设置A[0]为候选主元素
    for (i = 1; i < n; i++) {
        // 查找候选主元素
        if (A[i] == c) {
            count++; // 对A中的候选主元素计数
        } else {
            if (count > 0) {
                count--; // 处理不是候选主元素的情况
            } else {
                c = A[i]; // 更换候选主元素，重新计数
                count = 1;
            }
        }
    }

    // 统计候选主元素的实际出现次数
    count = 0;
    for (i = 0; i < n; i++) {
        if (A[i] == c) {
            count++;
        }
    }

    // 确认候选主元素是否存在
    if (count > n / 2) {
        return c;
    } else {
        return -1; // 不存在主元素
    }
}

实现的程序的时间复杂度为O(n)，空间复杂度为O(1)。
*/

int main() {
  SqList L = {{0, 5, 5, 3, 5, 7, 5, 5}, 8};
  std::cout << "主元素: " << FindMainEle(L) << std::endl;
  return 0;
}
