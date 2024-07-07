#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set>

int main(void)
{
  int P, V, Q, M;
  std::cin >> P >> V >> Q >> M;

  int startV = P - abs(V); 
  int startM = Q - abs(M); 
  int endV = P + abs(V); 
  int endM = Q + abs(M);

  std::set<int> setV; 
  std::set<int> setM;

  int count = (endV - startV + 1) + (endM - startM + 1);

  int minEnd = std::min(endV, endM);
  int maxStart = std::max(startV, startM);
  int overlap = std::max(0, minEnd - maxStart + 1);

  count -= overlap;

  std::cout << count << std::endl;
  

  return 0;
}
