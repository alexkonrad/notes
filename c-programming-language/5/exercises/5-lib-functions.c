#include <stdio.h>

void mystrncpy(char *s, char *t, int n) {
  for (int m = 0; m < n; m++)
    *s++ = *t++; 
}

void mystrncat(char *s, char *t, int n) {
  while (*++s)
    ;
  
  for (int m = 0; m < n; m++)
    *s++ = *t++;
}

int mystrncmp(char *s, char *t, int n) {
  for(int m = 1; *s == *t && m < n; m++, s++, t++)
    if (*s == '\0')
      return 0;

  return *s - *t;
}

int main() {
  char p[5] = "Hello";
  char *q = "World";

  mystrncpy(p, q, 5);
  
  printf("%s\n", p);

  char s[100] = "Hello, ";
  char *t = "World...";

  mystrncat(s, t, 5);

  printf("%s\n", s);

  char *u = "Hello";
  char *v = "Hella";

  printf("%d\n", mystrncmp(u, v, 4));
  printf("%d\n", mystrncmp(u, v, 5));

  return 0;
}
