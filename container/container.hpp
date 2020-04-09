
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <functional>

namespace lasd
{

/* ************************************************************************** */

class Container
{

private:
  //...

protected:
  ulong size;

public:
  // Destructor
  virtual ~Container() = 0;

  /* ************************************************************************ */

  // Copy assignment
  virtual Container& operator=(const Container&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  virtual Container& operator=(Container&&) = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual Container& operator==(const Container&) = 0; // Comparison of abstract types might not be possible.
  virtual Container& operator!=(const Container&) = 0; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  //type Empty() specifiers;
  virtual bool Empty() const noexcept;

  //type Size() specifiers;
  virtual ulong Size() const noexcept;

  // type Clear() specifiers;
  virtual void Clear() = 0;
};

/* ************************************************************************** */

template <typename Data>
class LinearContainer : virtual Container
{ // Should extend Container

private:
protected:
public:
  // Destructor
  ~LinearContainer();

  /* ************************************************************************ */

  // Copy assignment
  virtual LinearContainer& operator=(const LinearContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  virtual LinearContainer& operator=(LinearContainer&&) = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual LinearContainer& operator==(const LinearContainer&) = delete; // Comparison of abstract types might not be possible.
  virtual LinearContainer& operator!=(const LinearContainer&) = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual Data Front() const;
  virtual Data Back() const;

  virtual Data operator[](const ulong) = 0;
};

/* ************************************************************************** */

template <typename Data>
class TestableContainer : virtual Container
{ // Should extend Container

private:
protected:
public:
  // Destructor
  // ~TestableContainer() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // type Exists(argument) specifiers;
};

/* ************************************************************************** */

template <typename Data>
class SearchableContainer : Container
{ // Should extend TestableContainer<Data>

private:
protected:
public:
  // Destructor
  // ~SearchableContainer() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // typedef void (*MapFunctor)(Data&, void*);
  // typedef std::function<void(Data&, void*)> MapFunctor;
  // type MapPreOrder(arguments) specifiers;
  // type MapPostOrder(arguments) specifiers;

  // typedef void (*FoldFunctor)(const Data&, const void*, void*);
  // typedef std::function<void(const Data&, const void*, void*) noexcept> FoldFunctor;
  // type FoldPreOrder(arguments) specifiers;
  // type FoldPostOrder(arguments) specifiers;

  // type Exists(argument) specifiers; // Override TestableContainer member
};

/* ************************************************************************** */

#include "container.cpp"

} // namespace lasd

#endif
