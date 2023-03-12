/**
 * @file Block.h
 * @author Fabrizzio Daniell Perilli Martín
 * @brief This is a sequence-derived class that contains a vector where the keys will be stored when closed dispersion is used
 * @version 0.1
 * @date 2023-03-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "Sequence.h"
#include <vector>

template <class Key>
class Block : public Sequence<Key>
{
public:
  Block();
  Block(const unsigned);
  bool Search(const Key &) const override;
  bool Insert(const Key &) override;
  bool IsFull() const override;
  std::ostream &Write(std::ostream &) const override;

private:
  unsigned block_size_;
  std::vector<Key> block_;
};

/**
 * @brief Construct a new Block< Key>:: Block object
 *
 * @tparam Key
 */
template <class Key>
Block<Key>::Block() : block_size_(0), block_(0) {}

/**
 * @brief Construct a new Block< Key>:: Block object
 *
 * @tparam Key
 * @param size
 */
template <class Key>
Block<Key>::Block(const unsigned size) : block_size_(size) {}

/**
 * @brief Search a key in the block
 *
 * @tparam Key
 * @param k
 * @return true
 * @return false
 */
template <class Key>
bool Block<Key>::Search(const Key &k) const
{
  for (auto &i : block_)
    if (i == k)
      return true;
  return false;
}

/**
 * @brief Insert a key in the block
 *
 * @tparam Key
 * @param k
 * @return true
 * @return false
 */
template <class Key>
bool Block<Key>::Insert(const Key &k)
{
  if (IsFull())
    return false;
  if (Search(k))
    return false;
  block_.push_back(k);
  return true;
}

/**
 * @brief Check if the block is full
 *
 * @tparam Key
 * @return true
 * @return false
 */
template <class Key>
bool Block<Key>::IsFull() const
{
  return block_.size() == block_size_;
}

/**
 * @brief Write the block in the output stream
 *
 * @tparam Key
 * @param os
 * @return std::ostream&
 */
template <class Key>
std::ostream &Block<Key>::Write(std::ostream &os) const
{
  for (auto &i : block_)
    os << i << " ";
  return os;
}