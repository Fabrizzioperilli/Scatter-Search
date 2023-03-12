/**
 * @file FeRedispersion.h
 * @author Fabrizzio Daniell Perilli Martín
 * @brief It is a class derived from ExplorationFunction.h that implements the pure virtual method to perform the redispersion exploration function.
 * @version 0.1
 * @date 2023-03-12
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "ExplorationFunction.h"

template <class Key>
class FeRedispersion : public ExplorationFunction<Key>
{
public:
  FeRedispersion();
  unsigned operator()(const Key &, unsigned) const override;
};

/**
 * @brief Construct a new Fe Redispersion< Key>:: Fe Redispersion object
 *
 * @tparam Key
 */
template <class Key>
FeRedispersion<Key>::FeRedispersion() {}

/**
 * @brief It is a method that performs the redispersion exploration function.
 *
 * @tparam Key
 * @param k
 * @param i
 * @return unsigned
 */
template <class Key>
unsigned FeRedispersion<Key>::operator()(const Key &k, unsigned i) const
{
  srand(k);
  for (size_t j = 0; j < i; j++)
    rand();
  return rand();
}