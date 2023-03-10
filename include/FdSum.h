#include "DispersionFunction.h"

template <class Key>
class FdSum : public DispersionFunction<Key>
{
public:
  FdSum(const unsigned);
  unsigned operator()(const Key &) const override;

private:
  unsigned table_size;
};

template <class Key>
FdSum<Key>::FdSum(const unsigned n) : table_size(n) {}

template <class Key>
unsigned FdSum<Key>::operator()(const Key &k) const
{
  unsigned sum = 0;
  Key temp = k;
  while (temp > 0)
  {
    sum += temp % 10;
    temp /= 10;
  }
  return sum % table_size;
}
