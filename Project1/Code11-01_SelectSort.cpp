#include "Common.h"

Array<int> before = { 188, 162, 168, 120, 16 , 57, 68, 94, 165, 228, 133, 85, 12, 11, 95 };
Array<int> after;

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
	print("정렬 전 -->");
	printArray(before);
	int arrSize = len(before);

	for (int i = 0; i < arrSize; i++)
	{
		int minPos = findMinIdx(before);
		after.push_back(before[minPos]);
		del(before, minPos);
	}

	print("정렬 후 -->");
	printArray(after);

	return 0;
}