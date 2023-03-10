#include <iostream>
#include "../include/FdModule.h"
#include "../include/FdSum.h"
#include "../include/FdRandom.h"
#include "../include/DispersionFunction.h"
#include "../include/ExplorationFunction.h"
#include "../include/FeLineal.h"
#include "../include/FeQuadratic.h"
#include "../include/FeDoubleDispersion.h"
#include "../include/FeRedispersion.h"

int main()
{
  int table_size = 10;
  DispersionFunction<int> *fd;
  int op = 3;
  switch (op)
  {
  case 1:
    fd = new FdModule<int>(table_size);
    break;
  case 2:
    fd = new FdSum<int>(table_size);
    break;
  case 3:
    fd = new FdRandom<int>(table_size);
    break;
  default:
    break;
  }

  ExplorationFunction<int> *fe;
  int op_ex = 4;
  switch (op_ex)
  {
  case 1:
    fe = new FeLineal<int>();
    break;
  case 2:
    fe = new FeQuadratic<int>();
    break;
  case 3:
    fe = new FeDoubleDispersion<int>(*fd);
    break;
  case 4:
    fe = new FeRedispersion<int>();
    break;
  default:
    break;
  }

  std::cout << "Función de dispersión: " << fd->operator()(1234) << std::endl;
  std::cout << "Función de exploración: " << fe->operator()(1234, 5) << std::endl;

  return 0;
}