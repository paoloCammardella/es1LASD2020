
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd
{

/* ************************************************************************** */

template <typename Data>
class Vector
{ // Should extend LinearContainer<Data> and SearchableContainer<Data>

private:
  // ...

protected:
  // using LinearContainer<Data>::???;

  // ...

public:
  // Default constructor
  // Vector() specifier;

  // Specific constructor
  // Vector(argument); // A vector with an initial given dimension.

  // Copy constructor
  // Vector(argument);

  // Move constructor
  // Vector(argument);

  /* ************************************************************************ */

  // Destructor
  // ~Vector() specifier;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);

  // Move assignment
  // type operator=(argument);

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions

  // type Resize(argument) specifiers; // Resize the vector

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type Front() specifiers; // Override LinearContainer member
  // type Back() specifiers; // Override LinearContainer member

  // type operator[](argument) specifiers; // Override LinearContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from SearchableContainer)

  // using typename SearchableContainer<Data>::MapFunctor;
  // type MapPreOrder(arguments) specifiers; // Override SearchableContainer member
  // type MapPostOrder(arguments) specifiers; // Override SearchableContainer member

  // using typename SearchableContainer<Data>::FoldFunctor;
  // type FoldPreOrder(arguments) specifiers; // Override SearchableContainer member
  // type FoldPostOrder(arguments) specifiers; // Override SearchableContainer member
};

/* ************************************************************************** */

#include "vector.cpp"

} // namespace lasd

#endif
