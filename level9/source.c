#include <libc.h>
#include <nop>

int secret_backdoor()
{
	char	str[0x81]
	fgets(str, 0x80, stdin);
	return (system(str));
}

int set_msg(char *arg0) {
	asm { rep stosq  qword [rdi], rax };
	puts(">: Msg @Unix-Dude");
	printf(0xbdf);
	fgets(&var_400, 0x400, **qword_201fb8);
	return (strncpy(arg0, &var_400, *(arg0 + 0xb4)));
}

int set_username(int arg0) {
	var_98 = arg0;
	asm { rep stosq  qword [rdi], rax };
	puts(">: Enter your username");
	printf(0xbdf);
	fgets(&var_90, 0x80, **qword_201fb8);
	for (var_4 = 0x0; var_4 <= 0x28; var_4 = var_4 + 0x1) {
		if ((*(int8_t *)(rbp + (sign_extend_32(var_4) - 0x90)) & 0xff) == 0x0) {
			break;
		}
		*(int8_t *)(var_98 + sign_extend_32(var_4) + 0x8c) = *(int8_t *)(rbp + (sign_extend_32(var_4) - 0x90)) & 0xff;
	}
	rax = printf(">: Welcome, %s", var_98 + 0x8c);
	return rax;
}

int handle_msg()
{
	*(&var_C0 + 0x8c) = 0x0;
	*(&var_C0 + 0x94) = 0x0;
	*(&var_C0 + 0x9c) = 0x0;
	*(&var_C0 + 0xa4) = 0x0;
	*(&var_C0 + 0xac) = 0x0;
	set_username(&var_C0);
	set_msg(&var_C0);
	return (puts(">: Msg sent!"));
}

int main()
{
	puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------");
	handle_msg();
	return (0);
}
