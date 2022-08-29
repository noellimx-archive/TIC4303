/*
 * Name: Sim Yizhun
 * Student Number: A0211422B
 * Email: E0493753@u.nus.edu
 */

#include <stdio.h>
#include <stdlib.h>

void populateWithNewPointer(int i, int c, size_t size, char **pNew, char **pOld);
void populateWithOldPointer(size_t size, char **pNew, char **pOld);

void do_reverse(void)
{
	int l, i, c;
	char *p, *pNew;

	p = (char *)malloc(sizeof(char *) + 1);

	for (i = 0; (c = getchar()) != '\n'; i++)
	{
		size_t size = (i + 1) * sizeof(char *);

		if (i == 0)
		{
			pNew = (char *)malloc(sizeof(char *) + 1);
			p[i] = c;
			pNew[i] = c;
		}
		else
		{
			populateWithNewPointer(i, c, size, &pNew, &p);
			populateWithOldPointer(size, &pNew, &p);
		}
	}
	l = i;
	for (; i > 0; i--)
	{
		putchar(pNew[i - 1]);
	}
	if (l > 0)
		putchar('\n');
	free(p);
	free(pNew);
}

void populateWithNewPointer(int i, int c, size_t size, char **pNew, char **pOld)
{
	int j;
	free(*pNew);
	*pNew = NULL;
	*pNew = (char *)malloc(size + 1);
	for (j = 0; j < i; j++)
	{
		(*pNew)[j] = (*pOld)[j];
	}
	(*pNew)[i] = c;
}

void populateWithOldPointer(size_t size, char **pNew, char **pOld)
{
	int k;
	free(*pOld);
	*pOld = NULL;
	*pOld = (char *)malloc(size + 1);
	for (k = 0; k < size + 1; k++)
	{
		(*pOld)[k] = (*pNew)[k];
	}
}
