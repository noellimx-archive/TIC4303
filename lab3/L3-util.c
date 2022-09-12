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

void oops(void)
{
	fprintf(stderr, "NULL deref\n");
	exit(1);
}

void f(struct S *p, int *q)
{
	int x;
	x = p->b[1];
	if (!p) oops();
	*q = 42;
}

