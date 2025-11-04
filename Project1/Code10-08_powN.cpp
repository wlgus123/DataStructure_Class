#include "Common.h"

string tab = "";
int pow(int x, int n)
{
	tab += " ";
	if (n == 0) return 1;
	println(tab + to_string(x) + "*" + to_string(x) + "^(" + to_string(n) + "-1)");
	return x * pow(x, n - 1);
}

int main()
{
	println("2^4");
	println("´ä-->" + to_string(pow(2, 4)));
	return 0;
}