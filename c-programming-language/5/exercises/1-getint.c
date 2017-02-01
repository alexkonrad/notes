#include <ctype.h>
#include <stdio.h>

int getint(int *pn)
{
  int c, sign;

  while (isspace(c = getchar()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getchar();

  /* If the next character is not a digit,
   * push it back onto the buffer and
   * bail out.
   */
  if (!isdigit(c)) {
    ungetch(c);
    return 0;
  }

  for (*pn = 0; isdigit(c); c = getchar())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

int main() {
  int p;

  printf("%d", p);
  getint(&p);

  printf("%d", p);

  return 0;
}
