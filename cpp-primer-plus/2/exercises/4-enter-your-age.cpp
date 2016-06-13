#include <iostream>
int years_to_months(int years);

int main()
{
  using namespace std;

  cout << "Enter your age: ";
  int age;
  cin >> age;
  cout << "Your age in months is " << years_to_months(age);

  return 0;
}

int years_to_months(int years)
{
  return 12 * years;
}
