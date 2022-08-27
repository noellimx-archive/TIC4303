#include <stdio.h>
#include <stdlib.h>

void do_reverse(void)
{
	printf("[eg] do_reverse \n");
	int l, i, c;
	char *p1, *p2, *p3;

	p1 = (char *)malloc(25);
	p2 = (char *)malloc(8);
	p3 = (char *)malloc(8);
	printf("[eg] implemented size of char is %lu\n", sizeof(char *));
	printf("[eg] p1 value is %p\n", p1);
	printf("[eg] p2 value is %p\n", p2);
	printf("[eg] p3 value is %p\n", p3);

	for (i = 0; (c = getchar()) != '\n'; i++)
	{
		p1[i] = c;
	}

	// a	b	c	d	e	f	g	h	i	j	k	l	m	n	o	p
	// 0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15


	printf("[eg] last char is %c", c);
	printf("[eg] buffered length is %d\n", i);
	printf("[eg] %d\n", p1[i-1]);

	printf("[eg] p1 first element is %c\n", *p1 );
	printf("[eg] p2 first element is %c\n", *p2 );

	l = i;
	for (; i > 0; i--)
	{
		putchar(p1[i - 1]);
	}
	if (l > 0)
	{
		putchar('\n');
	}
}
