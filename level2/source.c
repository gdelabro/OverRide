#include <libc.h>

int main() {
	FILE *fd;
	int lu;
	char password[42];
	char name[100];
	char pass[100];

	fd = fopen("/home/users/level03/.pass", "r");
	if (!fd)
	{
		fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
		return (1);
	}
	else
	{
		lu = fread(password, 1, 41, fd);
		password[strcspn(password, "\x0a")] = 0;
		if (lu != 41)
		{
			fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
			fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
			exit(1);
		}
		else
		{
			fclose(fd);
			puts("===== [ Secure Access System v1.0 ] =====");
			puts("/***************************************\\");
			puts("| You must login to access this system. |");
			puts("\\**************************************/");
			printf("--[ Username: ");
			fgets(name, 100, stdin);
			name[strcspn(name, "\x0a")] = 0;
			printf("--[ Password: ");
			fgets(pass, 100, stdin);
			pass[strcspn(pass, "\x0a")] = 0;
			puts("*****************************************");
			if (!strncmp(password, pass, 41))
			{
				printf("Greetings, %s!\n", name);
				system("/bin/sh");
				return (0);
			}
			else {
				printf(name);
				puts(" does not have access!");
				return (1);
			}
		}
	}
}

