#include <stdio.h>
int main(void)
{
	int valeur;
	puts("***********************************");
	puts("*         -Level00 -       *");
	puts("***********************************");
	printf("Password:", );
	scanf("%d", valeur);
	if (valeur == 5276)
	{
		system("/bin/sh");
		return(0);
	}
	else
	{
		puts("Invalid Password!");
	}
	return(1);
}
