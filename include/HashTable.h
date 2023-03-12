#pragma once
#include "DispersionFunction.h"
#include "ExplorationFunction.h"
#include "Sequence.h"
#include "List.h"
#include "Block.h"
#include <iostream>
#include <vector>

template <class Key>
class HashTable;

template <class Key>
std::ostream& operator<<(std::ostream&, const HashTable<Key>&);


template <class Key>
class HashTable
{
public:
  HashTable();
  HashTable(unsigned, DispersionFunction<Key> *, ExplorationFunction<Key> * = nullptr, unsigned = 0);
  ~HashTable();
  bool Insert(const Key &) const;
  bool Search(const Key &) const;
  std::ostream& Write(std::ostream&) const;
  friend std::ostream& operator<< <Key>(std::ostream&, const HashTable<Key>&);
private:
  DispersionFunction<Key> *fd_;
  ExplorationFunction<Key> *fe_;
  unsigned table_size_;
  std::vector<Sequence<Key> *> table_;
  unsigned block_size_;
};

template <class Key>
HashTable<Key>::HashTable() {}

template <class Key>
HashTable<Key>::HashTable(unsigned table_size, DispersionFunction<Key> *fd, ExplorationFunction<Key> *fe, unsigned block_size)
{
  table_size_ = table_size;
  block_size_ = block_size;
  fd_ = fd;
  fe_ = fe;

  for (size_t i = 0; i < table_size_; i++)
  {
    if (fe_ == nullptr)
      table_.push_back(new List<Key>());
    else
      table_.push_back(new Block<Key>(block_size_));
  }
}

template <class Key>
HashTable<Key>::~HashTable()
{
  for (size_t i = 0; i < table_size_; i++)
    delete table_[i];
}

template <class Key>
bool HashTable<Key>::Insert(const Key &k) const
{
  unsigned index = fd_->operator()(k);

  if (fe_ == nullptr)
  {
    if (table_[index]->Insert(k))
    {
      std::cout << "Key inserted in position: " << index << std::endl;
      return true;
    }
    else
    {
      std::cout << "Key already exists" << std::endl;
      return false;
    }
  }
  else
  {
    for (size_t i = 0; i < table_size_; ++i)
    {
      unsigned exploration_index = (index + fe_->operator()(k, i)) % table_size_;
      if (table_[exploration_index]->Insert(k))
      {
        std::cout << "Key inserted in position: " << exploration_index << std::endl;
        return true;
      }
      else if (table_[exploration_index]->IsFull())
        continue;
      else
      {
        std::cout << "Key already exists" << std::endl;
        return false;
      }
    }
  }
  std::cout << "Key not inserted table is full" << std::endl;
  return false;
}

template <class Key>
bool HashTable<Key>::Search(const Key &k) const
{
  unsigned index = fd_->operator()(k);

  if (fe_ == nullptr)
  {
    if (table_[index]->Search(k))
    {
      std::cout << "Key found in position: " << index << std::endl;
      return true;
    }
    else
    {
      std::cout << "Key not found" << std::endl;
      return false;
    }
  }
  else
  {
    for (size_t i = 0; i < table_size_; ++i)
    {
      unsigned exploration_index = (index + fe_->operator()(k, i)) % table_size_;
      if (table_[exploration_index]->Search(k))
      {
        std::cout << "Key found in position: " << exploration_index << std::endl;
        return true;
      }
      else if (table_[exploration_index]->IsFull())
        continue;
      else
      {
        std::cout << "Key not found" << std::endl;
        return false;
      }
    }
  }
  return false;
}

template <class Key>
std::ostream& HashTable<Key>::Write(std::ostream& os) const
{
  for (size_t i = 0; i < table_size_; i++)
  {
    os << "\ni: " << i << " --> ";
    table_[i]->Write(os);
  }
  
  return os;
}

template <class Key>
std::ostream& operator<<(std::ostream& os, const HashTable<Key>& ht)
{
  return ht.Write(os);
}