#include "Common.h"

bool palindrome(string p_str)
{
	if (len(p_str) <= 1) return true;

	int p_size = len(p_str);
	if (p_str[0] != p_str[p_size - 1]) return false;

	return palindrome(p_str.substr(1, p_size - 2));
}

int main()
{
	Array <string> strArr = { "reaver", "kayak", "Borrow or rob", "Race Car", "Was it a cat I saw", "love love" };

	for (int i = 0; i < len(strArr); i++)
	{
		string testStr = strArr[i];
		print(testStr + "-->");
		removeChar(testStr, ' ');
		for (int k = 0; k < len(testStr); k++)
			testStr[k] = toupper(testStr[k]);
		if (palindrome(testStr))
		{
			println("O");
		}
		else
		{
			println("X");
		}
	}
	return 0;
}