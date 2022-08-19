

#include <stdio.h>

int main(void)
{
    char chr = 'a';
    char *chr_ptr;
    (chr_ptr);  // ok
    (*chr_ptr); // ok

    chr_ptr = &chr;

    // not ok (*(*chr_ptr));

    (&chr_ptr);

    (*(&chr_ptr));

    printf("%c", *(*(&chr_ptr)));
    return -1;
}