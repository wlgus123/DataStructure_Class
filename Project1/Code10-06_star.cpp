#include "Common.h"

void printStar(int n)
{
	if (n > 0)
	{
		printStar(n - 1);
		for (int i = 0; i < n; i++)
			print("*");
		println("");
	}
}

int main()
{
	printStar(5);
	return 0;
}