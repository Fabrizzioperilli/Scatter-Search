#include <iostream>
#include "../include/FdModule.h"
#include "../include/FdSum.h"
#include "../include/FdRandom.h"
#include "../include/FeLineal.h"
#include "../include/FeQuadratic.h"
#include "../include/FeDoubleDispersion.h"
#include "../include/FeRedispersion.h"
#include "../include/HashTable.h"

int main()
{
  unsigned table_size = 7;
  DispersionFunction<int> *fd;
  int op = 1;
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

  HashTable<int> *hash_table;
  int op_seq = 2;
  if (op_seq == 1)
    hash_table = new HashTable<int>(table_size, fd);
  else if (op_seq == 2)
  {
    unsigned block_size = 3;
    ExplorationFunction<int> *fe;
    int op_ex = 1;
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
    hash_table = new HashTable<int>(table_size, fd, fe, block_size);
  }

  int n1 = 10;
  int n2 = 15;
  int n3 = 13;
  int n4 = 12;
  int n5 = 20;
  int n6 = 21;
  int n7 = 22;
  int n8 = 10;
  int n9 = 1;
  int n10 = 8;
  int n11 = 29;
  int n12 = 30;
  int n13 = 51;

  std::cout << ".....HashTable......" << std::endl;
  
  std::cout << "Insert n1 = " << n1 << " --> ";
  hash_table->Insert(n1);

  std::cout << "Insert n2 = " << n2 << " --> ";
  hash_table->Insert(n2);

  std::cout << "Insert n3 = " << n3 << " --> ";
  hash_table->Insert(n3);

  std::cout << "Search n4 = " << n4 << " --> ";
  hash_table->Search(n4);

  std::cout << "Search n2 = " << n2 << " --> ";
  hash_table->Search(n2);

  std::cout << "Insert n1 = " << n1 << " --> ";
  hash_table->Insert(n1);

  std::cout << "Insert n4 = " << n4 << " --> ";
  hash_table->Insert(n4);

  std::cout << "Insert n5 = " << n5 << " --> ";
  hash_table->Insert(n5);

  std::cout << "Insert n6 = " << n6 << " --> ";
  hash_table->Insert(n6);

  std::cout << "Insert n7 = " << n7 << " --> ";
  hash_table->Insert(n7);

  std::cout << "Insert n8 = " << n8 << " --> ";
  hash_table->Insert(n8);

  std::cout << "Insert n9 = " << n9 << " --> ";
  hash_table->Insert(n9);
  
  std::cout << "Insert n10 = " << n10 << " --> ";
  hash_table->Insert(n10);

  std::cout << "Search n10 = " << n10 << " --> ";
  hash_table->Search(n10);

  std::cout << "Insert n11 = " << n11 << " --> ";
  hash_table->Insert(n11);

  std::cout << "Insert n12 = " << n12 << " --> ";
  hash_table->Insert(n12);

  std::cout << "Insert n13 = " << n13 << " --> ";
  hash_table->Insert(n13);

  return 0;
}