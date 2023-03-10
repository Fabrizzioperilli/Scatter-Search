#include "ExplorationFunction.h"

template <class Key>
class FeLineal : public ExplorationFunction<Key>
{
public:
  FeLineal();
  unsigned operator()(const Key &, unsigned) const override;
};

template <class Key>
FeLineal<Key>::FeLineal() {}


template <class Key>
unsigned FeLineal<Key>::operator()(const Key &k, unsigned i) const
{
  return i;
}