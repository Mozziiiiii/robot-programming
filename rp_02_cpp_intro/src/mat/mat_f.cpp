#include "mat_f.h"
#include <assert.h>
#include <iostream>
#include <cmath>
#include <random>


using namespace std;

MatF::MatF():
  rows(0),
  cols(0),
  dimension(0),
  v(nullptr){}

MatF::MatF(int rows, int cols){
    this->rows=rows;
    this->cols=cols;
    this->dimension=rows*cols;

    if(dimension>0){
       this->v=new float[dimension];
    } else {
        this->v=nullptr;
    }
}

MatF::~MatF(){
        delete[] v;
}


MatF::MatF(const MatF& other)
  : rows(other.rows), cols(other.cols), dimension(other.dimension), v(nullptr) {
    if (dimension > 0) {
      v = new float[dimension];
      for (int i = 0; i < dimension; ++i) v[i] = other.v[i];
    }
}

void MatF::fill(float f){
    for(int i=0; i<dimension; i++){
        v[i]=f;
    }
}

void MatF::randFill(){
    static thread_local std::mt19937 rng(std::random_device{}());  // una volta sola
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);        // [0,1)

    for (int i = 0; i < dimension; ++i)
        v[i] = dist(rng);
}

float& MatF::at(int pos){
    return v[pos];
}

const float&MatF::at(int pos) const{
    return v[pos];
}

float& MatF::at(int r, int c){
    return v[r*cols+c];
}

const float&MatF::at(int r, int c) const{
    return v[r*cols+c];
}

MatF& MatF::operator=(const MatF& other) {
    if (this == &other)  // auto-assegnazione
        return *this;

    // Se forma/dimensione diversa, rialloca
    if (rows != other.rows || cols != other.cols) {
        delete[] v;
        rows = other.rows;
        cols = other.cols;
        dimension = other.dimension;
        v = (dimension > 0) ? new float[dimension] : nullptr;
    } else {
        // Stessa forma: assicurati che dimension sia allineata
        dimension = other.dimension;
        // (v è già allocato della giusta dimensione)
    }

    // Copia i dati (se c'è qualcosa da copiare)
    for (int i = 0; i < dimension; ++i)
        v[i] = other.v[i];

    return *this;
}


MatF MatF::operator +(const MatF& other) const{

    assert(other.dimension==dimension && "dim mismatch");
    MatF returned(*this);

    for(int i=0; i<dimension; i++)
        returned.v[i]+= other.v[i];
    return returned;
}

MatF MatF::operator -(const MatF& other) const{

    assert(other.dimension==dimension && "dim mismatch");
    MatF returned(*this);

    for(int i=0;i<dimension;i++)
        returned.v[i]-=other.v[i];
    return returned;
}

MatF MatF::operator* (float f) const {
    MatF returned(*this);

    for(int i=0;i<dimension;i++)
        returned.v[i]*= f;
    return returned;
}

VecF MatF::operator*(const VecF& other) const{
    assert(other.dim==cols && "dim mismatch");
    VecF returned (rows);

    for(int i=0; i<rows;i++){
        float sum=0.0f;
        for(int j=0; j<cols;j++)
            sum+= other.v[j]*at(i,j);
            returned.v[i]=sum;
    }
    return returned;
}

MatF MatF::operator*(const MatF& other) const {
    assert(cols == other.rows && "dimension mismatch");
    MatF returned(rows, other.cols);

    for (int i = 0; i < rows; ++i) {
        for (int k = 0; k < other.cols; ++k) {
            float sum = 0.0f;
            for (int j = 0; j < cols; ++j) {
                sum += at(i, j) * other.at(j, k);
            }
            returned.at(i, k) = sum;
        }
    }
    return returned;
}

MatF MatF::transpose() const {
  MatF returned(cols, rows);
  for (int r=0; r<rows; ++r)
    for (int c=0; c<cols; ++c)
      returned.at(c,r)=at(r,c);
  return returned;
}


std::ostream& operator <<(std::ostream& os, const MatF& m) {
  os << "{ ptr: " << &m <<", rows: " << m.rows << ",  cols: " << m.cols << endl;
  os << "  values:[ " << endl;
  for (int r=0; r<m.rows; ++r) {
    os << "\t";
    for (int c=0; c<m.cols; ++c) {
      os << m.at(r,c) <<  " ";
    }
    os << endl;
  }
  os << " ]" << endl << "}";
  return os;
}
