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
#include "../include/Sequence.h"
#include "../include/List.h"
#include "../include/Block.h"


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

  Sequence<int> *seq;
  int op_seq = 2;
  switch (op_seq)
  {
  case 1:
    std::cout << "--Dispesión Abierta--" << std::endl;
    seq = new List<int>();
    break;
  case 2:
    std::cout << "--Dispesión Cerrada--" << std::endl;
    seq = new Block<int>(4);
    break;
  default:
    break;
  }

  unsigned n1 = 10;
  unsigned n2 = 20;
  unsigned n3 = 30;
  unsigned n4 = 40;

  std::cout << "Insert n1 = " << n1 << "-->";
  (seq->Insert(n1)) ? std::cout << " true " << std::endl : std::cout << " false " << std::endl;
  
  std::cout << "Insert n2 = " << n2 << "-->";
  (seq->Insert(n2)) ? std::cout << " true " << std::endl : std::cout << " false " << std::endl;

  std::cout << "Insert n3 = " << n3 << "-->";
  (seq->Insert(n3)) ? std::cout << " true " << std::endl : std::cout << " false " << std::endl;
  
  std::cout << "Search n4 = " << n4 << "-->";
  (seq->Search(n4)) ? std::cout << " true " << std::endl : std::cout << " false " << std::endl;

  std::cout << "Search n2 = " << n2 << "-->";
  (seq->Search(n2)) ? std::cout << " true " << std::endl : std::cout << " false " << std::endl;
 
  std::cout << "Insert n1 = " << n1 << "-->";
  (seq->Insert(n1)) ? std::cout << " true " << std::endl : std::cout << " false " << std::endl;
  
  std::cout << "Is Full -->";
  (seq->IsFull()) ? std::cout << " true " << std::endl : std::cout << " false " << std::endl;

  std::cout << "Insert n4 = " << n4 << "-->";
  (seq->Insert(n4)) ? std::cout << " true " << std::endl : std::cout << " false " << std::endl;

  std::cout << "Is Full -->";
  (seq->IsFull()) ? std::cout << " true " << std::endl : std::cout << " false " << std::endl;



  std::cout << "Función de dispersión: " << fd->operator()(1234) << std::endl;
  std::cout << "Función de exploración: " << fe->operator()(1234, 5) << std::endl;

  return 0;
}