#include <libc.h>
#include <sys/ptrace.h>

int auth(char *arg0, int serial) {
	int i;
	int arg0len;
	arg0[strcspn(arg0, "\n")] = 0x0;
	arg0len = strnlen(arg0, 32);
	if (arg0len <= 5)
		return (1);
	if (ptrace(0, 0, 1, NULL) == -1)
	{
		puts("[32m.---------------------------.");
		puts("[31m| !! TAMPERING DETECTED !!  |");
		puts("[32m'---------------------------'");
		return (1);
	}
	int var_10 = arg0[3] ^ 4919 + 6221293;
	i = 0;
	do {
		if (i >= arg0len)
		{
			if (serial != var_10)
				return (1);
			else
				return (0);
		}
		if (arg0[i] <= 0x1f) //not writeable
			return (1);
		int ecx = arg0[i] ^ var_10;
		var_10 = var_10 + (ecx - ((ecx - ((ecx * 0x88233b2b) >> 0x1)) + ((ecx * 0x88233b2b) >> 0xa)) * 0x539);
		i++;
	} while (1);
}

int main() {
	char	login[100];
	int		serial;
	puts("***********************************");
	puts("*\t\tlevel06\t\t  *");
	puts("***********************************");
	printf("-> Enter Login: ");
	fgets(login, 32, stdin);
	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	scanf("%u", &serial);
	if (!auth(login, serial))
	{
		puts("Authenticated!");
		system("/bin/sh");
		return (0);
	}
	else
		return (1);
}



/*
 * 8048a60 %u
 * 8048a68 [32m.---------------------------.
 * 8048a8c [31m| !! TAMPERING DETECTED !!  |
 * 8048ab0 [32m'---------------------------'
 * 8048ad4 ***********************************
 * 8048af8 *		level06		  *
 * 8048b08 -> Enter Login:
 * 8048b1c ***** NEW ACCOUNT DETECTED ********
 * 8048b40 -> Enter Serial:
 * 8048b52 Authenticated!
 * 8048b61 /bin/sh
 */


/*
b *0x080487ba
b *0x08048866
Enter Login: guilou
Enter serial: 1
set $eax=1
continue
x/d $ebp-16   ->      our serial number for this login
serial: 6232801
*/
