#include <stdio.h>
#include <stdlib.h>

void do_reverse(void)
{
	int l, i, c;
	char *p;

	p = (char *)malloc(256);
	for (i = 0; (c = getchar()) != '\n'; i++)
		p[i] = c;
	l = i;
	for (; i > 0; i--)
		putchar(p[i - 1]);
	if (l > 0)
		putchar('\n');
}
