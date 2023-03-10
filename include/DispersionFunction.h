#pragma once

template <class Key>
class DispersionFunction
{
public:
  virtual unsigned operator()(const Key&) const = 0;
};