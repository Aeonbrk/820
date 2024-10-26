#include <iostream>
#ifndef GRAPH_H
#define GRAPH_H

#define Maxsize 200

// 定义邻接矩阵表示的图结构
/**
 * AdjMatrix - 表示邻接矩阵表示的图结构。
 * @Vertex: 存储顶点信息的数组。
 * @Edge: 存储边的信息的二维数组。
 * @numV: 顶点数。
 * @numE: 边数。
 */
typedef struct Graph {
  char Vertex[Maxsize];        // 存储顶点信息
  int Edge[Maxsize][Maxsize];  // 存储边的信息
  int numV, numE;              // 顶点数和边数
} AdjMatrix;

// 定义邻接表中的边节点结构
/**
 * EdgeNode - 表示邻接表中的边节点。
 * @index: 边的目标顶点索引。
 * @weight: 边的权重。
 * @next: 指向下一个边节点的指针。
 */
typedef struct EdgeNode {
  int index;       // 边的目标顶点索引
  int weight;      // 边的权重
  EdgeNode* next;  // 指向下一个边节点的指针
} EdgeNode;

// 定义邻接表中的顶点节点结构
/**
 * VertexNode - 表示邻接表中的顶点节点。
 * @info: 顶点信息。
 * @firstEdge: 指向第一个边节点的指针。
 */
typedef struct VertexNode {
  char info;            // 顶点信息
  EdgeNode* firstEdge;  // 指向第一个边节点的指针
} VertexNode, AdjList[Maxsize];

// 定义邻接表表示的图结构
/**
 * ALGraph - 表示邻接表表示的图结构。
 * @adjList: 邻接表。
 * @numV: 顶点数。
 * @numE: 边数。
 */
typedef struct {
  AdjList adjList;  // 邻接表
  int numV, numE;   // 顶点数和边数
} ALGraph;

// 函数声明
/**
 * CreateAdjMatrix - 创建邻接矩阵表示的图。
 * @G: 指向邻接矩阵表示的图的指针。
 */
void CreateAdjMatrix(AdjMatrix* G);

/**
 * CreateALGraph - 创建邻接表表示的图。
 * @G: 指向邻接表表示的图的指针。
 */
void CreateALGraph(ALGraph* G);

/**
 * AddEdgeToMatrix - 向邻接矩阵表示的图中添加边。
 * @G: 指向邻接矩阵表示的图的指针。
 * @start: 边的起始顶点索引。
 * @end: 边的目标顶点索引。
 * @weight: 边的权重。
 */
void AddEdgeToMatrix(AdjMatrix* G, int start, int end, int weight);

/**
 * AddEdgeToALGraph - 向邻接表表示的图中添加边。
 * @G: 指向邻接表表示的图的指针。
 * @start: 边的起始顶点索引。
 * @end: 边的目标顶点索引。
 * @weight: 边的权重。
 */
void AddEdgeToALGraph(ALGraph* G, int start, int end, int weight);

/**
 * PrintAdjMatrix - 打印邻接矩阵表示的图。
 * @G: 指向邻接矩阵表示的图的指针。
 */
void PrintAdjMatrix(AdjMatrix* G);

/**
 * PrintALGraph - 打印邻接表表示的图。
 * @G: 指向邻接表表示的图的指针。
 */
void PrintALGraph(ALGraph* G);

#endif  // GRAPH_H

void CreateAdjMatrix(AdjMatrix* G) {
  std::cout << "Enter number of vertices: ";
  std::cin >> G->numV;
  std::cout << "Enter number of edges: ";
  std::cin >> G->numE;

  for (int i = 0; i < G->numV; ++i) {
    std::cout << "Enter vertex " << i << " info: ";
    std::cin >> G->Vertex[i];
  }

  for (int i = 0; i < G->numV; ++i) {
    for (int j = 0; j < G->numV; ++j) {
      G->Edge[i][j] = 0;  // 初始化边为0
    }
  }

  for (int i = 0; i < G->numE; ++i) {
    int start, end, weight;
    std::cout << "Enter edge (start end weight): ";
    std::cin >> start >> end >> weight;
    AddEdgeToMatrix(G, start, end, weight);
  }
}

void CreateALGraph(ALGraph* G) {
  std::cout << "Enter number of vertices: ";
  std::cin >> G->numV;
  std::cout << "Enter number of edges: ";
  std::cin >> G->numE;

  for (int i = 0; i < G->numV; ++i) {
    std::cout << "Enter vertex " << i << " info: ";
    std::cin >> G->adjList[i].info;
    G->adjList[i].firstEdge = nullptr;
  }

  for (int i = 0; i < G->numE; ++i) {
    int start, end, weight;
    std::cout << "Enter edge (start end weight): ";
    std::cin >> start >> end >> weight;
    AddEdgeToALGraph(G, start, end, weight);
  }
}

void AddEdgeToMatrix(AdjMatrix* G, int start, int end, int weight) {
  if (start >= 0 && start < G->numV && end >= 0 && end < G->numV) {
    G->Edge[start][end] = weight;
    G->Edge[end][start] = weight;  // 如果是无向图
  }
}

void AddEdgeToALGraph(ALGraph* G, int start, int end, int weight) {
  if (start >= 0 && start < G->numV && end >= 0 && end < G->numV) {
    EdgeNode* newEdge = new EdgeNode;
    newEdge->index = end;
    newEdge->weight = weight;
    newEdge->next = G->adjList[start].firstEdge;
    G->adjList[start].firstEdge = newEdge;

    // 如果是无向图
    newEdge = new EdgeNode;
    newEdge->index = start;
    newEdge->weight = weight;
    newEdge->next = G->adjList[end].firstEdge;
    G->adjList[end].firstEdge = newEdge;
  }
}

void PrintAdjMatrix(AdjMatrix* G) {
  std::cout << "Adjacency Matrix:" << std::endl;
  for (int i = 0; i < G->numV; ++i) {
    for (int j = 0; j < G->numV; ++j) {
      std::cout << G->Edge[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void PrintALGraph(ALGraph* G) {
  std::cout << "Adjacency List:" << std::endl;
  for (int i = 0; i < G->numV; ++i) {
    std::cout << G->adjList[i].info << " -> ";
    EdgeNode* edge = G->adjList[i].firstEdge;
    while (edge) {
      std::cout << "(" << edge->index << ", " << edge->weight << ") ";
      edge = edge->next;
    }
    std::cout << std::endl;
  }
}
