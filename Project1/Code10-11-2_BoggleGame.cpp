#include "Common.h"

#define MOVE_DATA 8
#define BOARD_H 5		// 보드판 높이
#define BOARD_W 5		// 보드판 너비

enum E_Dir
{
	LEFT_UP = 0,
	LEFT,
	LEFT_DOWN,
	RIGHT_UP,
	RIGHT,
	RIGHT_DOWN,
	UP,
	DOWN,
};

// 상하좌우/대각선 이동 
const int dx[MOVE_DATA] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[MOVE_DATA] = { -1, 0, 1, -1, 0, 1, -1, 1 };

// 보드판 데이터
char board[BOARD_H][BOARD_W] =
{ {'u', 'r', 'l', 'p', 'm'},
{'x', 'p', 'r', 'e', 't'},
{'g', 'i', 'a', 'e', 't'},
{'x', 't', 'n', 'z', 'y'},
{'x', 'o', 'q', 'r', 's'} };

void FindWord(string p_str, string p_findWord)
{
	static int posX = 0;
	static int posY = 0;
	static int findCnt = 0;
	for (int i = 0; i < MOVE_DATA; i++)
	{
		if (board[dx[i]][dy[i]])
		{

		}
	}
}

int main()
{

	string str = "SDLFKJSDLDKFJKOREAITDFDKJFFLF";	// 랜덤 문자열
	FindWord(str, "KOREAIT");
}