#include "Common.h"

Array <string> stack = { "커피", "녹차", "꿀물", "None", "None" };
int top = 2;

int main()
{
	// pop: 데이터 추출
	println("--------스택 상태--------");
	for (int i = len(stack) - 1; i > -1; i--)
		println(stack[i]);

	string data;
	println("------------------------");
	data = stack[top];
	stack[top] = "None";
	top--;
	println("pop: " + data);

	data = stack[top];
	stack[top] = "None";
	top--;
	println("pop: " + data);

	data = stack[top];
	stack[top] = "None";
	top--;
	println("pop: " + data);
	println("------------------------");

	println("--------스택 상태--------");
	for (int i = len(stack) - 1; i > -1; i--)
		println(stack[i]);
}