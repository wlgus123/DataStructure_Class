#include "Common.h"

int SIZE = 5;
Array<string> queue = { "화사", "None", "None", "None", "None" };
int front = -1, rear = 0;

// 큐가 비었는지 확인하는 함수
bool isQueueEmpty()
{
	if (front == rear)
		return true;
	return false;
}

string deQueue()
{
	if(isQueueEmpty())
	{
		println("큐가 비었습니다.");
		return "None";
	}
	front++;
	string data = queue[front];
	queue[front] = "None";
	return data;
}

int main()
{
	string retData;
	printArray(queue);
	retData = deQueue();
	println("추출한 데이터-->" + retData);	// 추출한 데이터 불러오기
	printArray(queue);
	retData = deQueue();

	return 0;
}