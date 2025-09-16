#include "Common.h"

using namespace std;

Array <string> kt = { "다현", "정연", "쯔위", "사나", "지효" };

void delete_data(int pos)
{
	if ((pos < 0) || (pos > len(kt)))
	{
		print("데이터를 삽입할 범위를 벗어났습니다.");
		return;
	}

	int kLen = len(kt);
	kt[pos] = "None";

	for (int i = pos + 1; i < kLen; i++)
	{
		kt[i - 1] = kt[i];
		kt[i] = "None";
	}

	del(kt, kLen - 1);
}

int main()
{
	delete_data(1);
	printArray(kt);
	delete_data(3);
	printArray(kt);

	return 0;
}