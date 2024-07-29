#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int k;
    cin >> k;

    int minx, miny, maxx, maxy;
    cin >> minx >> miny;
    maxx = minx;
    maxy = miny;

    for (int i = 0; i < k - 1; ++i) {
        int x, y;
        cin >> x >> y;
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
    }

    cout << minx << " " << miny << " " << maxx << " " << maxy << endl;
    return 0;
}

