#include <stdio.h>
#include <stdlib.h>




void do_reverse(void)
{	
	// notice we do not know the space required and we can only read the buffer ONCE.
	
	// for each getchar

	// one character is 1 malloc size_t
	
	printf("[eg] do_reverse \n");


	int c1;


	int to_allocate_size, current_allocated_size;

	int buffered_size;
	buffered_size = 0;
	to_allocate_size = 8;

	char *p;
	p = (char *) malloc(to_allocate_size);
	current_allocated_size = to_allocate_size;

	int null_terminator_size = 1;
	while (1) {
		if((c1 = getchar()) != '\n'){
			printf("buffering %c\n",c1);

			p[buffered_size] = c1;
			buffered_size += 1;

			if ((buffered_size + null_terminator_size) >= current_allocated_size){
				printf("Overflow Prevention: expanding size and copying buffer.\n");

				printf("allocated_size %i -> ", to_allocate_size);
				to_allocate_size = current_allocated_size * 2;
				printf(" %i\n", to_allocate_size);

				char * new_p;
				new_p = (char *) malloc(to_allocate_size);

				int buffered_cursor;
				buffered_cursor = 0;
				while(buffered_cursor < buffered_size){

					printf("%i", buffered_cursor);
					new_p[buffered_cursor] = p[buffered_cursor];
					buffered_cursor += 1;
				}
				printf("\n");
				free(p);
				p = new_p;
				current_allocated_size = to_allocate_size;
			}
		} else{
			break;
		}
	}


	int l = 0;
	int j = buffered_size - 1;



	printf("\n :)");

	while (j >= 0){


		putchar(p[j--]);
	}
	printf("\n :))");

	for(int ii = 0; ii < buffered_size; ii++){

		printf("%c",p[ii]);
	}



	if (buffered_size > 0){
		p[buffered_size] = '\n';
		buffered_size += null_terminator_size;
	}

	printf("i need %i and have %i", buffered_size, current_allocated_size);
	return;
	// int l, i, c;
	// char *p1, *p2, *p3;

	// p1 = (char *)malloc(256);
	// p2 = (char *)malloc(8);
	// p3 = (char *)malloc(8);
	// printf("[eg] implemented size of char is %lu\n", sizeof(char *));
	// printf("[eg] p1 value is %p\n", p1);
	// printf("[eg] p2 value is %p\n", p2);
	// printf("[eg] p3 value is %p\n", p3);

	// for (i = 0; (c = getchar()) != '\n'; i++)
	// {
	// 	p1[i] = c;
	// }

	// // a	b	c	d	e	f	g	h	i	j	k	l	m	n	o	p
	// // 0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15


	// printf("[eg] last char is %c", c);
	// printf("[eg] buffered length is %d\n", i);
	// printf("[eg] %d\n", p1[i-1]);

	// printf("[eg] p1 first element is %c\n", *p1 );
	// printf("[eg] p2 first element is %c\n", *p2 );

	// l = i;
	// for (; i > 0; i--)
	// {
	// 	putchar(p1[i - 1]);
	// }
	// if (l > 0)
	// {
	// 	putchar('\n');
	// }
}
