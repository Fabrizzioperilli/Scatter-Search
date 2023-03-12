/**
 * @file FeDoubleDispersion.h
 * @author Fabrizzio Daniell Perilli Martin
 * @brief It is a class derived from ExplorationFunction.h that implements the pure virtual method to perform the double hash exploration function.
 * @version 0.1
 * @date 2023-03-12
 *
 * @copyright Copyright (c) 2023
 *
 */

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
/**
 * @brief Construct a new Fe Double Dispersion< Key>:: Fe Double Dispersion object
 *
 * @tparam Key
 */
template <class Key>
FeDoubleDispersion<Key>::FeDoubleDispersion() {}

/**
 * @brief Construct a new Fe Double Dispersion< Key>:: Fe Double Dispersion object
 *
 * @tparam Key
 * @param function
 */
template <class Key>
FeDoubleDispersion<Key>::FeDoubleDispersion(DispersionFunction<Key> &function)
{
  fd_ = &function;
}

/**
 * @brief It is a method that performs the double hash exploration function.
 *
 * @tparam Key
 * @param k
 * @param i
 * @return unsigned
 */
template <class Key>
unsigned FeDoubleDispersion<Key>::operator()(const Key &k, unsigned i) const
{
  return fd_->operator()(k) * i;
}