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
	edx = index;
	edx -= eax;
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

//peut etre mettre le shellcode dans les arg ou dans le storage
//
//
//
//le -11 segfault: on touche a ebp sauvegarder. il suffit de modifier l'ebp pour
//avoir une stack personnalisee
//read -9: adresse de la ou on ecris.
//
//
//
//
//in -11 => store *(read -9) + 4*4 ----------------------------------------
//                                                                         |
//                                                                         |
//                                                                         |
//                                                                         |
//0                                                                        |
//+1   -> new esp   ==       *(read -9) + 1*4             && pop ebx       |
//+2   -> pop esi               ^                                          |
// 3   -> pop edi               | lea    -0xc(%ebp),%esp   <----------------
//+4   -> new ebp   ==       *(read -9) + 4*4             && pop ebp
//+5   -> pop eip   => store *(shellcode)
// 6
//+7
//+8
// 9
//+10
//+11
