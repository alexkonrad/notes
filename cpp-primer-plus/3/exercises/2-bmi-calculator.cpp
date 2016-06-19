// bmi-calculator.cpp -- calculates BMI from height and weight
#include <iostream>
float bmi(int f, int i, int l);
int inches(int f, int i);
float meters(int i);
float kg(int l);
int main()
{
  using namespace std;
  cout << "Height (feet): _\b";
  int f;
  cin >> f;
  cout << "Height (inches): __\b\b";
  int i;
  cin >> i;
  cout << "Weight (pounds): ___\b\b\b";
  int l;
  cin >> l;
  cout << "BMI: " << bmi(f, i, l) << endl;
  return 0;
}
float bmi(int f, int i, int l)
{
  float height = meters(inches(f, i));
  return kg(l) / (height * height);
}
int inches(int f, int i)
{
  return 12 * f + i;
}
float meters(int i)
{
  return 0.0254 * i;
}
float kg(int l)
{
  return l / 2.2;
}
