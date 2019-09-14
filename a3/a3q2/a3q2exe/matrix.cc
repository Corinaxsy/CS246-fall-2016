#include <iostream>
#include <iomanip>
#include "matrix.h"
using namespace std;

Matrix::Matrix(int numRows, int numCols):
 rown{numRows},
 coln{numCols} {
 if ((rown == 0) || (coln == 0)) {
  matrix = nullptr;
 } else {
  matrix = new int*[rown];
  for (int i = 0;i < rown;++i) {
   matrix[i] = new int[coln];
  }
  for (int r = 0;r < rown;++r) {
   for (int c = 0;c < coln;++c) {
    matrix[r][c] = 0;
   }
  }
 }
}

Matrix::Matrix( const Matrix & other):
 rown{other.rown},
 coln{other.coln} {
 if ((rown == 0) || (coln == 0)) {
  matrix = nullptr;
 } else {
  matrix = new int*[rown];
  for (int m = 0;m < rown;++m) {
   matrix[m] = new int[coln];
  }
  for (int r = 0;r < rown;++r) {
   for (int c = 0;c < coln;++c) {
    matrix[r][c] = other.matrix[r][c];
   }
  }
 }
}

Matrix::Matrix(Matrix && other):
 rown{other.rown},
 coln{other.coln},
 matrix{other.matrix} {
 other.rown = 0;
 other.coln = 0;
 other.matrix = nullptr;
}

Matrix::~Matrix() {
 if (matrix != nullptr) { 
  for (int i = 0;i < rown;++i) {
   delete [] matrix[i];
  }
  delete [] matrix;
 }
}

Matrix& Matrix::operator= (const Matrix & other) {
 if (this == &other) return *this;
 rown=other.rown;
 coln=other.coln; 
 if ((rown == 0) || (coln == 0)) {
  matrix = nullptr;
 } else {
  matrix = new int*[rown];
  for (int i = 0;i < rown;++i) {
   matrix[i] = new int[coln];
  }
  for (int r = 0;r < rown;++r) {
   for (int c = 0;c < coln;++c) {
    matrix[r][c] = other.matrix[r][c];
   }
  }
 }
 return *this;
}

Matrix& Matrix::operator= (Matrix && other) {
 swap(rown,other.rown);
 swap(coln,other.coln);
 other.rown = 0;
 other.coln = 0;
 swap(matrix,other.matrix);
 return *this;
}

Matrix Matrix::operator+(const Matrix &other) const {
 if ((rown == other.rown) && (coln == other.coln)) {
   Matrix m = other;
  for(int r = 0;r < rown; ++r) {
   for(int c = 0; c < coln; ++c) {
    m.matrix[r][c] += matrix[r][c];
   }
  }
 return m;
 } else {
  Matrix m;
  return m;
 }
}

Matrix Matrix::operator*(const Matrix &other) const {
 if ((rown == other.coln) && (coln == other.rown)) {
   Matrix m{rown,other.coln};
  for(int r = 0;r < rown;++r) {
   for(int c = 0;c < other.coln;++c) {
    int sum = 0;
    for(int i = 0;i < coln;++i) {
     int pro = matrix[r][i] * other.matrix[i][c];
     sum += pro;
    }
    m.matrix[r][c] = sum;
   }
  }
  return m;
 } else {
  Matrix m;
  return m;
 }
}

int Matrix::rows() const {
 return rown;
}

int Matrix::cols() const {
 return coln;
}

void Matrix::set(int row,int col,int value) {
 if ((row >= 0) && (col >=0)) {
  matrix[row][col] = value;
 }
}

int Matrix::get(int row,int col) const {
 return matrix[row][col];
}

istream &operator >> (istream & in,Matrix & m) { 
 int row,col;
 if (cin >> row >> col) {
  if ((row >= 0) && (col >-0)) {
  Matrix newm{row,col};
  bool brk = false;
  for(int r = 0;r < row; ++r) {
   for(int c = 0;c < col; ++c) {
    int value;
    if (cin >> value) {
     newm.set(r,c,value);
    } else {
     brk = true;
     break;
    }
   }
   if (brk) {
    break;
   }
  }
 m = newm;
 }
 }
 return in;
}

ostream &operator<< (ostream & out,const Matrix &m) {
 if ((m.rows() == 0) || (m.cols() == 0)) {
  cout << "[]";
 } else {
  for(int r = 0;r < m.rows();++r) {
   for(int c = 0;c < m.cols();++c) {
     cout << setw(4) << m.get(r,c) << " ";
   } 
  cout << endl;
  }
 }
 return out;
}
