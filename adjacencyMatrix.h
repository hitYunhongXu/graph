//
// Created by xyh on 2020/9/26.
//

#ifndef MYGRAPH_ADJACENCYMATRIX_H
#define MYGRAPH_ADJACENCYMATRIX_H

/* 图的邻接矩阵表示法 */
#include <iostream>
#define maxVertexNum 100    /* 最大顶点数设为100 */
#define INFINITY 65535  /* ∞设为双字节无符号整数的最大值65535*/
using vertex = int; /* 用顶点下标表示顶点,为整型 */
using dataType = char;  /* 顶点存储的数据类型设为字符型 */
using weightType = int; /* 边的权值设为整型 */

/* 边的定义 */
using ptrToENode = struct ENode*;
struct ENode
{
	vertex v1, v2; // 有向边 <v1, v2>
	weightType weight; // 权重
};
using edge = ENode*;

/* 图节点的定义*/
using ptrToGNode = struct GNode*;
struct GNode
{
	int Nv; // 顶点数
	int Ne; // 边数
	weightType G[maxVertexNum][maxVertexNum];
	dataType data[maxVertexNum];
};
using MGraph = GNode*;

MGraph createGraph(int vertexNum)
{
	// 初始化一个有vertexNum个顶点但没有边的图
	vertex v, w;
	MGraph graph;
	graph = new GNode;
	graph->Nv = vertexNum;
	graph->Ne = 0;
	/* 初始化邻接矩阵 */
	/* 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) */
	for (v = 0; v<graph->Nv; v++)
		for (w = 0; w<graph->Nv; w++)
		{
			graph->G[v][w] = INFINITY;
		}
	return graph;
}

void insertEdge (MGraph graph, edge e)
{
	//插入边 <v1, v2>
	graph->G[e->v1][e->v2] = e->weight;
	/* 若是无向图，还要插入边<V2, V1> */
	graph->G[e->v2][e->v1] = e->weight;
}


MGraph buildGraph()
{
	MGraph graph;
	edge e;
	vertex v;
	int Nv, i;
	std::cin >> Nv;
	graph = createGraph(Nv);

	std::cin >> graph->Ne;
	if (graph->Ne != 0)
	{
		e = new ENode;
		for(i = 0; i < graph->Ne; i++)
		{
			std::cin >> e->v1 >> e->v2 >> e->weight;
			insertEdge(graph, e);
		}
	}

	for (v = 0; v < graph->Nv; v++)
	{
		std::cin >> graph->data[v];
	}
	return graph;
}




#endif //MYGRAPH_ADJACENCYMATRIX_H
