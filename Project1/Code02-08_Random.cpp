#include <iostream>
#include <random>

#define print(data) cout << data << " ";
#define println(data) cout << data << endl;
#define randomInit(start, end)	\
		random_device rd;		\
		mt19937 gen(rd());		\
		uniform_int_distribution<int> cookRandom(start, end)

using namespace std;

void main()
{
	randomInit(0, 9999);

	for (int i = 0; i < 5; i++)
	{
		print(cookRandom);
	}
}