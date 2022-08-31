/*
 * CS4239 
 * Lab 22 (c) Roland Yap
 */

#include <stdlib.h>
#include <stdio.h>

int glob = 42;

void setvalue(char *p, char v)
{

	printf("--%c\n", v);
	printf("--%p\n", p);
	printf("--%c\n", *p);
	*p = v;
}

int main(int argc, char *argv[], char *envp[])
{
	char *p, *hello="world", string[]="1234";
	int *q;
	int choice=1;

	if (argc > 1) choice=atoi(argv[1]);
	printf("choice %d\n", choice);

	switch (choice) {
	case 1:
		p = 0;
		setvalue(p, 0);
		break;
	case 2:
		p = hello;
		setvalue(p, 'W');
		break;
	case 3:
		p = string;
		setvalue(p, '0');
		break;
	case 4:
		p = 0;
		choice = *p;
		break;
	case 5:
		p = (char *) &choice;
		setvalue(p, 5);
		break;
/**
	case 6:
		q = (int *) 0x400000;
		printf("@%p = %x\n", q, *q);
		break;
	case 7:
		p = (char *) 0x404040;
		setvalue(p, 7);
		break;
**/
	case 8:
		p = (char *) 0x400000000000;
		setvalue(p, 8);
		break;
	}
	return 0;
}

