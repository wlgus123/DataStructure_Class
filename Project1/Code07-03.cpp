#include "Common.h"

int SIZE = 5;
Array <string> queue = { "화사", "솔라", "문별", "휘인", "None" };
int front = -1, rear = 3;

// 큐가 꽉 찼는지 확인하는 함수
bool isQueueFull()
{
	if (rear == SIZE - 1)
		return true;
	return false;
}

void enQueue(string data)
{
	if (isQueueFull())
	{
		println("큐가 꽉 찼습니다.");
		return;
	}
	rear++;
	queue[rear] = data;
}

int main()
{
	print("큐가 꽉 찼는지 여부: ");
	println((isQueueFull() ? "true" : "false"));	// 0: false, 1: true

	printArray(queue);
	enQueue("선미");
	printArray(queue);
	enQueue("재남");

	return 0;
}