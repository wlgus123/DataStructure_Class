#include "Common.h"

int arrSum(Array <int> arr, int n)
{
	if (n < 0) return arr[0];
	return arrSum(arr, n - 1) + arr[n];
}

int main()
{
	Array <int> arr;
	randomInit(0, 255);
	int arrCnt = (dis(gen) + 10) / 10;
	for (int i = 0; i < arrCnt; i++)
	{
		arr.push_back(dis(gen));
	}
	printArray(arr);
	print("배열 합계 -->");
	print(arrSum(arr, len(arr) - 1));

	return 0;
}