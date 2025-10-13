#include "Common.h"

int SIZE = 5;
Array <string> stack = { "커피", "녹차", "꿀물", "콜라", "None" };
int top = 3;

bool isStackFull()
{
	if (top >= SIZE - 1)
		return true;
	else
		return false;
}

void pushInventory(string data)
{
	if (isStackFull())
	{
		println("스택이 꽉 찼습니다.");
		return;
	}
	top++;
	stack[top] = data;
}

int main()
{
	printArray(stack);
	pushInventory("환타");
	printArray(stack);
	pushInventory("게토레이");

	//print("스택이 꽉 찼는지 여부: ");
	//println((isStackFull() ? "true" : "false"));	// 0: false, 1: true

	return 0;
}