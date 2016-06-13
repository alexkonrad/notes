// hexoct1.cpp -- shows hex and octal literals
#include <iostream>
int main()
{
  using namespace std;
  int chest = 42;
  int waist = 0x42;
  int inseam = 042;

  cout << "Chest: " << chest << " (42 in decimal)\n";
  cout << "Waist: " << waist << " (0x42 in hex)\n";
  cout << "Inseam: " << inseam << " (042 in octal)\n";
  return 0;
}
