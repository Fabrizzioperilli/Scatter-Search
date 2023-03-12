/**
 * @file List.h
 * @author Fabrizzio Daniell Perilli Martín
 * @brief This is a sequence derived class that contains a linked list where the keys will be stored when using open dispersion
 * @version 0.1
 * @date 2023-03-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../include/Sequence.h"
#include <list>
#include <iostream>

template <class Key>
class List : public Sequence<Key>
{
public:
  List();
  bool Search(const Key &) const override;
  bool Insert(const Key &) override;
  bool IsFull() const override;
  std::ostream &Write(std::ostream &) const override;

private:
  std::list<Key> list_;
};

/**
 * @brief Construct a new List< Key>:: List object
 *
 * @tparam Key
 */
template <class Key>
List<Key>::List() {}

/**
 * @brief Search a key in the list
 *
 * @tparam Key
 * @param k
 * @return true
 * @return false
 */
template <class Key>
bool List<Key>::Search(const Key &k) const
{
  for (auto &i : list_)
    if (i == k)
      return true;
  return false;
}

/**
 * @brief Insert a key in the list
 *
 * @tparam Key
 * @param k
 * @return true
 * @return false
 */
template <class Key>
bool List<Key>::Insert(const Key &k)
{
  if (IsFull())
    return false;
  if (Search(k))
    return false;
  list_.push_back(k);
  return true;
}

/**
 * @brief Check if the list is full
 *
 * @tparam Key
 * @return true
 * @return false
 */
template <class Key>
bool List<Key>::IsFull() const
{
  return false;
}

/**
 * @brief Write the list in the output stream
 *
 * @tparam Key
 * @param os
 * @return std::ostream&
 */
template <class Key>
std::ostream &List<Key>::Write(std::ostream &os) const
{
  for (auto &i : list_)
    os << i << " ";
  return os;
}