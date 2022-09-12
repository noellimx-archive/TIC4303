/*
 * CS4239 
 * Lab 3 (c) Roland Yap
 */


#include <stdio.h>
#include <stdlib.h>

struct S {
	char a;
	int b[3];
};

void oops(void);
void f(struct S *p, int *q);

int main()
{
	struct S A;
	int y;

	scanf("%d", &y);
	// f(&A, &y);
	f(((void *) 0), &y);
	printf("A = %d\n", y);
	return 0;
}

