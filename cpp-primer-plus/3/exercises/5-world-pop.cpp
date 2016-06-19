// world-pop.cpp -- displays the US population as a percentage of
// world population
#include <iostream>
long double percent(long long num, long long denom);
int main()
{
  using namespace std;
  cout << "Enter the world's population: ";
  long long w;
  cin >> w;
  cout << "Enter the US' population: ";
  long long u;
  cin >> u;
  cout << "The population of the US is " << percent(u, w)
       << "% of the world population.";
  return 0;
}
long double percent(long long num, long long denom)
{
  return (long double) num / denom * 100;
}
