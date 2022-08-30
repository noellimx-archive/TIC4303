/*
 * CS4239 mem-region.c
 * Lab 2, (c) Roland Yap
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

char *rostr = "abcdefgh";
int global[4];
char initglobal[] = "1234567890";

void addr(void *ptr, char *s)
{
	printf("%-22s : %p\n", s, ptr);
}

void f(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6,
	   int arg7, int arg8)
{
	char local[32];
	addr(&arg1, "f(arg1)");
	addr(&arg6, "f(arg6)");
	addr(local, "f():local");
}

int main(int , char* [], char* []);
int main2(int argc, char *argv[], char *envp[])
{
	char buf[256], local[16];
	void *heap;

	addr(addr, "addr of func addr");
	addr(main, "addr of func main");
	addr(rostr, "addr of char array rostr"); // uses value of rostr
	addr(&rostr, "addr of pointer to char array rostr");
	addr(global, "global"); // global is treated as &global[0]
	addr(initglobal, "initglobal");
	addr(local, "local");

	int malloc_size = 16;
	heap = malloc(malloc_size);
	addr(heap, "heap from malloc(16)");
	f(1, 2, 3, 4, 5, 6, 7, 8);
	addr(argv[0], "argv[0], which is a char array"); // argv[0] has type (char *)
	addr(envp[0], "envp[0], which is a char array");
	addr(&errno, "errno"); // comes from errno.h
	addr(stdout, "stdout"); // comes from stdio.h
	fflush(stdout);

	printf("\n\nMemory Map from /proc/%d/maps\n", getpid());
	sprintf(buf, "cat /proc/%d/maps", getpid());
	system(buf);
	return 0;
}

int main(int argc, char *argv[], char* envp[]){
	char buf[256], local[16];
	void *heap;
	addr(buf, "addr of buf");
	addr(local, "addr of local");
	addr(heap, "addr of heap");


}