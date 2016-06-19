// 4-seconds.cpp -- converts seconds to hours, minutes, days
#include <iostream>
int stod(int s);
int stom(int s);
int stos(int s);
int main()
{
  using namespace std;
  cout << "Enter seconds: ";
  int s;
  cin >> s;
  cout << s << " seconds = "
       << stod(s) << "days, "
       << stom(s) << "min, and "
       << stos(s) << " seconds";
  return 0;
}
const int SECONDS_IN_MINUTE = 60;
const int SECONDS_IN_DAY = SECONDS_IN_MINUTE * 60 * 24;
int stod(int s)
{
  return s / SECONDS_IN_DAY;
}
int stom(int s)
{
  return (s % SECONDS_IN_DAY) / SECONDS_IN_MINUTE;
}
int stos(int s)
{
  return s % SECONDS_IN_MINUTE;
}
