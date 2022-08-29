/*
 * Name: Sim Yizhun
 * Student Number: A0211422B
 * Email: E0493753@u.nus.edu
 */

#include <stdio.h>
#include <stdlib.h>

void populateWithNewPointer(int i, int c, size_t size, char **);

void do_reverse(void)
{
	int l, i, c;
	char *p;

	p = (char *)malloc(sizeof(char *) + 1);

	for (i = 0; (c = getchar()) != '\n'; i++)
	{
		size_t size = (i + 1) * sizeof(char *);

		populateWithNewPointer(i, c, size, &p);
	}
	l = i;
	for (; i > 0; i--)
	{
		putchar(p[i - 1]);
	}
	if (l > 0)
		putchar('\n');
	free(p);
}

void populateWithNewPointer(int i, int c, size_t size, char **pp)
{
	int j;
	char *ppNew = (char *)malloc(size + 1);
	for (j = 0; j < i; j++)
	{
		(ppNew)[j] = (*pp)[j];
	}
	ppNew[i] = c;
	free(*pp);
	*pp = ppNew;
}
