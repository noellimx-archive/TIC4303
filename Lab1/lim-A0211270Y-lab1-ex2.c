#include <stdio.h>
#include <stdlib.h>



#define NULL_TERMINATOR_SIZE 1
/*
 *	Name: NOEL LIM XIAN
 *	Student Number: A0211270Y
 *	Email: E0493357@u.nus.edu
 */

void do_reverse(void)
{	
	int c; // this character
	int to_allocate_capacity, current_allocated_capacity; // space awareness MUST be revised by programmer upon space allocation of the pointer.

	int buffered_size; // size of elements
	buffered_size = 0;

	char *p; // the pointer


	// re-allocation of space. the next 3 lines are to be executed consecutively to maintain consistency in tracking space of the pointer of interest.
	to_allocate_capacity = 8;
	p = (char *) malloc(sizeof(char) * to_allocate_capacity);
	current_allocated_capacity = to_allocate_capacity;

	// size mulitplication factor;

	int size_growth_factor = 2;

	while (1) { // reading
		if((c = getchar()) != '\n'){

			p[buffered_size] = c;
			buffered_size += 1;

			if ((buffered_size + NULL_TERMINATOR_SIZE) >= current_allocated_capacity){ // space reallocation criteria

				to_allocate_capacity = current_allocated_capacity * size_growth_factor;

				char * new_p;
				new_p = (char *) malloc(sizeof(char) * to_allocate_capacity);
				current_allocated_capacity = to_allocate_capacity;

				int buffered_cursor;
				buffered_cursor = 0;
				while(buffered_cursor < buffered_size){ // copying
					new_p[buffered_cursor] = p[buffered_cursor];
					buffered_cursor += 1;
				}
				free(p);
				p = new_p;
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

	free(p); // earned the right to exit
	return;
}
