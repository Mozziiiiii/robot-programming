#pragma once
#include "vec_f.h"
#include <ostream>

struct MatF {
  int rows, cols, dimension; // guess what
  float* v; // elements to the data

  MatF();
  MatF(int rows, int cols);
  ~MatF();
  MatF(const MatF& other);
  void fill(float f);
  void randFill();
  float& at(int pos);
  const float&at(int pos) const;
  float& at(int r, int c);
  const float&at(int r, int c) const;
  MatF& operator =(const MatF& other);
  MatF operator +(const MatF& other) const;
MatF operator -(const MatF& other) const;
MatF operator* (float f) const;
VecF operator*(const VecF& other) const;
MatF operator*(const MatF& other) const;
MatF transpose() const;
};
std::ostream& operator <<(std::ostream& os, const MatF& v);