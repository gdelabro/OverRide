#include <stdio.h>
#include <libc.h>
#include <stdlib.h>
#include <time.h>

int decrypt(int c)
{
	char str[17] = "Q}|u`sfg~sf{}|a3";
	int len = strlen(str);
	int i = 0;

	while (i < len)
	{
		char d = str[i];
		char a = c;
		d ^= a;
		str[i] = d;
		i++;
	}
	if (!strncmp(str, "Congratulations!", 17))
		system("/bin/sh");
	else
		puts("Invalid Password");
	return (0);
}

int test(int a, int b)
{
	unsigned int c;
	c = b - a;
	if (c <= 21)
	{
		if (c == 1)
			return (decrypt(c));
		else if (c == 2)
			return (decrypt(c));
		else if (c == 3)
			return (decrypt(c));
		else if (c == 4)
			return (decrypt(c));
		else if (c == 5)
			return (decrypt(c));
		else if (c == 6)
			return (decrypt(c));
		else if (c == 7)
			return (decrypt(c));
		else if (c == 8)
			return (decrypt(c));
		else if (c == 9)
			return (decrypt(c));
		else if (c == 10)
			return (decrypt(c));
		else if (c == 11)
			return (decrypt(c));
		else if (c == 12)
			return (decrypt(c));
		else if (c == 13)
			return (decrypt(c));
		else if (c == 14)
			return (decrypt(c));
		else
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
