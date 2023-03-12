/**
 * @file FdModule.h
 * @author Fabrizzio Daniell Perilli Martín
 * @brief It is a class derived from DispertionFunction that implements the operator() for the module function
 * @version 0.1
 * @date 2023-03-12
 *
 * @copyright Copyright (c) 2023
 *
 */

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

/**
 * @brief Construct a new Fd Module< Key>:: Fd Module object
 *
 * @tparam Key
 * @param n
 */
template <class Key>
FdModule<Key>::FdModule(const unsigned n) : table_size(n) {}

/**
 * @brief It is the operator() that performs the module function
 *
 * @tparam Key
 * @param k
 * @return unsigned
 */
template <class Key>
unsigned FdModule<Key>::operator()(const Key &k) const
{
  return k % table_size;
}