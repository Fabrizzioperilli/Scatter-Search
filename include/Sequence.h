#pragma once
#include <iostream>

template <class Key>
class Sequence{
  public:
    virtual bool Search(const Key&) const = 0;
    virtual bool Insert(const Key&) = 0;
    virtual bool IsFull() const = 0;
    virtual std::ostream& Write(std::ostream& os) const = 0;
};