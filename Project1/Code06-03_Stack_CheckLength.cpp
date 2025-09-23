#include "Common.h"

int SIZE = 5;
Array <string> stack = { "커피", "녹차", "꿀물", "콜라", "환타" };
int top = 4;

bool isStackFull()
{
	if (top >= SIZE - 1)
		return true;
	else
		return false;
}

int main()
{
	print("스택이 꽉 찼는지 여부: ");
	println((isStackFull() ? "true" : "false"));	// 0: false, 1: true

	return 0;
}