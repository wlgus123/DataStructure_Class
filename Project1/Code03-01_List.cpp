#include "Common.h"

using namespace std;

Array <string> katalk;

void add_data(string data)
{
	katalk.push_back("None");
	int kLen = len(katalk);
	katalk[kLen - 1] = data;
}

int main()
{
    add_data("ÁöÇö");
    add_data("Áø¼ö");
    add_data("¼­¿µ");
    add_data("À±Âù");
    add_data("ÇÑºû");
    add_data("À±¼º");
    add_data("¼ºÁØ");
    add_data("Àç¹ü");
    add_data("Àç½Â");
    add_data("¼º·¡");
    add_data("¼ºÈ¯");
    add_data("½ÂÁØ");
    add_data("Çö¿ì");
    add_data("ÂùÇõ");

    printArray(katalk);

	return 0;
}