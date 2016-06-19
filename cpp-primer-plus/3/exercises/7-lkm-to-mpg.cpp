// 7-lkm-to-mpg -- converts liters per 100 km to mpg
#include <iostream>
float to_mpg(float lkm);
int main()
{
  using namespace std;
  cout << "Enter liters per 100 km: ";
  float lkm;
  cin >> lkm;
  cout << "MPG: " << to_mpg(lkm) << endl;
  return 0;
}
float to_mpg(float lkm)
{
  return 62.14;
}
