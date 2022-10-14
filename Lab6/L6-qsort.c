/*
 * TIC4303 
 * Lab 6 qsort demo (c) Roland Yap
 */

#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>

// example of qsort using function pointer for comparison function (*compar)()
// see man qsort

char *num[] = {
	"000000001",
	"1", 
	"1000", 
	"  100 ", 
	"1     ", 
};


// compare p1 & p2 as strings
// call with the address of the array element, e.g. &(char *) = char **
int string_comp(const void *p1, const void *p2) 
{
	// be careful that address of element is passed so there is an
	// extra * needed here given that it is already (char *)
	// return strcmp((char *) p1, (char *) p2); /* a bug as needs deref */
	return strcmp(*((char **) p1), *((char **) p2));
}

// compare p1 & p2 as integers
int int_comp(const void *p1, const void *p2) 
{
	int i1, i2;

	// i1 = atoi((char *) p1); /* bug: same reason as line in string_comp() */
	i1 = atoi(*((char **) p1)); /* correct */
	// i2 = atoi((char *) p2); /* bug: same reason as line in string_comp() */
	i2 = atoi(*((char **) p2)); /* correct */
	// printf("comp(%s,%s)\n", p1, p2); /* bug: for debugging */
	// printf("comp(\"%s\", \"%s\")\n", *(char **) p1, *(char **) p2); /* correct: for debugging */
	if (i1 < i2) return -1;
	else if (i1 == i2) return 0;
	else return 1;
}

void print_array(char *a[], int n)
{
	int i;
	for (i=0; i < n; i++)
		printf("\"%s\" ", a[i]);
}

int main()
{
	printf("Original array\n"); print_array(num, 5); printf("\n");

	qsort(num, 5, sizeof(char *), int_comp);
	printf("sorted array as int\n"); print_array(num, 5); printf("\n");

	qsort(num, 5, sizeof(char *), string_comp);
	printf("sorted array as string\n"); print_array(num, 5); printf("\n");

	return(0);
}
