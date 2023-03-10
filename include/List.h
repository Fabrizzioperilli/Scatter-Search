#include "../include/Sequence.h"
#include <list>

template <class Key>
class List : public Sequence<Key>
{
public:
  List();
  bool Search(const Key &) const override;
  bool Insert(const Key &) override;
  bool IsFull() const override;

private:
  std::list<Key> list_;
};

template <class Key>
List<Key>::List() {}

template <class Key>
bool List<Key>::Search(const Key &k) const
{
  for (auto &i : list_)
    if (i == k)
      return true;
  return false;
}

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

template <class Key>
bool List<Key>::IsFull() const
{
  return false;
}