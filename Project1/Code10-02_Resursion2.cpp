#include "Common.h"

int boxCnt = 10;

void openBox()
{
	println("종이 상자를 엽니다.^^");
	--boxCnt;
	if (boxCnt == 0)
	{
		println("** 반지를 넣고 반환합니다. **");
		return;
	}
	openBox();
	println("종이 상자를 닫습니다.^^");
}

int main()
{
	openBox();
	return 0;
}