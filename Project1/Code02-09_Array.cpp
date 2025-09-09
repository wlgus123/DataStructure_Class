#include <iostream>
#include <vector>
#include <algorithm>

#define Array vector
#define print(data) cout << data << " ";
#define println(data) cout << data << endl;
#define printArray(arr)								\
		cout << "[";								\
		for(int i = 0; i < (int)arr.size(); i++)	\
			cout << arr[i] << " ";					\
		cout << "]" << endl;						

#define sortArray(arr) sort(arr.begin(), arr.end())
#define reverseArray(arr) reverse(arr.begin(), arr.end());
#define copyArray(src, target) target.assign(src.begin(), src.end())
#define insertArray(arr, pos, data) arr.insert(arr.begin()+ pos, data)
#define setArray(arr) arr.erase(unique(arr.begin(), arr.end()), arr.end())
#define isInArray(arr, data) find(arr.begin(), arr.end(), data) != arr.end()
#define removeChar(strr, chr) strr.erase(remove(strr.begin(), strr.end(), chr), strr.end())

using namespace std;

int main()
{
	// 배열 선언
	Array <int> arr1 = { 3, 5, 2, 7, 3, 8, 9, 3, 1, 3, 2, 1, 8, 4, 7 };
	Array <int> arr2;

	// 배열 정렬
	println("-----------------Array-----------------");
	sortArray(arr1);
	printArray(arr1);
	println("");
	
	// 배열 거꾸로 정렬
	println("-------------Reverse Array-------------");
	reverseArray(arr1);
	printArray(arr1);
	println("");

	// 배열 복사
	println("---------------Copy Array--------------");
	copyArray(arr1, arr2);
	printArray(arr2);
	println("");

	// 배열에 값 추가
	println("-----------Insert Array Data-----------");
	insertArray(arr1, 2, 8888);
	printArray(arr1);
	println("");

	// 배열에 값이 있는지 구분
	println("------------Find Array Data------------");
	bool yn = isInArray(arr1, 8888);
	println(yn);
	println("");

	// 원하는 값 제거
	println("-----------Remove Array Data-----------");
	string myStr = "Hello CData Structure !";
	removeChar(myStr, 'C');
	println(myStr);
	println("");

	return 0;
}