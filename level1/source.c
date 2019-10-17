#include <libc.h>

char name[256];

int verify_user_name()
{
	puts("verifying username....\n");
	return (strcmp(name, "dat_wil"));
}

int verify_user_pass(char *str)
{
	return (strcmp(str, "admin"));
}

int main() {
	char password[68];

	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(name, 256, stdin);
	if (verify_user_name() != 0x0) {
		puts("nope, incorrect username...\n");
		return (1);
	}
	else {
		puts("Enter Password: ");
		fgets(password, 0x64, stdin);
		if ((verify_user_pass(password) != 0x0) && (verify_user_pass(password) == 0x0)) {
			return (0);
		}
		else {
			puts("nope, incorrect password...\n");
			return (1);
		}
	}
}
