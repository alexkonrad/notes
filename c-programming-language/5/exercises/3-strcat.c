#include <stdio.h>

/* mystrcat: append t to s */
void mystrcat(char *s, char *t)
{
  while (*++s)
    ;
  while (*s++ = *t++)
    ;
}


int main() {
  char dest[100] = "This is an ";
  char *src = "English-language sentence.";
  
  mystrcat(dest, src);

  printf("%s\n", dest);

  return 0;
}
