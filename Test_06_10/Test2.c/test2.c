#include <stdio.h>

int main()
{
	int c = 7;
	float x = 2.5, y = 4.7;
	printf("%d\n", x + c % 3 * (int)(x + y) % 2 / 4);
	system("pause");
	return 0;
}