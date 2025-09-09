#include <iostream>
#include ".\Common.h"

#define Array vector

int main()
{
	/*randomInit(1, 100);
	println(cookRandom(gen));*/
	// 로또번호 생성기 하나를 만드시오
	// 형식: [10 5 23 56 23 99]

	Array<int> roto;

	print("[");
	for(int i = 0; i < 6; i++)
	{
		randomInit(1, 45);
		print(cookRandom(gen));
	}
	println("]");

	return 0;
}