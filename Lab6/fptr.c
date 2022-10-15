

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <sys/mman.h>

#define L (32)

int addnum(int a)
{
	return 255 + a;
}

int main(int argc, char *argv[], char *envp[])
{

	int a;
	int (*f)(int); // pointer to a function:int->int
	void *code_buf;

	char *p;
	char data[] = {0x0f, 0x0b};

	printf("[f] initialized to: %p\n", f);
	f = NULL;
	printf("[f] after assign NULL: %p\n", f);
	// f(1); /* illegal, seg fault*/

	f = addnum;

	printf("addnum(10) = %d \n",addnum(10) );
	;
	printf("f(10) = %d \n",f(10) );

	code_buf = (void *) mmap(0,4096, PROT_EXEC|PROT_READ|PROT_WRITE, MAP_PRIVATE| MAP_ANONYMOUS, -1 ,0); 
	// code_buf = (int *) mmap(0, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0); /* Without protection execution, bus error */

	printf("code_buf: %p\n", code_buf);

	memcpy(code_buf, addnum, L);
	f = (int (*) (int)) code_buf;

	printf("f(10) = %d\n",f(10) );

	p = index((char *) code_buf, 0xff);

	printf("before *p=%hhx\n", *p);
	*p = 100;
	printf("after *p= 0x%hhx or %d\n", *p, *p);

	printf("f(10) = %d\n",f(10) );

	p = index((char *) code_buf, 0xc3);

	printf("f(10) = %d\n",f(10) );

	printf("WARN\n");
	memcpy(code_buf, data, 2); /* Change memory from function to data, illegal instruction on ptr execution */

	int bar (int );
	memcpy(code_buf,bar,L  ) ;

	
	printf("LINE4 code_buf == p %i", code_buf == p);
	printf("%p",p);
	printf("%p", code_buf);
	printf("f(10) = %d\n",f(10) );

	// int iii[] = {1,2,3};
	// memcpy(code_buf,iii,L  ) ;

	// printf("f(10) = %d\n",f(10) );



}



int bar (int a) {

	return 0;
}