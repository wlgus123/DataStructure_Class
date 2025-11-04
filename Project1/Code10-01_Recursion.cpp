#include "Common.h"

int openBox(int sum)
{
	static int cnt = 0;
	++cnt;
	println("종이 상자를 엽니다.^^ (" + to_string(cnt) + ")");
	
	return sum;
}

int main()
{
	cout << openBox(1) << endl;
}