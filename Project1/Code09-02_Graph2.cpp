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
// 무방향 그래프
Graph G1;
Array<string> nameArr = { "문별", "솔라", "휘인", "쯔위" "선미", "화사" };
int 문별 = 0, 솔라 = 1, 휘인 = 2, 쯔위 = 3, 선미 = 4, 화사 = 5;

void printGraph(Graph g)
{
	print(" ");
	for (int v = 0; v < len(g); v++)
		print(nameArr[v]);
	println("");

	for (int row = 0; row < len(g); row++)
	{
		print(nameArr[row] + " ");
		for (int col = 0; col < len(g[row]); col++)
		{
			print(g[row][col]);
			print(" ");
		}
		println("");
	}
	println("");
}

int main()
{
	int gSize = 6;
	G1 = initGraph(gSize);
	G1[문별][솔라] = 1; G1[문별][휘인] = 1;
	G1[솔라][문별] = 1; G1[솔라][쯔위] = 1;
	G1[휘인][문별] = 1; G1[휘인][쯔위] = 1;
	G1[쯔위][솔라] = 1; G1[쯔위][휘인] = 1; G1[쯔위][선미] = 1; G1[쯔위][화사] = 1;
	G1[선미][쯔위] = 1; G1[선미][화사] = 1;
	G1[화사][쯔위] = 1; G1[화사][선미] = 1;

	println("## G1 무방향 그래프 ##\n");
	printGraph(G1);

	return 0;
}