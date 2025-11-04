#include "Common.h"

void gugu(int dan, int n)
{
	println(to_string(dan) + " x " + to_string(n) + " = " + to_string(dan * n));
	if (n < 9)
		gugu(dan, n + 1);
}

int main()
{
	for (int dan = 2; dan < 10; dan++)
	{
		println("## " + to_string(dan) + "´Ü ##");
		gugu(dan, 1);
	}

	return 0;
}