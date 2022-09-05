

#include <stdio.h>

// See http://blog.llvm.org/2011/05/what-every-c-programmer-should-know_14.html

static void (*FP)(int, int) = 0;
static void impl(short potential_mutant, int always_long)
{   

    int mutant_short = potential_mutant;
    int diff = mutant_short - always_long;
    printf("[impl] %d %d %d%d\n", potential_mutant, always_long,diff,diff );
}

int main(void)
{

    printf("%d %d %d <- sizeof (int | short int | long int ) \n",sizeof(int), sizeof(short int), sizeof(long)); 

    // printf("%d %d\n", &FP, &impl);
    FP = impl;
    // printf("%d %d\n", &FP, &impl);

    FP(1,1);

    int i;
    i = 0;

    i = 2147483647;

    while ((i) != 0){
        i = i >> 1;
        printf("\n[]%d ->", i);

        FP(i,i);
    }




    

    return -1;
}