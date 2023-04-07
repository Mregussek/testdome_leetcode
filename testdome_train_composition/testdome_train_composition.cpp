#include <stdexcept>
#include <iostream>
#include <deque>

class TrainComposition
{
public:

  void attachWagonFromLeft(int wagonId)
  {
    wagons.push_front(wagonId);
  }

  void attachWagonFromRight(int wagonId)
  {
    wagons.push_back(wagonId);
  }
  int detachWagonFromLeft()
  {
    int popped = *wagons.begin();
    wagons.pop_front();
    return popped;
  }

  int detachWagonFromRight()
  {
    int popped = *(wagons.end() - 1);
    wagons.pop_back();
    return popped;
  }

private:

  std::deque<int> wagons{};

};

#ifndef RunTests
int main()
{
  TrainComposition train;
  train.attachWagonFromLeft(7);
  train.attachWagonFromLeft(13);
  std::cout << train.detachWagonFromRight() << "\n"; // 7 
  std::cout << train.detachWagonFromLeft(); // 13
}
#endif