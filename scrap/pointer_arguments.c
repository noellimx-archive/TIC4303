

#include <stdio.h>

void some(char **ptr_chr_ptr)
{
    printf("start of some\n");
    printf("\n");
    printf(ptr_chr_ptr);
    printf("\n dereference \n");
    printf("%d\n", *ptr_chr_ptr);
    printf("\n dereference dereference\n");
    printf("%d\n", **ptr_chr_ptr);
    printf("\nend of some");
}

int main(void)
{
    char chr = 'a';
    char *chr_ptr;
    (chr_ptr);  // ok
    (*chr_ptr); // ok

    chr_ptr = &chr;
    printf("--- %d\n", chr_ptr);
    // not ok (*(*chr_ptr));

    (&chr_ptr);

    (*(&chr_ptr));

    printf("%c\n", *(*(&chr_ptr)));

    some(&chr_ptr);
    return -1;
}