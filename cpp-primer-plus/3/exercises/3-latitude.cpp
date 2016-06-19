// 3-latitude.cpp -- converts degrees, minutes and seconds to latitude in decimal format
#include <iostream>
float lat(int d, int m, int s);
int main()
{
  using namespace std;
  cout << "Enter a latitude in degrees, minutes, and seconds:\n";
  cout << "First, enter the degrees: ";
  int d;
  cin >> d;
  cout << "Next, enter the minutes of the arc: ";
  int m;
  cin >> m;
  cout << "Finally, enter the seconds of the arc: ";
  int s;
  cin >> s;
  cout << d << " degrees, " << m << " minutes, "
       << s << " seconds = " << lat(d, m, s) << " degrees.";
  return 0;
}
const float SECONDS = 60 * 60;
const float MINUTES = 60;
float lat(int d, int m, int s)
{
  return d + m / MINUTES + s / SECONDS;
}
