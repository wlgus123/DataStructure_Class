#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define dataout(data) cout << data << " "
#define println(data) cout << data << endl

#define Array vector
#define len(arr) (int)arr.size()
#define del(arr, pos) arr.erase(arr.begin() + pos)

typedef struct Data
{
	int grade;
	int ID;
	string name;
} Data;

#define initData(data, grade, ID, name) data = {grade, ID, name}

Array<Array<int>> emptyArray2(int row, int col)
{
	Array<Array<int>> arr2;
	Array<int> tmp;
	for (int i = 0; i < row; i++)
	{
		tmp.clear();
		for (int j = 0; j < col; j++)
		{
			tmp.push_back(0);
		}
		arr2.push_back(tmp);
	}
	return arr2;
}

#define printArray2(arr2)									\
	cout << "[";											\
	for(int i = 0; i < (int)arr2.size(); i++) {				\
		cout << "{ ";										\
		for(int j = 0; j < (int)arr2[i].size() - 1; j++)	\
			cout << arr2[i][j] << ", ";						\
		cout << arr2[i][arr2[0].size() - 1] << " }";		\
		if(i < (int)arr2.size() - 1)						\
			cout << ", ";									\
	}														\
	cout << "]" << endl

int main()
{
	/*string strname;
	dataout("이름 입력:");
	cin >> strname;
	cout << endl << "안녕 " << strname << "." << endl;

	Data data[5];
	initData(data[0], 2, 132, "ff");
	cout << data[0].ID << ": " << data[0].grade << "학년 " << data[0].name << endl;

	string str1 = "IT";
	const char* char1 = "자료구조";

	println(str1);
	println(char1);

	string str2 = char1;
	println(str2);

	const char* char2 = str1.c_str();	// string -> char*
	println(char2);

	println(str1.size());
	println(((string)char1).size());

	str1 = "100";
	char1 = "200";
	println(str1 + char1);

	int value = stoi(str1) + stoi(char1);
	println("합계: " + to_string(value));*/

	// vector
	/*vector<int> arrayint;
	arrayint.push_back(10);
	arrayint.push_back(20);
	arrayint.push_back(30);
	arrayint.push_back(50);
	arrayint.push_back(70);
	//arrayint.pop_back();	// 최근 값부터 제거
	arrayint.erase(arrayint.begin() + 2);	// 2번째 인덱스 제거

	cout << "arrayint 값들" << endl;
	for (int i = 0; i < arrayint.size(); i++)
	{
		cout << arrayint[i] << " ";
	}
	cout << endl;*/

	// Vector2
	/*
	int selIdx;		// 메뉴 선택
	int delIdx;		// 삭제할 인덱스 선택
	Array<int> arr;

	cout << "<MENU>" << endl;
	cout << "------------------" << endl;
	cout << "1. 추가" << endl;
	cout << "2. 조회" << endl;
	cout << "3. 삭제" << endl;
	cout << "------------------" << endl;
	cout << "입력: ";

	cin >> selIdx;

	switch (selIdx)
	{
	case 1:
		int addCnt;
		int tempData;
		cout << "추가할 데이터 갯수를 입력하세요: ";
		cin >> addCnt;
		for(int idx = 0; idx < addCnt; idx++)
		{
			cout << idx + 1 << "번째 데이터: ";
			cin >> tempData;
			arr.push_back(tempData);
		}
		cout << "추가되었습니다." << endl;
		break;
	}

	arr.push_back(10);
	arr.push_back(60);
	arr.push_back(50);
	arr.push_back(80);
	cout << "arr length: " << len(arr) << endl;

	for (int i = 0; i < len(arr); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;

	cout << "삭제할 인덱스 입력: ";
	cin >> delIdx;

	del(arr, delIdx);

	cout << endl << "<삭제 후 리스트>" << endl;

	for (int i = 0; i < len(arr); i++)
	{
		cout << "[" << i << "] " << arr[i] << " ";
	}
	cout << endl;
	*/

	Array<Array<string>> grade = { {"수학", "90"}, {"영어", "70"}, {"과학", "88"} };
	grade.push_back({ "역사", "75" });
	printArray2(grade);

	Array<Array<int>> emptyArr = emptyArray2(3, 4);
	printArray2(emptyArr);

		return 0;
}