#include "Common.h"

Array <string> queue = { "None", "None", "None", "None", "None" };
int front = -1, rear = -1;

int main()
{
	rear++;
	queue[rear] = "화사";
	rear++;
	queue[rear] = "솔라";
	rear++;
	queue[rear] = "문별";

	println("------- 큐 상태 -------");
	print("[출구] <-- ");
	for (int i = 0; i < len(queue); i++)
		print(queue[i]);

	println("<-- 입구");

	return 0;
}