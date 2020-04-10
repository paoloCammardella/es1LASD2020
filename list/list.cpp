
#include <stdexcept>
#include "list.hpp"

/* ************************************************************************** */
//Destructor
template <typename Data>
lasd::List<Data>::Node::~Node(){
    dato = 0;
    next = nullptr;
}

//specifier constructor
template <typename Data>
lasd::List<Data>::Node::Node(Data& val){
    dato = val;
    next = nullptr;
}

//copy constructor
template <typename Data>
lasd::List<Data>::Node::Node(const Node& n1){
    dato = n1.dato;
    next = n1.next;
}

//move constructor
template <typename Data>
lasd::List<Data>::Node::Node(Node&& n1){
    std::swap(dato, n1.dato);
    std::swap(next, n1.next);
    delete [] n1;
}

//operator ==
template <typename Data>
bool lasd::List<Data>::Node::operator==(const Node& n1){
    if (dato == n1.dato)
    {
        return true;
    }
    else
    {
        return false;
    }
 }

//operator !=
template <typename Data>
bool lasd::List<Data>::Node::operator!=(const Node& n1){
    return !operator==();
}

template <typename Data>
void lasd::List<Data>::InsertAtFront(const Data& val){

}