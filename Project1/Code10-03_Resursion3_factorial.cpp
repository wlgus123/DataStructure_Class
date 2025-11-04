#include "Common.h"

int factorial(int num)
{
	int retVal;
	if (num <= 1)
	{
		println("1 반환");
		return 1;
	}
	println(to_string(num) + " * " + to_string(num - 1) + "! 호출");
	retVal = factorial(num - 1);

	println(to_string(num) + " * " + to_string(num - 1) + "!(=" + to_string(retVal) + ") 반환");
	return num * retVal;
}

int main()
{
	println("\n5! = " + to_string(factorial(5)));
}