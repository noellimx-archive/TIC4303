#include <stdio.h>
#include <stdlib.h>




void do_reverse(void)
{	
	int c; // this character
	int to_allocate_size, current_allocated_size;

	int buffered_size;
	buffered_size = 0;

	char *p;

	to_allocate_size = 8;
	p = (char *) malloc(to_allocate_size);
	current_allocated_size = to_allocate_size;

	int null_terminator_size = 1;
	while (1) {
		if((c = getchar()) != '\n'){

			p[buffered_size] = c;
			buffered_size += 1;

			if ((buffered_size + null_terminator_size) >= current_allocated_size){

				to_allocate_size = current_allocated_size * 2;
				char * new_p;
				new_p = (char *) malloc(to_allocate_size);

				int buffered_cursor;
				buffered_cursor = 0;
				while(buffered_cursor < buffered_size){

					new_p[buffered_cursor] = p[buffered_cursor];
					buffered_cursor += 1;
				}
				free(p);
				p = new_p;
				current_allocated_size = to_allocate_size;
			}
		} else{
			break;
		}
	}


	int j = buffered_size - 1;
	while (j >= 0){
		putchar(p[j--]);
	}
	if (buffered_size > 0){
		putchar('\n');
	}

	return;
	
}
