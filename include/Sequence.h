#pragma once

template <class Key>
class Sequence{
  public:
    virtual bool Search(const Key&) const = 0;
    virtual bool Insert(const Key&) = 0;
    virtual bool IsFull() const = 0;
};