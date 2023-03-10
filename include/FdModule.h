#include "DispersionFunction.h"

template <class Key>
class FdModule : public DispersionFunction<Key>
{
public:
  FdModule(const unsigned);
  unsigned operator()(const Key &) const override;

private:
  unsigned table_size;
};

template <class Key>
FdModule<Key>::FdModule(const unsigned n) : table_size(n) {}

template <class Key>
unsigned FdModule<Key>::operator()(const Key &k) const
{
  return k % table_size;
}