#include <iostream>
int ctof(int c);

int main()
{
  using namespace std;
  cout << "Please enter a celsius value: ";
  int c;
  cin >> c;
  cout << c << " degrees Celsius is " << ctof(c)
       << " degrees Fahrenheit." << endl;

  return 0;
}

int ctof(int c)
{
  return 1.8 * c + 32;
}
