#include <iostream>

int main()
{
  int n, k, d;

  std::cin >> n >> k >> d;

  int plus = -1;

if (n % k == 0)
{
	std::cout << n; 
	for (int i = 0; i < d; ++i)
  {
		std::cout << 0;
  }
}
else 
{
	for (int j = 0; j < 10; j++)
    {
		if(( n * 10 + j) % k == 0 ) plus = n * 10 + j;
    }
    if (plus == -1) std::cout << plus; 
	else
    {
		std::cout << plus;
    	for (int i = 0; i < d - 1; ++i) std::cout << 0;
    }
}
  return 0;
}
