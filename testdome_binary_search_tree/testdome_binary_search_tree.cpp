#include <stdexcept>
#include <string>
#include <iostream>

class Node
{
public:
  Node(int value, Node* left, Node* right)
  {
    this->value = value;
    this->left = left;
    this->right = right;
  }

  int getValue() const
  {
    return value;
  }

  Node* getLeft() const
  {
    return left;
  }

  Node* getRight() const
  {
    return right;
  }

private:
  int value{ -1 };
  Node* left{ nullptr };
  Node* right{ nullptr };
};

class BinarySearchTree
{
public:
  static bool contains(const Node& root, int value)
  {
    if (value == root.getValue())
    {
      return true;
    }

    Node* pNode = nullptr;
    if (value > root.getValue())
    {
      pNode = root.getRight();
    }
    else
    {
      pNode = root.getLeft();
    }

    if (pNode == nullptr)
    {
      return false;
    }
    return contains(*pNode, value);
  }
};

#ifndef RunTests
int main()
{
  Node n1(1, NULL, NULL);
  Node n3(3, NULL, NULL);
  Node n2(2, &n1, &n3);

  std::cout << BinarySearchTree::contains(n2, 3);
}
#endif