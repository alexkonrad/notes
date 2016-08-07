// strings.cpp
#include <iostream>
#include <cstring>
int main()
{
  using namespace std;
  const int Size = 15;
  char name1[Size];  
  char name2[Size] = "C++owboy";
  cout << "I'm " << name2 << "! What's your name?\n";
  cin >> name1;
  cout << "You are " << name1;
  cout << " and your name has " << strlen(name1)
       << " letters." << endl;
  cout << "Your initial is " << name1[0] << endl;
  name2[3] = '\0';
  cout << "The first three characters of my name are "
       << name2 << endl;
  return 0;
}
