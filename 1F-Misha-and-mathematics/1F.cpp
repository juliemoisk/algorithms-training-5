#include <iostream>
using namespace std;

int main ()
{
  int n; cin >> n;
  int index = -1;
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    int per; cin >> per;
    if (per % 2 != 0)
    {
      count++;
      if (index < 0) index = i;
    }
  }

  if (count % 2 != 0)
  {
    for (int i = 0; i < n - 1; i++)
    {
      cout << "+";
    }
  }

  if (count % 2 == 0)
  {
    for (int i = 0; i < n -1; i++)
    {
      if (i != index) cout << "+";
      else 
        cout << "x";
    }
  }

  return 0;
}
