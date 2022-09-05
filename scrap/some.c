

#include <stdio.h>

int main(void)
{
    int some[111];

    printf("Bytes: %lu, Element Size: %lu, Number of Elements: %lu %lu %lu", sizeof(some), sizeof(int), sizeof(some) / sizeof(int));
    
    return -1;
}