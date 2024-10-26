/*
写出从图的邻接表表示转换成邻接矩阵表示的算法
*/

#include <iostream>

#include "../include/Graph.h"

// 将邻接表表示的图转换为邻接矩阵表示的图
void ConvertALGraphToAdjMatrix(ALGraph* G, AdjMatrix* M) {
  // 初始化邻接矩阵
  for (int i = 0; i < G->numV; i++) {
    for (int j = 0; j < G->numV; j++) {
      M->Edge[i][j] = 0;  // 初始化所有边的权重为0，表示没有边
    }
  }

  // 遍历邻接表，填充邻接矩阵
  for (int i = 0; i < G->numV; i++) {
    VertexNode* vertex = &(G->adjList[i]);  // 获取当前顶点
    EdgeNode* edge = vertex->firstEdge;     // 获取当前顶点的第一条边

    // 遍历当前顶点的所有边
    while (edge != nullptr) {
      M->Edge[i][edge->index] = edge->weight;  // 将边的权重赋值给邻接矩阵
      edge = edge->next;                       // 指向下一条边
    }
  }

  // 复制顶点信息
  for (int i = 0; i < G->numV; i++) {
    M->Vertex[i] = G->adjList[i].info;
  }

  // 复制顶点数和边数
  M->numV = G->numV;
  M->numE = G->numE;
}
