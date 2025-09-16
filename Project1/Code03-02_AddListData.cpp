#include "Common.h"

using namespace std;

Array <string> kt = { "다현", "정연", "쯔위", "사나", "지효" };

void insert_data(int pos, string data)
{
	if ((pos < 0) || (pos > len(kt)))
	{
		print("데이터를 삽입할 범위를 벗어났습니다.");
		return;
	}

	kt.push_back("None");
	int kLen = len(kt);

	for (int i = kLen - 1; i > pos; i--)
	{
		kt[i] = kt[i - 1];
		kt[i - 1] = "None";
	}

	kt[pos] = data;
}

int main()
{
	insert_data(2, "솔라");
	printArray(kt);
	insert_data(6, "문별");
	printArray(kt);
	return 0;
}