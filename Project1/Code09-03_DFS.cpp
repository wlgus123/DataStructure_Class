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

Graph G1;
Array<int> stack;
Array<int> visitedArr;

int main()
{
	Graph G1 = initGraph(4);
	G1[0][2] = 1; G1[0][3] = 1;
	G1[1][2] = 1;
	G1[2][0] = 1; G1[2][1] = 1; G1[2][3] = 1;
	G1[3][0] = 1; G1[3][2] = 1;

	println("## G1 무방향 그래프 ##");
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			print(G1[row][col]);
		}
		println("");
	}

	int current = 0;
	stack.push_back(current);
	visitedArr.push_back(current);

	while (len(stack) != 0)
	{
		int next = -1;
		for (int vertex = 0; vertex < 4; vertex++)
		{
			if (G1[current][vertex] == 1)
			{
				// 방문한 적이 있으면 탈락
				if(isInArray(visitedArr, vertex))
				{ }
				// 방문한 적이 없으면 다음 정점으로 지정
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

	print("방문 순서-->");
	for (int i = 0; i < len(visitedArr); i++)
		print((char)('A' + visitedArr[i]));

	return 0;
}