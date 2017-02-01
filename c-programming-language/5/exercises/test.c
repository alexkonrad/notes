#include <stdio.h>

int main() {
  int len;
  char *p;

  getline(&p, &len, stdin);

  printf("Received %d characters.\n", len);

  printf("%s\n", p);

  return 0;
} 
