#include "ExplorationFunction.h"

template <class Key>
class FeQuadratic : public ExplorationFunction<Key>
{
public:
  FeQuadratic();
  unsigned operator()(const Key &, unsigned) const override;
};

template <class Key>
FeQuadratic<Key>::FeQuadratic() {}


template <class Key>
unsigned FeQuadratic<Key>::operator()(const Key &k, unsigned i) const
{
  return i * i;
}
