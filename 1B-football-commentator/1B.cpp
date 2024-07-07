#include <iostream>
#include <string>

int main(void)
{
  std::string M1, M2;
  int loc;

  int sum1, sum2;

  int answer;

  std::cin >> M1 >> M2 >> loc;

  int G1, G2; 
  G1 = std::stoi(M1.substr(0, M1.find(":")));
  G2 = std::stoi(M1.substr(M1.find(":") + 1));

  int currG1, currG2;
  currG1 = std::stoi(M2.substr(0, M2.find(":")));
  currG2 = std::stoi(M2.substr(M2.find(":") + 1));

  sum1 = G1 + currG1; 
  sum2 = G2 + currG2; 

  if (sum1 > sum2)
  {
    answer = 0;
  }

  if (sum1 == sum2)
  {
    if (loc == 2)
    {
      if (G1 > currG2)
      {
        answer = 0;
      }
      if (G1 == currG2)
      {
        answer = 1;
      }
      if (G1 < currG2)
      {
        answer = 1; 
      }
    }
    if (loc == 1)
    {
      if (currG1 > G2)
      {
        answer = 0;
      }
      if (currG1 == G2)
      {
        answer = 1;
      }
      if (currG1 < G2)
      {
        answer = 1;
      }
    }
  }
  if (sum1 < sum2)
  {
    if (loc == 2)
    {
      if (G1 < currG2)
      {
        answer = sum2 - sum1 + 1;
      }
      if (G1 == currG2)
      {
        answer = sum2 - sum1 + 1;
      }
      if (G1 > currG2)
      {
        answer = sum2 - sum1;
      }
    }
    if (loc == 1)
    {
      if (currG1 < G2)
      {
        if ((sum2 - sum1) > (G2 - currG1)) answer = sum2 - sum1;
        if ((sum2 - sum1) == (G2 - currG1)) answer = sum2 - sum1 + 1;
        if ((sum2 - sum1) < (G2 - currG1)) answer = sum2 - sum1 + 1;
      }
      if (currG1 == G2)
      {
        answer = sum2 - sum1;
      }
      if (currG1 > G2)
      {
        answer = sum2 - sum1;
      }
    }
  }
  std::cout << answer;

  return 0;
}
