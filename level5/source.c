#include <libc.h>

int main ()
{
	char str[144];
	unsigned int a = 0;

	fgets(str, 100, stdin);
	while (strlen(str) > a )
		do
		{
			if(str[a] > '@' ) // @ = 0x40, A = 0x41
			{
				if (str[a] <= 'Z')
				{
					str[a] += 32;
				}
			}
			a++;
		} while (1);
		printf(str);
		exit(0);
}
