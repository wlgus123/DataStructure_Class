#include "Common.h"

int fibo(int n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else return fibo(n - 1) + fibo(n - 2);
}

int main()
{
	print("피보나치 수 --> 0 1");
	for (int i = 2; i < 20; i++)
		print(fibo(i));
	return 0;
}