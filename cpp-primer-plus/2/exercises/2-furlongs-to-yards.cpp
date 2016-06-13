#include <iostream>
int furlongs_to_yards(int d);

int main()
{
  using namespace std;
  cout << "Enter distance in furlongs: ";
  int dist;
  cin >> dist;
  cout << dist << " furlongs is "
       << furlongs_to_yards(dist) << " yards."
       << endl;

  return 0;
}

int furlongs_to_yards(int d)
{
  return d * 220;
}
