#include <libc.h>

int get_unum()
{
	int nb;
	fflush(stdout);
	scanf("%u", &nb);
	clear_stdin();
	return (nb);
}

int store_number(int *addr) {
	printf(" Number: ");
	int nb = get_unum(); //-0x10
	printf(" Index: ");
	int index = get_unum();//-0xc
	int ecx = index;
	int edx = 0xaaaaaaab;
	int eax = index;
	eax *= 0xaaaaaaab;
	edx = (ecx * 0xaaaaaaab) >> 32;
	edx >>= 1;
	eax = edx * 3;
	edx = ecx;
	eax -= edx;
	if ((index != ((index * 0xaaaaaaab) >> 0x1)*3)
		&& (nb >> 0x18 != 0xb7))
	{
		addr[index] = nb;
		return (0);
	}
	else {
		puts(" *** ERROR! ***");
		puts("   This index is reserved for wil!");
		puts(" *** ERROR! ***");
		return (1);
	}
}

int read_number(unsigned int *addr) {
	printf(" Index: ");
	unsigned int index = get_unum();
	printf(" Number at data[%u] is %u\n", index, addr[index]);
	return (0);
}

//on peut tenter decrire numero par numero du shellcode puis essayer de pointer dessus
