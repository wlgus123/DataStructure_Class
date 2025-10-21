#include "Common.h"

// <그래프>
// 여러 노드가 서로 연결된 자료구조
// 그래프를 활용한 예:
// 지하철 노선도(부산), KTX 노선도

// <그래프 종류>
// 무방향 그래프: 간선에 방향성이 없는 그래프
// 방향 그래프: 화살표로 간선 방향 표기, 그래프의 정점 집합이 무방향 그래프와 동일
// 가중치 그래프: 간선마다 가중치가 다르게 부여된 그래프

// <그래프의 깊이 우선 탐색>
// - 그래프의 모든 정점을 한 번씩 방문하는 것을 그래프 순회(Graph Traversal)
// - 대표적인 그래프 순회 방식: 깊이 우선 탐색, 너비 우선 탐색

// <그래프의 인접 행렬 표현>
// - 무방향 그래프의 인접 행렬
// - 방향 그래프의 인접 행렬


typedef Array<Array<int>> Graph;
Graph initGraph(int size)
{
	Graph G;
	Array <int> tempArr;
	for (int i = 0; i < size; i++)
	{
		tempArr.clear();
		for (int k = 0; k < size; k++)
		{
			tempArr.push_back(0);
		}
		G.push_back(tempArr);
	}

	return G;
}

// 전역 변수
Graph G1, G3;

int main()
{
	G1 = initGraph(4);
	G1[0][1] = 1; G1[0][2] = 1; G1[0][3] = 1;
	G1[1][0] = 1; G1[1][2] = 1;
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

	G3 = initGraph(4);
	G3[0][1] = 1; G3[0][2] = 1;
	G3[3][0] = 1; G3[3][2] = 1;


	println("## G3 방향 그래프 ##");
	G3[0][1] = 1; G3[0][2] = 1;
	G3[3][0] = 1; G3[3][2] = 1;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			print(G3[row][col]);
		}
		println("");
	}

	return 0;
}