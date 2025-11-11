#include "Common.h"

Array<int> moneyArr = { 7, 5, 11, 6, 9, 80000, 10, 6, 15, 12 };

Array<int> selectionSort(Array<int> arr)
{
	int n = len(arr);
	for (int cycle = 0; cycle < n - 1; cycle++)
	{
		int minIdx = cycle;
		for (int i = cycle + 1; i < n; i++)
		{
			if (arr[minIdx] > arr[i])
				minIdx = i;
		}
		int temp = arr[cycle];
		arr[cycle] = arr[minIdx];
		arr[minIdx] = temp;
	}

	return arr;
}

int main()
{
	print("¿ëµ· Á¤·Ä Àü -->");
	printArray(moneyArr);
	moneyArr = selectionSort(moneyArr);
	print("¿ëµ· Á¤·Ä ÈÄ -->");
	printArray(moneyArr);
	print("¿ëµ· Áß¾Ó°ª -->");
	println(moneyArr[len(moneyArr) / 2]);
	print("¿ëµ· Æò±Õ°ª -->");
	int sum = 0;
	for (int mon : moneyArr)
		sum += mon;
	println(sum / len(moneyArr));
	return 0;
}