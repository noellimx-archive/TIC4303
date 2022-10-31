#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void do_not_call(void);
int my_protect = 0;
int i;

void printbytes(char *p, int j, int k) // only for convenience, not needed
{
  for (; j <= k; j++) printf("%02d: %p : %02hhx\n", j, p+j, p[j]);
}

void cookie_error() // call when error detected
{
  fprintf(stderr, "wrong cookie\n");
  exit(1);
}

FILE *fp;

int f()
{
  fp = fopen("/dev/urandom", "r");



  char prebuf[1];
  char buf[8]; 
  char postbuf[1];
  fread(&prebuf, 1, 1, fp);
  fread(&postbuf, 1, 1, fp);
  fclose(fp);
  char c;


  char b[1];

  // LINE1 - don't change code from LINE1 to LINE2 
  printf("Enter a string: ");
  for (i = 0; (c = getchar()) != '\n'; i++) buf[i] = c;
  buf[i] = '\0';
  // printf("string = [%s]\n", buf);
  // LINE2

  printf("prebuf\n");
  printbytes(prebuf, 0, 1);

  printf("buf\n");
  printbytes(buf, 0, 8);
  
  printf("postbuf\n");
  printbytes(postbuf, 0, 1);

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
  if (argc > 1 && strcmp(argv[1], "-p")==0)
    my_protect = 1;
  
  printf("f = %p\n", (void *) do_not_call); // leak
  return f();
}

