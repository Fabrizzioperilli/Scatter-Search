/**
 * @file Sequence.h
 * @author Fabrizzio Daniell Perilli Martín
 * @brief Sequence is an abstract class that contains the pure virtual methods that will be implemented in the derived classes.
 * @version 0.1
 * @date 2023-03-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once
#include <iostream>

template <class Key>
class Sequence
{
public:
  virtual bool Search(const Key &) const = 0;
  virtual bool Insert(const Key &) = 0;
  virtual bool IsFull() const = 0;
  virtual std::ostream &Write(std::ostream &os) const = 0;
};