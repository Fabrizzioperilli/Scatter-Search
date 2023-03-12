/**
 * @file ExplorationFunction.h
 * @author Fabrizzio Daniell Perilli Martín
 * @brief It is an abstract class, it has a pure virtual method that is the overload of the operator() that will be implemented in the derived classes.
 * @version 0.1
 * @date 2023-03-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

template <class Key>
class ExplorationFunction
{
public:
  virtual unsigned operator()(const Key &, unsigned) const = 0;
};