/*
【2021 统考真题】已知无向连通图𝐺由顶点集𝑉和边集𝐸组成,|𝐸| > 0,当𝐺中度为奇数的顶
点个数为不大于 2 的偶数时,𝐺存在包含所有边且长度为|𝐸|的路径(称为 EL
路径)。设图𝐺采用邻接矩阵存储
/*
类型定义如下:
Typedef struct{ //图的定义
int numVertices,numEdges; //图中实际的顶点数和边数
char VerticesList[MAXV]; //顶点表。MAXV 为已定义常量
int Edge[MAXV][MAXV]; //邻接矩阵
}MGraph;
*/
/*
请设计算法 intIsExistEL(MGraph),判断 G 是否存在 EL 路径,若存在,则返回
1,否则返回 0。
要求:
1)给出算法的基本设计思想。
2)根据设计思想,采用 C 或
C++语言描述算法,关键之处给出注释。
3)说明你所设计算法的时间复杂度和空间复杂度。
*/

#define MAXV 100

Typedef struct {              // 图的定义
  int numVertices, numEdges;  // 图中实际的顶点数和边数
  char VerticesList[MAXV];    // 顶点表。MAXV 为已定义常量
  int Edge[MAXV][MAXV];       // 邻接矩阵
} MGraph;

int IsExistEL(MGraph G) {
  int degree[MAXV] = {0};  // 存储每个顶点的度数
  int oddDegreeCount = 0;  // 度为奇数的顶点个数

  // 计算每个顶点的度数
  for (int i = 0; i < G.numVertices; i++) {
    for (int j = 0; j < G.numVertices; j++) {
      if (G.Edge[i][j] == 1) {
        degree[i]++;
      }
    }
  }

  // 统计度为奇数的顶点个数
  for (int i = 0; i < G.numVertices; i++) {
    if (degree[i] % 2 != 0) {
      oddDegreeCount++;
    }
  }

  // 判断度为奇数的顶点个数是否为不大于2的偶数
  if (oddDegreeCount % 2 == 0 && oddDegreeCount <= 2) {
    return 1;  // 存在 EL 路径
  } else {
    return 0;  // 不存在 EL 路径
  }
}
