#include "Common.h"

Array<int> dataArr;
const int randCnt = 100;

Array<int> selectionSort(Array<int> arr)
{
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j - 1] < arr[j])
			{
				int tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	return arr;
}

int main()
{
	// 랜덤 함수 초기화
	randomInit(0, 500);

	// 랜덤 정수 삽입
	for (int i = 0; i < randCnt; i++)
	{
		dataArr.push_back(dis(gen));
	}

	println("=================정렬 전=================");
	printArray(dataArr);

	println("=================정렬 후=================");
	printArray(selectionSort(dataArr));

}