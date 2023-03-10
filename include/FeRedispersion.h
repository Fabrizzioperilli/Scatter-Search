#include "ExplorationFunction.h"

template <class Key>
class FeRedispersion : public ExplorationFunction<Key>
{
public:
  FeRedispersion();
  unsigned operator()(const Key &, unsigned) const override;
};

template <class Key>
FeRedispersion<Key>::FeRedispersion() {}

template <class Key>
unsigned FeRedispersion<Key>::operator()(const Key &k, unsigned i) const
{
  srand(k);
  for (size_t j = 0; j < i; j++)
    rand();
  return rand();
}