#include <iostream>
#include <string>
#include <vector>

bool bishop (std::vector<std::string> &arr, int row, int col)
{
  int i , j;
  int size = arr.size();

  for (i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
  {
    if (arr[i][j] != '*')
    {
      if (arr[i][j] == 'B')
      {
        return true;
      }
      break;
    }
  }

  for (i = row - 1, j = col + 1; i >= 0 && j < size; --i, j++)
  {
    if (arr[i][j] != '*')
    {
      if (arr[i][j] == 'B')
      {
        return true;
      }
      break;
    }
  }

  for (i = row + 1, j = col - 1; i < size && j >= 0; ++i, --j)
  {
    if (arr[i][j] != '*')
    {
      if (arr[i][j] == 'B')
      {
        return true;
      }
      break;
    }
  }

  for (i = row + 1, j = col + 1; i < size && j < size; ++i, j++)
  {
    if (arr[i][j] != '*')
    {
      if (arr[i][j] == 'B')
      {
        return true;
      }
      break;
    }
  }

  return false;
}

bool rook (std::vector<std::string> &arr, int row, int col)
{
  int size = arr.size();

  for (int i = row + 1; i < size; i++)
  {
    if (arr[i][col] != '*')
    {
      if (arr[i][col] == 'R')
      {
        return true;
      }
      break;
    }
  }

  for (int i = row - 1; i >= 0; --i)
  {
    if (arr[i][col] != '*')
    {
      if (arr[i][col] == 'R')
      {
        return true;
      }
      break;
    }
  }

  for (int j = col + 1; j < size; j++)
  {
    if (arr[row][j] != '*')
    {
      if (arr[row][j] == 'R')
      {
        return true;
      }
      break;
    }
  }

  for (int j = col - 1; j >= 0; --j)
  {
    if (arr[row][j] != '*')
    {
      if (arr[row][j] == 'R')
      {
        return true;
      }
      break;
    }
  }

  return false;
}

int main()
{
  std::vector<std::string> arr(8);

  for (int i = 0; i < 8; i++)
  {
    std::getline(std::cin, arr[i]);
  }

  int count = 0; 

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (arr[i][j] == '*')
      {
        if (!bishop(arr, i, j) && !rook(arr, i, j))
        {
          count++;
        }
      }
    }
  }

  std::cout << count;

  return 0;
}
