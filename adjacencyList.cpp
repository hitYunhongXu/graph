//
// Created by xyh on 2020/9/27.
//
#include "adjacencyList.h"

LGrpah createGraph(int vertexNum)
{
	/* 初始化一个有vertexNum个顶点但没有边的图 */
	vertex v;
	LGrpah graph;
	graph = new GNode; /* 建立图 */
	graph->Nv = vertexNum;
	graph->Ne = 0;
	/* 初始化邻接表头指针 */
	/* 注意： 这里默认顶点编号从0开始，到(graph->Nv - 1 )*/
	for (v = 0; v<graph->Nv; v++)
		graph->G[v].firstEdge = nullptr;
	return graph;
}

void insertEdge(LGrpah graph, edge e)
{
	ptrToAdjVNode newNode;
	/* 插入边<v1, v2> */
	/* 为v2建立新的邻接点 */
	newNode = new adjVNode;
	newNode->adjV = e->v2;
	newNode->weight = e->weight;
	/* 将v2插入v1的表头 */
	newNode->next = graph->G[e->v1].firstEdge;
	graph->G[e->v1].firstEdge = newNode;
	/* 若是无向图，还要插入边 <V2, V1> */
	/* 为V1建立新的邻接点 */
	newNode = new adjVNode;
	newNode->adjV = e->v2;
	newNode->adjV = e->v1;
	newNode->weight = e->weight;
	/* 将V1插入V2的表头 */
	newNode->next= graph->G[e->v2].firstEdge;
	graph->G[e->v2].firstEdge = newNode;
}

LGrpah buildGraph()
{
	LGrpah graph;
	edge e;
	vertex v;
	int Nv, i;

	std::cin >> Nv; /* 读入顶点个数 */
	graph = createGraph(Nv);    /* 初始化有Nv个顶点但没有边的图 */

	std::cin >>graph->Ne;
	if (graph->Ne != 0)
	{
		e = new ENode;
		for (i = 0; i<graph->Ne; i++)
		{
			std::cin >> e->v1 >> e->v2 >> e->weight;
			insertEdge(graph, e);
		}
	}
	/* 如果顶点有数据的话 */
//	for (v = 0; v<graph->Nv; v++)
//		std::cin >> graph->G->data;
	return graph;
}
