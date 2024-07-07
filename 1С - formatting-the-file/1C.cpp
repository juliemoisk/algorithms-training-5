#include <iostream>

int main(void)
{
  int n;
  std::cin >> n;

  long long int total = 0;

  for (int i = 0; i < n; i++)
  {
    int space;
    std::cin >> space;

    total += space/4 + std::min(space%4, 2);
  }

  std::cout << total;
  return 0;
}
