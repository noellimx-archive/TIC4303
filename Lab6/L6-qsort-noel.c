

#include <stdlib.h>	 // malloc, calloc
#include <string.h>	 // c string
#include <strings.h> // strings comparison
#include <stdio.h>	 // standard input / output

// A char* pointer refer to the address of the first element in a char array.
char *sample_char = "asd";

char chars[] = {'a', 'b'};
int ints[] = {1, 2};

// An array of char* pointers
char *num_STR[] = {"000001", "1", "1000", "  99 ", "1    "};

int ARRAY_SIZE = 5;
int string_comp(const void *, const void *);
int int_comp(const void *, const void *);

void preview();
void sorting();
int main()
{
	preview();

	sorting();
	return 0;
}

/*
	p1 - void pointer
	p2 - void pointer
*/
int string_comp(const void *p1, const void *p2)
{
	// In this practical, p1 and p2 are assumed addresses of char* pointers.

	// Cast pointers as char** pointers, then dereference to obtain char* pointers.
	char *c1 = *(char **)p1;
	char *c2 = *(char **)p2;
	return strcmp(c1, c2);
}

int string_comp_strict_type(const char **, const char **);
int string_comp2(const void *p1, const void *p2)
{

	return string_comp_strict_type((const char **)p1, (const char **)p2);
}

// Refer string_comp, with implicit conversion
int string_comp_strict_type(const char **p1, const char **p2)
{
	return strcmp(*p1, *p2);
}

/*
	p1 - void pointer
	p2 - void pointer
*/
int int_comp(const void *p1, const void *p2)
{
	// In this practical, p1 and p2 are assumed addresses of char* pointers.

	// Cast pointers as char** pointers, then dereference to obtain char* pointers.
	char *c1 = *(char **)p1;
	char *c2 = *(char **)p2;

	// Conversion is required from char array to int.
	// atoi takes in char* (ptr to char array)
	int i1 = atoi(c1);
	int i2 = atoi(c2);

	return i1 < i2 ? -1 : (i1 > i2 ? 1 : 0);
}

void preview()
{

	printf("[Preview]\n");

	printf("%s\n", sample_char);

	printf("%c\n", chars[0]); // legal
	printf("%s\n", chars);	  // legal
	printf("%p\n", chars);	  // legal

	printf("%p\n", ints); // legal
	// printf("%d\n", ints); // not legal

	printf("\"char *\": [\n");
	for (int i = 0; i < 3; i++)
	{
		printf(" { \"addr\": %p, \"value\": %s }\n", num_STR[i], num_STR[i]);
	}

	printf("] \n");

	printf("[End of Preview]\n");
}

void print_array(char *a[], int n)
{
	printf("\n");
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		printf("\"%s\" ", a[i]);
	}
	printf("\n");
}

void sorting()

{

	printf("[sorting] \n");

	int size_of_char_pointer = sizeof(char *);
	int size_of_ptr_to_char_pointer = sizeof(char **);

	printf("%i\n", size_of_char_pointer == size_of_ptr_to_char_pointer);
	printf("Original array\n");
	print_array(num_STR, ARRAY_SIZE);

	printf("[Sorting as int]... \n");
	print_array(num_STR, ARRAY_SIZE);

	printf("\n -> \n");
	qsort(num_STR, ARRAY_SIZE, sizeof(char **), int_comp);

	print_array(num_STR, ARRAY_SIZE);

	printf("[Sorting as str]... \n");
	print_array(num_STR, ARRAY_SIZE);

	printf("\n -> \n");
	qsort(num_STR, ARRAY_SIZE, sizeof(char **), string_comp);

	print_array(num_STR, ARRAY_SIZE);

	printf("[Sorting as str]... \n");
	print_array(num_STR, ARRAY_SIZE);

	printf("\n -> \n");
	qsort(num_STR, ARRAY_SIZE, sizeof(char **), string_comp2);

	print_array(num_STR, ARRAY_SIZE);
}
