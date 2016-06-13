#include <iostream>
double ltoa(double l);

int main()
{
  using namespace std;

  cout << "Enter the number of light years: ";
  double l;
  cin >> l;
  cout << l << " light years = " << ltoa(l)
       << " astronomical units." << endl;

  return 0;
}

double ltoa(double l)
{
  return 63240 * l;
}
