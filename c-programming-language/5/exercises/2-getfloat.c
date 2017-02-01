#include <ctype.h>
#include <math.h>
#include <stdio.h>

int getchar(void);
void ungetch(int);

/* getfloat: get next float from input into *pn */
int getfloat(float *pn)
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
  for (*pn = 0; isdigit(c); c = getchar())
    *pn = 10 * *pn + (c - '0');
  if (c == '.') {
    for (int i = 1, c = getchar(); isdigit(c); c = getchar(), i++) {
      *pn = *pn + (pow(10, -i) * (c - '0'));
    }
  }
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

int main() {
  float f;

  getfloat(&f);

  printf("%.2f\n", f);

  return 0;
}
