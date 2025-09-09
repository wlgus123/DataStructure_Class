#include <iostream>
#include <Windows.h>
#include ".\Common.h"

#define Array vector

bool IsUnique(Array<int> arr, int num)
{
	for (int idx = 0; idx < arr.size(); idx++)
	{
		if (num == arr[idx])
			return false;
	}
	return true;
}

int main()
{
	/*randomInit(1, 100);
	println(cookRandom(gen));*/
	// 로또번호 생성기 하나를 만드시오
	// 형식: [10 5 23 56 23 99]

	int cnt;
	Array<int> roto;

	println("** 로또 번호 생성을 시작합니다. **");
	while (true)
	{
		print("몇 개를 뽑을까요?(1 ~ 50) ");
		cin >> cnt;
		if (cnt > 0 && cnt <= 50)
			break;

		system("cls");
		print("1에서 50개 까지만 생성이 가능합니다.");
		Sleep(700);
		system("cls");
	}

	print("[");
	randomInit(1, 45);
	for (int i = 0; i < cnt; i++)
	{
		int tempNum;
		tempNum = dis(gen);

		// 로또 번호가 중복인지 체크
		if (IsUnique(roto, tempNum))
		{
			roto.push_back(tempNum);
		}
		else
		{
			--i;
			continue;
		}

		print(dis(gen));
	}
	println("]");

	return 0;
}