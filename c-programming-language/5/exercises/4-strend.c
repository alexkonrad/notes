#include <stdio.h>

int strend(char *s, char *t)
{
  char *start_t = t;

  while (*s++)
    ;
  --s; 
  while (*t++)
    ;
  --t;
  
  while (t != start_t && *--t == *--s)
    ;

  return start_t == t && *t == *s;
}

int main() {
  printf("%d\n", strend("Alex Konrad", "Konrad"));
  printf("%d\n", strend("Alex Konrad", "Conrad"));
  printf("%d\n", strend("Alex Konrad", "Konrrad"));
  printf("%d\n", strend("Alex Konrad", ""));
  printf("%d\n", strend("", ""));

  return 0;
}
