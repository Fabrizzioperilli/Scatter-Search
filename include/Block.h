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

private:
  unsigned block_size_;
  std::vector<Key> block_;
};

template <class Key>
Block<Key>::Block() : block_size_(0), block_(0) {}

template <class Key>
Block<Key>::Block(const unsigned size) : block_size_(size) {}

template <class Key>
bool Block<Key>::Search(const Key &k) const
{
  for (auto &i : block_)
    if (i == k)
      return true;
  return false;
}

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

template <class Key>
bool Block<Key>::IsFull() const
{
  return block_.size() == block_size_;
}