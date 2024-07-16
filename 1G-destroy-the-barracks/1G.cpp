#include <iostream>
#include <cmath>

int calc(int t, int myunits, int barhp, int enemyprod)
{
    int rounds = 0;
    int enemyunits = 0;

    while (barhp >= t)
    {
        if (enemyunits >= myunits)
            return pow(10, 9);

        barhp -= myunits - enemyunits;
        enemyunits = 0;

        if (barhp >= 0)
        {
            enemyunits += enemyprod;
        }

        rounds++;
    }

    while (barhp > 0)
    {
        if (myunits <= 0)
            return pow(10, 9);

        if (barhp >= myunits)
            barhp -= myunits;

        else
        {
            enemyunits -= myunits - barhp;
            barhp = 0;
        }

        myunits -= enemyunits;

        if (barhp > 0)
        {
            enemyunits += enemyprod;
        }

        rounds++;
    }

    while (enemyunits > 0)
    {
        if (myunits <= 0)
            return pow(10, 9);

        enemyunits -= myunits;

        if (enemyunits > 0)
        {
            myunits -= enemyunits;
        }

        rounds++;
    }

    return rounds;
}

int main()
{
    int x, y, p;

    std::cin >> x >> y >> p;

    int ans = pow(10, 9);

    for (int i = 0; i < (y + 2); i++)
    {
        ans = std::min(ans, calc(i, x, y, p));
    }

    if (ans != pow(10, 9))
    {
        std::cout << ans;
    }
    else
    {
        std::cout << -1;
    }

    return 0;
}
