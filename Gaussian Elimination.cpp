//eponari19
#include <iostream>
#include "matrixClass.h"
using namespace std;

int main() {
  cout<<"Enter the size of the square matrix: \n";
  int size;
  cin>>size;
  matrix myMatrix(size);
  myMatrix.solve_matrix();
}
