#include <libc.h>

typedef struct s_msg
{
	char	msg[140];
	char	user[40]; //8c
	int		size_msg; //b4
} t_msg;

int secret_backdoor()
{
	char	str[128];
	fgets(str, 128, stdin);
	return (system(str));
}

void set_msg(t_msg *msg) {
	char	msg2[1024];

	memset(msg2, 0, 1024);
	puts(">: Msg @Unix-Dude");
	printf(">>: ");
	fgets(msg2, 1024, stdin);
	strncpy(msg->msg, msg2, msg->size_msg);
}

void set_username(t_msg *msg) {
	char	buf[128];

	memset(buf, 0, 128);
	puts(">: Enter your username");
	printf(">>: ");
	fgets(buf, 128, stdin);

	for (int i; i <= 40; i++) {
		if (!buf[i])
			break;
		msg->user[i] = buf[i];
	}
	printf(">: Welcome, %s", msg->user);
}

int handle_msg()
{
	t_msg msg;

	memset(msg.user, 0, 40);
	msg.size_msg = 140;
	set_username(&msg);
	set_msg(&msg);
	return (puts(">: Msg sent!"));
}

int main()
{
	puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------");
	handle_msg();
	return (0);
}

/*
b *0x000055555555495b
b *0x00005555555549c3
recuperer rdi    ->       0x7fffffffe0b0
continue
>>enter msg
x/s 0x7fffffffe0b0
*/
