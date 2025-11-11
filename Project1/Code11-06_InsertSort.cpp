#include "Common.h"

Array<int> dataArr = { 188, 162, 168, 120, 16 , 57, 68, 94, 165, 228, 133, 85, 12, 11, 95 };

Array<int> insertionSort(Array<int> arr)
{
	int n = len(arr);
	for (int end = 1; end < n; end++)
	{
		for (int cur = end; cur > 0; cur--)
		{
			if (arr[cur - 1] > arr[cur])
			{
				int tmp = arr[cur - 1];
				arr[cur - 1] = arr[cur];
				arr[cur] = tmp;
			}
		}
	}

	return arr;
}

int main()
{
	print("정렬 전: ");
	printArray(dataArr);
	dataArr = insertionSort(dataArr);
	print("정렬 후: ");
	printArray(dataArr);
	
	return 0;
}