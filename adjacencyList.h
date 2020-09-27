//
// Created by xyh on 2020/9/26.
//

#ifndef MYGRAPH_ADJACENCYLIST_H
#define MYGRAPH_ADJACENCYLIST_H
#include <iostream>
/* 图的邻接表表示法 */

#define maxVertexNum 100
using vertex = int;
using weightType  = int ;
using dataType = char;

/* 边的定义 */
using ptrToENode = struct ENode*;
struct ENode{
	vertex v1, v2;
	weightType weight;
};
using edge = ENode*;

/* 邻接点的定义 */
using ptrToAdjVNode = struct adjVNode*;
struct adjVNode
{
	vertex adjV;
	weightType  weight;
	ptrToAdjVNode next;
};

/* 顶点表头的定义 */
struct VNode
{
	ptrToAdjVNode firstEdge;    /* 边表头指针 */
	dataType data;  /* 存顶点的数据 */
	/* 注意：很多情况下，顶点无数据，此时Data可以不用出现 */
};
using adjList = VNode[maxVertexNum];

/* 图节点的定义 */
using ptrToGNode= struct GNode*;
struct GNode
{
	int Nv;
	int Ne;
	adjList G;
};
using LGrpah = GNode*; /* 以邻接表方式存储图的类型 ListGraph */

LGrpah createGraph(int vertexNum);


void insertEdge(LGrpah graph, edge e);


LGrpah buildGraph();

void DFS_LGraph (LGrpah graph, vertex v);
#endif //MYGRAPH_ADJACENCYLIST_H
