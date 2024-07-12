#define ElemType int
#define InitSize 100

// Define the structure of SqList
typedef struct {
  ElemType *data;
  int length, MaxSize;
} SqList;

// Function prototypes for basic operations on SqList

// Initialize an empty SqList
void InitList(SqList L) {
  L.data = new ElemType[InitSize];
  L.length = 0;
}

// Get the element at a specific position in the SqList
bool GetElem(SqList &L, int pos, ElemType *e) {
  if (pos < 1 || pos > L.length) return false;
  *e = L.data[pos - 1];
  return true;
}

// Find the first occurrence of an element in the SqList
int LocateElem(SqList L, ElemType e) {
  for (int i = 0; i < L.length; i++) {
    if (L.data[i] == e) return i + 1;
  }
  return 0;
}

// Insert an element at a specific position in the SqList
bool ListInsert(SqList &L, int pos, ElemType e) {
  if (L.length >= L.MaxSize || pos < 1 || pos > L.length + 1) return false;
  for (int i = L.length; i >= pos; i--) {
    L.data[i] = L.data[i - 1];
  }
  L.data[pos - 1] = e;
  L.length++;
  return true;
}

// Delete an element at a specific position in the SqList
bool ListDelete(SqList &L, int pos, ElemType *e) {
  if (L.length == 0 || pos < 1 || pos > L.length) return false;
  *e = L.data[pos - 1];
  for (int i = pos; i < L.length; i++) {
    L.data[i - 1] = L.data[i];
  }
  return true;
}
