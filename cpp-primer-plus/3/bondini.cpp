// bondini.cpp -- using escape sequences
#include <iostream>
int main()
{
  using namespace std;
  cout << "\aOperation \"HyperHype\" is now activated!\n";
  cout << "Enter your agent code:_______\b\b\b\b\b\b\b";
  long code;
  cin >> code;
  cout << "\aYou entered " << code << "...\n";
  cout << "\aCode verified!\n";
  return 0;
}
