/**
 * @file FdSum.h
 * @author Fabrizzio Daniell Perilli Martín
 * @brief It is a class derived from DispertionFunction that implements the operator() for the sum function
 * @version 0.1
 * @date 2023-03-12
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "DispersionFunction.h"

template <class Key>
class FdSum : public DispersionFunction<Key>
{
public:
  FdSum(const unsigned);
  unsigned operator()(const Key &) const override;

private:
  unsigned table_size;
};

/**
 * @brief Construct a new Fd Sum< Key>:: Fd Sum object
 *
 * @tparam Key
 * @param n
 */
template <class Key>
FdSum<Key>::FdSum(const unsigned n) : table_size(n) {}

/**
 * @brief It is the operator() that performs the sum function
 *
 * @tparam Key
 * @param k
 * @return unsigned
 */
template <class Key>
unsigned FdSum<Key>::operator()(const Key &k) const
{
  unsigned sum = 0;
  Key temp = k;
  while (temp > 0)
  {
    sum += temp % 10;
    temp /= 10;
  }
  return sum % table_size;
}
