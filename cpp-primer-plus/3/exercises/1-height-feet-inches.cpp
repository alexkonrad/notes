// 1-height-feet-inches.cpp -- asks for height in inches and
// converts to height in feet and inches
#include <iostream>
int feet(int i);
int inches(int i);
int main()
{
  using namespace std;
  cout << "Enter your height in inches:___\b\b\b";
  int i;
  cin >> i;
  cout << "Height: " << feet(i) << " feet "
       << inches(i) << " inches." << endl;
  return 0;
}
int feet(int i)
{
  return i / 12;
}
int inches(int i)
{
  return i % 12;
}
