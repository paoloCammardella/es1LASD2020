
#ifndef VECTOR_HPP
#define VECTOR_HPP


/* ************************************************************************** */

  #include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector : public LinearContainer<Data>, public SearchableContainer<Data>{ // Should extend LinearContainer<Data> and SearchableContainer<Data>

private:

  // ...

protected:

  using SearchableContainer<Data>::size;
  Data* vector; 
public:

  // Default constructor
  Vector() = default;

  // Specific constructor
  Vector(const ulong); // A vector with an initial given dimension.

  // Copy constructor
  Vector(const Vector&);

  // Move constructor
  Vector(Vector&&);

  /* ************************************************************************ */

  // Destructor
  ~Vector();

  /* ************************************************************************ */

  // Copy assignment
  Vector operator=(const Vector&);

  // Move assignment
  Vector operator=(Vector&&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Vector&);
  bool operator!=(const Vector&);

  /* ************************************************************************ */

  // Specific member functions

  void Resize(ulong); // Resize the vector

  /* ************************************************************************ */

  // Spectypeific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type Front() specifiers; // Override LinearContainer member (might throw std::length_error)
  // type Back() specifiers; // Override LinearContainer member (might throw std::length_error)

  // type operator[](argument) specifiers; // Override LinearContainer member (might throw std::out_of_range)

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

}

#endif
