// 6-miles-driven.cpp -- reports miles per gallon
#include <iostream>
int mpg(int m, int g);
int main()
{
  using namespace std;
  cout << "Enter miles: ";
  int m;
  cin >> m;
  cout << "Enter gallons: ";
  int g;
  cin >> g;
  cout << "MPG: " << mpg(m, g) << endl;
  return 0;
}
int mpg(int m, int g)
{
  return (float) m / g;
}
