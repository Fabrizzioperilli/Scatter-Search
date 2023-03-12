#include <cstdlib>
/**
 * @file FdRandom.h
 * @author Fabrizzio Daniell Perilli Martín
 * @brief It is a class derived from DispertionFunction that implements the operator() for the pseudorandom function
 * @version 0.1
 * @date 2023-03-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "DispersionFunction.h"

template <class Key>
class FdRandom : public DispersionFunction<Key>
{
public:
  FdRandom(const unsigned);
  unsigned operator()(const Key &) const override;

private:
  unsigned table_size;
};

/**
 * @brief Construct a new Fd Random< Key>:: Fd Random object
 *
 * @tparam Key
 * @param n
 */
template <class Key>
FdRandom<Key>::FdRandom(const unsigned n) : table_size(n) {}

/**
 * @brief It is the operator() that performs the pseudorandom function
 *
 * @tparam Key
 * @param k
 * @return unsigned
 */
template <class Key>
unsigned FdRandom<Key>::operator()(const Key &k) const
{
  srand(k);
  return rand() % table_size;
}