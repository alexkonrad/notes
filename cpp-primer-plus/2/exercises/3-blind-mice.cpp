#include <iostream>
void mice(void);
void run(void);

int main()
{
  mice();
  mice();
  run();
  run();
  return 0;
}

void mice(void)
{
  using namespace std;
  cout << "Three blind mice" << endl;
}

void run(void)
{
  using namespace std;
  cout << "See how they run" << endl;
}
