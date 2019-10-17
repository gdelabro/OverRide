#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int decrypt(int c)
{
	system("/bin/sh");
	return (0);
}

int test(int a, int b)
{
	unsigned int c;
	c = b - a;
	if (c <= 21)
	{
		/*jump to *((c*4) + 0x80489f0);*/
		if (c == 1)
			return (decrypt(c));
		if (c == 2)
		return (decrypt(c));
		if (c == 3)
		return (decrypt(c));
		if (c == 4)
		return (decrypt(c));
		if (c == 5)
		return (decrypt(c));
		if (c == 6)
		return (decrypt(c));
		if (c == 7)
		return (decrypt(c));
		if (c == 8)
		return (decrypt(c));
		if (c == 9)
		return (decrypt(c));
		if (c == 10)
		return (decrypt(c));
		if (c == 11)
		return (decrypt(c));
		if (c == 12)
		return (decrypt(c));
		if (c == 13)
		return (decrypt(c));
		if (c == 14)
		return (decrypt(c));
	}
	return (decrypt(rand()));
}

int main()
{
	int a;

	srand(time(NULL));
	puts("***********************************");
	puts("*		level3		**");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &a);
	test(a, 322424845);
	return(0);
}
