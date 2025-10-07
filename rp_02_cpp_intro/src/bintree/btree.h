#pragma once
#include <iostream>

struct TreeNodeInt {
  int value;
  TreeNodeInt * left, *right;
  TreeNodeInt(int value=0,
              TreeNodeInt* left=nullptr,
              TreeNodeInt* right=nullptr);

~TreeNodeInt();
TreeNodeInt* find(int value_);
bool insert(int value_);
};
std::ostream& operator <<(std::ostream& os, const TreeNodeInt& node);
