#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void do_not_call(void);
int my_protect = 0;
int i;

void printbytes(char *p, int j, int k) // only for convenience, not needed
{
  for (; j <= k; j++)
    printf("%02d: %p : %02hhx\n", j, p + j, p[j]);
}

void cookie_error() // call when error detected
{
  fprintf(stderr, "wrong cookie\n");
  exit(1);
}

FILE *fp;

// Some of the
int f()
{

#define CANARY_SIZE 8
  fp = fopen("/dev/urandom", "r");

  char canary_value[CANARY_SIZE];
  char buf[8];
  char canary[CANARY_SIZE];
  char c;

  if (
      my_protect == 1)
  {
    int p = fread(&canary_value, 1, CANARY_SIZE, fp);
    if (p != CANARY_SIZE)
    {
      fprintf(stderr, "reading from /dev/urandom deviates from CANARY_SIZE \n");
      exit(1);
    }
    while (--p >= 0)
      canary[p] = canary_value[p];
  }
  printf("canaryvalue\n");
  printbytes(canary_value, 0, 7);
  printf("canary\n");
  printbytes(canary, 0, 7);

  // LINE1 - don't change code from LINE1 to LINE2
  printf("Enter a string: ");
  for (i = 0; (c = getchar()) != '\n'; i++)
    buf[i] = c;
  buf[i] = '\0';
  // printf("string = [%s]\n", buf);
  // LINE2

  printf("buf\n");
  printbytes(buf, 0, 7);

  printf("canary\n");
  printbytes(canary, 0, 7);

  if (my_protect == 1)
  {

    for(int p = 0; p < CANARY_SIZE; p++){
      if (canary[p] != canary_value[p]){
        cookie_error();
      }
    }
  }

  fclose(fp);

  return 0;
}

void do_not_call(void)
{
  printf("HIJACKED!\n");
  exit(0);
}

int main(int argc, char *argv[])
{
  setvbuf(stdout, 0, _IONBF, 0); // use unbuffered I/O to simplify things
  setvbuf(stdin, 0, _IONBF, 0);
  setvbuf(stderr, 0, _IONBF, 0);
  if (argc > 1 && strcmp(argv[1], "-p") == 0)
    my_protect = 1;

  printf("...my_protect %d\n", my_protect);
  printf("f = %p\n", (void *)do_not_call); // leak
  return f();
}
