#include <iostream>
#include <vector>

class RouteVisitedVector
{
public:
  RouteVisitedVector(int _x, int _y)
    : dim_x(_x), dim_y(_y)
  {
    visited.resize(dim_x * dim_y);
  }

  void set_visited(int x, int y)
  {
    visited[dim_x * y + x] = true;
  }

  bool is_visited(int x, int y) const
  {
    return visited[dim_x * y + x];
  }

private:
  std::vector<bool> visited{};
  int dim_x{ -1 };
  int dim_y{ -1 };
};


bool routeSearch(int fromRow, int fromColumn, int toRow, int toColumn,
  const std::vector<std::vector<bool>>& mapMatrix, RouteVisitedVector* pVisitedVector)
{
  auto IsPositionValid = [&mapMatrix](int row, int column) -> bool
  {
    return row >= 0 and column >= 0 and
      row < mapMatrix.size() and column < mapMatrix[row].size() and
      mapMatrix[row][column];
  };

  if (not IsPositionValid(fromRow, fromColumn) or not IsPositionValid(toRow, toColumn))
  {
    return false;
  }

  if (pVisitedVector->is_visited(fromRow, fromColumn))
  {
    return false;
  }

  if (fromRow == toRow and fromColumn == toColumn)
  {
    return true;
  }

  pVisitedVector->set_visited(fromRow, fromColumn);

  bool exists{ routeSearch(fromRow + 1, fromColumn, toRow, toColumn, mapMatrix, pVisitedVector) };
  if (not exists)
  {
    exists = routeSearch(fromRow - 1, fromColumn, toRow, toColumn, mapMatrix, pVisitedVector);
  }
  if (not exists)
  {
    exists = routeSearch(fromRow, fromColumn + 1, toRow, toColumn, mapMatrix, pVisitedVector);
  }
  if (not exists)
  {
    exists = routeSearch(fromRow, fromColumn - 1, toRow, toColumn, mapMatrix, pVisitedVector);
  }
  return exists;
}

bool routeExists(int fromRow, int fromColumn, int toRow, int toColumn,
  const std::vector<std::vector<bool>>& mapMatrix)
{
  RouteVisitedVector visitedVector{ (int)mapMatrix.size(), (int)mapMatrix[0].size() };
  return routeSearch(fromRow, fromColumn, toRow, toColumn, mapMatrix, &visitedVector);
}

#ifndef RunTests
int main()
{
  std::vector<std::vector<bool>> mapMatrix{
    {true, false, false},
    {true, true, false},
    {false, true, true}
  };

  std::cout << routeExists(0, 0, 2, 2, mapMatrix) << std::endl;
}
#endif