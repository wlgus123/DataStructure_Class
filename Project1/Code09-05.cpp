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
int gSize = 6;
Array<string> nameArr = { "춘천", "서울", "속초", "대전", "광주", "부산" };
int 춘천 = 0, 서울 = 1, 속초 = 2, 대전 = 3, 광주 = 4, 부산 = 5;

void printGraph(Graph g)
{
	print(" ");
	for (int v = 0; v < len(g); v++)
		print(nameArr[v] + " ");
	println("");
	for (int row = 0; row < len(g); row++)
	{
		print(nameArr[row] + " ");
		for (int col = 0; col < len(g[row]); col++)
		{
			if (g[row][col] == 0)	// 0은 한 칸 띄어쓰기
				print("0");
			else
				print(g[row][col]);
			print(" ");
		}
		println("");
	}
	println("");
}

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
				if (isInArray(visitedArr, vertex))	// 방문한 적이 있으면 탈락
				{
				}
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
	G1 = initGraph(gSize);
	G1[춘천][서울] = 10; G1[춘천][속초] = 15;
	G1[서울][춘천] = 10; G1[서울][속초] = 40; G1[서울][대전] = 11; G1[서울][광주] = 50;
	G1[속초][춘천] = 15; G1[속초][서울] = 40; G1[속초][대전] = 12;
	G1[대전][서울] = 11; G1[대전][속초] = 12; G1[대전][광주] = 20; G1[대전][부산] = 30;
	G1[광주][서울] = 50; G1[광주][대전] = 20; G1[광주][부산] = 25;
	G1[부산][대전] = 30; G1[부산][광주] = 25;

	println("## 자전거 도로 건설을 위한 전체 연결도 ##\n");
	printGraph(G1);

	Array <Array<int>> edgeArr;
	for (int i = 0; i < gSize; i++)
	{
		for (int k = 0; k < gSize; k++)
		{
			if (G1[i][k] != 0)
				edgeArr.push_back({ G1[i][k], i, k });
		}
	}

	sortArray(edgeArr);		// 정렬
	reverseArray(edgeArr);	// 역순

	Array<Array<int>> newArr;
	for (int i = 0; i < len(edgeArr); i++)
		newArr.push_back(edgeArr[i]);

	int idx = 0;
	int start, end, saveCost;
	bool startYN, endYN;
	while (len(newArr) > gSize - 1)
	{
		start = newArr[idx][1];
		end = newArr[idx][2];
		saveCost = newArr[idx][0];

		G1[start][end] = 0;
		G1[end][start] = 0;


		startYN = findVertex(G1, start);
		endYN = findVertex(G1, end);

		if (startYN && endYN)
		{
			del(newArr, idx);
		}
		else
		{
			G1[start][end] = saveCost;
			G1[end][start] = saveCost;
			idx++;
		}
	}
	println("## 최소 비용의 자전거 도로 연결도 ##\n");
	printGraph(G1);

	
	return 0;
}