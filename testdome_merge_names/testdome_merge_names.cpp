#include <iostream>
#include <vector>
#include <set>

std::vector<std::string> unique_names(const std::vector<std::string>& names1, const std::vector<std::string>& names2)
{
  std::set<std::string> setNames{};
  std::vector<std::string> result{};
  result.reserve(names1.size() + names2.size());

  for (int i = 0; i < names1.size(); ++i)
  {
    if (setNames.contains(names1[i].c_str()))
    {
      continue;
    }

    setNames.insert(names1[i].c_str());
    result.push_back(names1[i]);
  }

  for (int i = 0; i < names2.size(); ++i)
  {
    if (setNames.contains(names2[i].c_str()))
    {
      continue;
    }

    setNames.insert(names2[i].c_str());
    result.push_back(names2[i]);
  }

  return result;
}

#ifndef RunTests
int main()
{
  std::vector<std::string> names1 = { "Ava", "Emma", "Olivia" };
  std::vector<std::string> names2 = { "Olivia", "Sophia", "Emma" };

  std::vector<std::string> result = unique_names(names1, names2);
  for (auto element : result)
  {
    std::cout << element << ' '; // should print Ava Emma Olivia Sophia
  }
}
#endif