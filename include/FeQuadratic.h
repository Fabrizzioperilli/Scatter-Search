/**
 * @file FeQuadratic.h
 * @author Fabrizzio Daniell Perilli Martín
 * @brief It is a class derived from ExplorationFunction.h that implements the pure virtual method to perform the quadratic exploration function.
 * @version 0.1
 * @date 2023-03-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "ExplorationFunction.h"

template <class Key>
class FeQuadratic : public ExplorationFunction<Key>
{
public:
  FeQuadratic();
  unsigned operator()(const Key &, unsigned) const override;
};

/**
 * @brief Construct a new Fe Quadratic< Key>:: Fe Quadratic object
 *
 * @tparam Key
 */
template <class Key>
FeQuadratic<Key>::FeQuadratic() {}

/**
 * @brief It is a method that performs the quadratic exploration function.
 *
 * @tparam Key
 * @param k
 * @param i
 * @return unsigned
 */
template <class Key>
unsigned FeQuadratic<Key>::operator()(const Key &k, unsigned i) const
{
  return i * i;
}
