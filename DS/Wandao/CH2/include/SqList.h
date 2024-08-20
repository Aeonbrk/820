#define ElemType int
#define InitSize 100

// 定义顺序表的结构
typedef struct {
  ElemType *data;  // 存储元素的数组指针
  int length;      // 当前长度
  int MaxSize;     // 最大容量
} SqList;

// 初始化顺序表
/**
 * 初始化一个空的顺序表。
 *
 * @param L 要初始化的顺序表。
 */
void InitList(SqList &L) {
  L.data = new ElemType[InitSize];  // 分配初始大小的数组
  L.length = 0;                     // 初始长度为0
  L.MaxSize = InitSize;             // 初始最大容量
}

// 获取指定位置的元素
/**
 * 获取顺序表中指定位置的元素。
 *
 * @param L 要操作的顺序表。
 * @param pos 要获取元素的位置（1-based index）。
 * @param e 存储获取到的元素的指针。
 * @return 如果成功获取元素返回true，否则返回false。
 */
bool GetElem(SqList &L, int pos, ElemType *e) {
  if (pos < 1 || pos > L.length) return false;  // 位置不合法
  *e = L.data[pos - 1];                         // 获取元素
  return true;
}

// 查找元素的位置
/**
 * 查找顺序表中第一个出现的指定元素的位置。
 *
 * @param L 要搜索的顺序表。
 * @param e 要查找的元素。
 * @return 第一个出现该元素的位置（1-based index），如果未找到返回0。
 */
int LocateElem(SqList L, ElemType e) {
  for (int i = 0; i < L.length; i++) {
    if (L.data[i] == e) return i + 1;  // 找到元素，返回位置
  }
  return 0;  // 未找到元素
}

// 在指定位置插入元素
/**
 * 在顺序表的指定位置插入元素。
 *
 * @param L 要插入元素的顺序表。
 * @param pos 插入位置（1-based index）。
 * @param e 要插入的元素。
 * @return 如果成功插入元素返回true，否则返回false。
 */
bool ListInsert(SqList &L, int pos, ElemType e) {
  if (L.length >= L.MaxSize || pos < 1 || pos > L.length + 1)
    return false;  // 插入位置不合法或容量不足
  for (int i = L.length; i >= pos; i--) {
    L.data[i] = L.data[i - 1];  // 向后移动元素
  }
  L.data[pos - 1] = e;  // 插入元素
  L.length++;           // 长度增加
  return true;
}

// 删除指定位置的元素
/**
 * 删除顺序表中指定位置的元素。
 *
 * @param L 要删除元素的顺序表。
 * @param pos 删除位置（1-based index）。
 * @param e 存储删除的元素的指针。
 * @return 如果成功删除元素返回true，否则返回false。
 */
bool ListDelete(SqList &L, int pos, ElemType *e) {
  if (L.length == 0 || pos < 1 || pos > L.length)
    return false;        // 删除位置不合法或顺序表为空
  *e = L.data[pos - 1];  // 获取删除的元素
  for (int i = pos; i < L.length; i++) {
    L.data[i - 1] = L.data[i];  // 向前移动元素
  }
  L.length--;  // 长度减少
  return true;
}
