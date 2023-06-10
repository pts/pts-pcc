/*#include <stdio.h>*/
extern int printf(const char *format, ...);

int main(int argc, char **argv) {
  printf("Hello, %s!\n", argc < 2 ? "World" : argv[1]);
  return 0;
}
