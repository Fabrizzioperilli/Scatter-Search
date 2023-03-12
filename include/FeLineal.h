/**
 * @file FeLineal.h
 * @author Fabrizzio Daniell Perilli Martín
 * @brief It is a class derived from ExplorationFunction.h that implements the pure virtual method to perform the linear exploration function.
 * @version 0.1
 * @date 2023-03-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "ExplorationFunction.h"

template <class Key>
class FeLineal : public ExplorationFunction<Key>
{
public:
  FeLineal();
  unsigned operator()(const Key &, unsigned) const override;
};

/**
 * @brief Construct a new Fe Lineal< Key>:: Fe Lineal object
 *
 * @tparam Key
 */
template <class Key>
FeLineal<Key>::FeLineal() {}

/**
 * @brief It is a method that performs the linear exploration function.
 *
 * @tparam Key
 * @param k
 * @param i
 * @return unsigned
 */
template <class Key>
unsigned FeLineal<Key>::operator()(const Key &k, unsigned i) const
{
  return i;
}