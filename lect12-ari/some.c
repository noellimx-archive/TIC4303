#include <stdio.h>



int main(){


    int i, neg=0, pos=0;
    char a;
    for(i = 1; i <= 127; i++){

        a = (char) i * (char)127;
        printf("%d %d %d\n", i, (i * 127) % 256, a);

    }
}