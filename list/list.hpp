
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : public LinearContainer<Data>, public SearchableContainer<Data>{ // Should extend LinearContainer<Data> and SearchableContainer<Data>

private:

  // ...

protected:

  using LinearContainer<Data>::size;

  struct Node
  {

    // Data
    Data dato;
    Node* next = nullptr;

    /* ********************************************************************** */

    // Specific constructors
    Node(Data&);

    // Copy constructor
    Node(const Node&);

    // Move constructor
    Node(Node&&);

    /* ********************************************************************** */

    // Destructor
    ~Node();

    /* ********************************************************************** */

    // Comparison operators
    bool operator==(const Node&);
    bool operator!=(const Node&);

    /* ********************************************************************** */

    // Specific member functions
    void read() const;
    void write();
    void whosNext() const;
  };

  // ...

public:

  // Default constructor
  List() = default;

  // Copy constructor
  List(const List&);

  // Move constructor
  List(List&&);

  /* ************************************************************************ */

  // Destructor
   ~List() noexcept;

  /* ************************************************************************ */

  // Copy assignment
  List &operator=(const List&);

  // Move assignment
  List &operator=(List&&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const List&) const;
  bool operator!=(const List&) const;

  /* ************************************************************************ */

  // Specific member functions

  void RemoveFromFront(); // (might throw std::length_error)
  void FrontNRemove(); // (might throw std::length_error)
  void InsertAtFront(const Data&); // Copy of the value
  void InsertAtFront(Data&&); // Move of the value

  void InsertAtBack(Data&); // Copy of the value
  void InsertAtBack(const Data&&); // Move of the value

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() noexcept; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  void Front() override; // Override LinearContainer member (might throw std::length_error)
  void Back() override; // Override LinearContainer member (might throw std::length_error)

  // type operator[](argument) specifiers; // Override LinearContainer member (might throw std::out_of_range)

  /* ************************************************************************ */

  // Specific member functions (inherited from SearchableContainer)

  using typename SearchableContainer<Data>::MapFunctor;
  void MapPreOrder(MapFunctor, void *) const override; // Override SearchableContainer member
  void MapPostOrder(MapFunctor, void *) const override; // Override SearchableContainer member

  using typename SearchableContainer<Data>::FoldFunctor;
  void FoldPreOrder(FoldFunctor, const void *, void *) override; // Override SearchableContainer member
  void FoldPostOrder(FoldFunctor, const void *, void *) override; // Override SearchableContainer member

protected:

  void MapPreOrder(MapFunctor, Node *); // Accessory function executing from one point of the list onwards
  void MapPostOrder(MapFunctor, Node *); // Accessory function executing from one point of the list onwards

  void FoldPreOrder(FoldFunctor, const void *, Node *) const; // Accessory function executing from one point of the list onwards
  void FoldPostOrder(FoldFunctor, const void*, Node *) const; // Accessory function executing from one point of the list onwards

};

/* ************************************************************************** */

#include "list.cpp"

}

#endif
