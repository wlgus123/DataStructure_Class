#include "Common.h"

typedef Array <Array<int>> Graph;
Graph initGraph(int size)
{
	Graph G;
	Array <int> tempArr;
	for (int i = 0; i < size; i++)
	{
		tempArr.clear();
		for (int k = 0; k < size; k++)
			tempArr.push_back(0);
		G.push_back(tempArr);
	}
	return G;
}

int gSize = 6;
Graph G1;
Array<string> nameArr = { "문별", "솔라", "휘인", "쯔위", "선미", "화사" };
int 문별 = 0, 솔라 = 1, 휘인 = 2, 쯔위 = 3, 선미 = 4, 화사 = 5;

bool findVertex(Graph g, int findVtx)
{
	Array<int> stack;
	Array<int> visitedArr;

	int current = 0;		// 시작 정점
	stack.push_back(current);
	visitedArr.push_back(current);

	while (len(stack) != 0)
	{
		int next = -1;
		for (int vertex = 0; vertex < gSize; vertex++)
		{
			if (g[current][vertex] != 0)
			{
				if(isInArray(visitedArr, vertex))	// 방문한 적이 있으면 탈락
				{}
				else
				{
					next = vertex;
					break;
				}
			}
		}
		// 다음에 방문할 정점이 있는 경우
		if (next != -1)
		{
			current = next;
			stack.push_back(current);
			visitedArr.push_back(current);
		}
		// 다음에 방문할 정점이 없는 경우
		else
		{
			current = stack[len(stack) - 1];
			stack.pop_back();
		}
	}
	
	if (isInArray(visitedArr, findVtx))
		return true;
	else
		return false;
}

int main()
{
	Graph G1 = initGraph(gSize);
	G1[문별][솔라] = 1; G1[문별][휘인] = 1;
	G1[솔라][문별] = 1; G1[솔라][쯔위] = 1;
	G1[휘인][문별] = 1; G1[휘인][쯔위] = 1;
	G1[쯔위][솔라] = 1; G1[쯔위][휘인] = 1; G1[쯔위][선미] = 1;
	G1[선미][쯔위] = 1;

	for (int name = 0; name < gSize; name++)
	{
		if (findVertex(G1, name))
		{
			println(nameArr[name] + " 연락이 됨");
		}
		else
		{
			println(nameArr[name] + " 연락이 안 됨");
		}
	}
	
	return 0;
}