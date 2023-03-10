#include <cstdlib>
#include "DispersionFunction.h"

template <class Key>
class FdRandom : public DispersionFunction<Key>
{
public:
  FdRandom(const unsigned);
  unsigned operator()(const Key &) const override;

private:
  unsigned table_size;
};

template <class Key>
FdRandom<Key>::FdRandom(const unsigned n) : table_size(n) {}

template <class Key>
unsigned FdRandom<Key>::operator()(const Key &k) const
{
  srand(k);
  return rand() % table_size;
}