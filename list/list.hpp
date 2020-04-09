
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List { // Should extend LinearContainer<Data> and SearchableContainer<Data>

private:

  // ...

protected:

  // using LinearContainer<Data>::???;

  struct Node
  {

    // Data
    // ...

    /* ********************************************************************** */

    // Specific constructors
    // ...

    // Copy constructor
    // ...

    // Move constructor
    // ...

    /* ********************************************************************** */

    // Destructor
    // ...

    /* ********************************************************************** */

    // Comparison operators
    // ...

    /* ********************************************************************** */

    // Specific member functions

    // ...

  };

  // ...

public:

  // Default constructor
  // List() specifier;

  // Copy constructor
  // List(argument);

  // Move constructor
  // List(argument);

  /* ************************************************************************ */

  // Destructor
  // ~List() specifier;

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

  // type RemoveFromFront() specifier; // (might throw std::length_error)
  // type FrontNRemove() specifier; // (might throw std::length_error)
  // type InsertAtFront(argument) specifier; // Copy of the value
  // type InsertAtFront(argument) specifier; // Move of the value

  // type InsertAtBack(argument) specifier; // Copy of the value
  // type InsertAtBack(argument) specifier; // Move of the value

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

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

protected:

  // type MapPreOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards
  // type MapPostOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards

  // type FoldPreOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards
  // type FoldPostOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards

};

/* ************************************************************************** */

#include "list.cpp"

}

#endif
