#include "Common.h"

Array<int> testArr = { 55, 88, 33, 77 };

int findMinIdx(Array<int> arr)
{
	int minIdx = 0;
	for (int i = 1; i < len(arr); i++)
	{
		if (arr[minIdx] > arr[i])
		{
			minIdx = i;
		}
	}

	return minIdx;
}

int main()
{
	int minPos = findMinIdx(testArr);
	print("ÃÖ¼Ú°ª -->");
	println(testArr[minPos]);
	
	return 0;
}