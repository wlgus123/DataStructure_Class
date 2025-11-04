#include <Windows.h>
#include "Common.h"

void countDown(int n)
{
	if (n == 0)
		println("น฿ป็!!");
	else
	{
		println(n);
		Sleep(1000);
		countDown(n - 1);
	}
}

int main()
{
	countDown(5);
	return 0;
}