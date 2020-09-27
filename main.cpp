#include "adjacencyList.h"
#include <iostream>

bool visited[maxVertexNum];

int main()
{
	for (int i = 0; i < maxVertexNum; ++i)
	{
		visited[i] = false;
	}

	LGrpah graph = buildGraph();
	DFS_LGraph(graph, 1);
// 4 4 1 2 1 1 3 2 2 3 3 2 4 4
}
