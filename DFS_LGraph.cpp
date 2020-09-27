//
// Created by xyh on 2020/9/26.
//
#include "adjacencyList.h"


void visit (vertex v)
{
	std::cout << "正在访问顶点" << v << "  ";
}

extern bool visited[maxVertexNum];


void DFS_LGraph (LGrpah graph, vertex v)
{
	ptrToAdjVNode w;

	visit (v);
	visited[v] = true;
	for(w = graph->G[v].firstEdge; w; w=w->next)
		if (!visited[w->adjV])
			DFS_LGraph(graph,w->adjV);
}

