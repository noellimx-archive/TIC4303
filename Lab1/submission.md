this is for working reference


it is implied (malloc 256) / (line length =  16) = 16 byte per character




example run
gcc -Wall -fsanitize=address L1-eg.c L1-main.c && echo "abcdefghijklmnopqrstuvwxyz" | ./a.out


# Notes

- sizeof has no idea of malloc (the programmer controls memory allocation!!!)
- ```gcc``` flag ```-fsanitize=address``` helps to check for memory leaks during runtime. i.e, if illegal value modification to other variable's or stack's heap memory