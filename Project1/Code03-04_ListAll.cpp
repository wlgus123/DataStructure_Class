#include "Common.h"

using namespace std;

Array <string> kt = { "지현", "서영", "승준", "진수", "윤찬", "한빛", "윤성", "성준", "재범", "재승", "성래", "성환", "창민", "현우", "찬혁" };
int sel_num = -1;	// 숫자 선택 변수

// 데이터 출력 함수
void print_data()
{
	println("\n<현재 데이터>");
	printArray(kt);
	println("");
}

// 데이터 삽입 함수
bool insert_data(int pos, string data)
{
	if ((pos < 0) || (pos > len(kt)))
	{
		print("데이터를 삽입할 범위를 벗어났습니다.");
		return false;
	}

	kt.push_back("None");
	int kLen = len(kt);

	for (int i = kLen - 1; i > pos; i--)
	{
		kt[i] = kt[i - 1];
		kt[i - 1] = "None";
	}

	kt[pos] = data;

	return true;
}

// 데이터 삭제 함수
bool delete_data(int pos)
{
	if ((pos < 0) || (pos > len(kt)))
	{
		print("데이터를 삽입할 범위를 벗어났습니다.");
		return false;
	}

	int kLen = len(kt);
	kt[pos] = "None";

	for (int i = pos + 1; i < kLen; i++)
	{
		kt[i - 1] = kt[i];
		kt[i] = "None";
	}

	del(kt, kLen - 1);

	return true;
}

// 데이터 추가 함수
bool add_data(string data)
{
	kt.push_back(data);

	return true;
}

// 데이터 초기화 함수
void reset_data(int* pos, string* data)
{
	*pos = -1;
	*data = "";
}

int main()
{
	string data;
	int pos;

	while (sel_num != 0)
	{
		input(sel_num, "\n옵션을 선택해주세요(1: 추가, 2: 삽입, 3: 삭제, 4: 조회, 0: 종료): ");

		switch (sel_num)
		{
		case 1:
			input(data, "\n추가할 데이터: ");
			// 정상적으로 추가되었을 때
			if (add_data(data))
			{
				println("추가되었습니다.");
				print_data();
			}
			else println("에러가 발생했습니다.");
			break;

		case 2:
			print_data();	// 데이터 출력
			input(pos, "삽입할 위치를 선택해주세요: ");
			input(data, "삽입할 데이터를 입력해주세요: ");

			// 정상적으로 삽입되었을 때
			if (insert_data(pos, data))
			{
				println("삽입되었습니다.");
				print_data();
			}
			else println("에러가 발생했습니다.");

			break;

		case 3:
			print_data();
			input(pos, "삭제할 위치를 선택해주세요: ");

			// 정상적으로 삭제되었을 때
			if (delete_data(pos))
			{
				println("삭제되었습니다.");
				print_data();
			}
			else println("에러가 발생했습니다.");

			break;

		case 4:
			printArray(kt);
			break;
		}

		// 데이터 초기화
		reset_data(&pos, &data);
	}

	return 0;
}