#include "Common.h"

Array <string> stack = { "None", "None", "None", "None", "None" };
int top = -1;

int main()
{
	// push: 데이터 삽입
	top++;
	stack[top] = "커피";
	top++;
	stack[top] = "녹차";
	top++;
	stack[top] = "꿀물";
	// top 카운트가 되면서 스택의 위치가 이동함
	
	println("-------스택 상태-------");
	for (int i = len(stack) - 1; i > -1; i--)
	{
		println(stack[i]);
	}
}