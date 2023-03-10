#include "ExplorationFunction.h"
#include "DispersionFunction.h"

template <class Key>
class FeDoubleDispersion : public ExplorationFunction<Key>
{
public:
  FeDoubleDispersion();
  FeDoubleDispersion(DispersionFunction<Key> &);
  unsigned operator()(const Key &, unsigned) const override;

private:
  DispersionFunction<Key> *fd_;
};

template <class Key>
FeDoubleDispersion<Key>::FeDoubleDispersion() {}

template <class Key>
FeDoubleDispersion<Key>::FeDoubleDispersion(DispersionFunction<Key> &function){
  fd_ = &function;
}

template <class Key>
unsigned FeDoubleDispersion<Key>::operator()(const Key &k, unsigned i) const
{
  return fd_->operator()(k) * i;
}