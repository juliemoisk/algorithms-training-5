#include <iostream>
#include <cmath>

int main(void)
{
	int l, x1, v1, x2, v2;

	std::cin >> l >> x1 >> v1 >> x2 >> v2;

	int ans = pow(10, 9);

	for (int i = 0; i < 2; i++)
	{
		int deltax = (x2 - x1 + l) % l;
		int deltav = v1 - v2;

		if (deltav < 0)
		{
			deltav = -deltav;
			deltax = (-deltax + l) % l;
		}

		if (deltax == 0)
		{
			ans = 0;
		}

		if (deltav != 0)
		{
			ans = std::min(ans, deltax / deltav);
		}

		x2 = (-x2 + l) % l;
		v2 = -v2;
	}

	if (ans == pow(10, 9))
	{
		std::cout << "NO";
	}

	else
	{
		std::cout << "YES";
	}

	return 0;
}
