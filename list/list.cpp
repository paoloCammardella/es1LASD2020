
#include <stdexcept>
#include "list.hpp"

/* ************************************************************************** */
//Destructor
template <typename Data>
lasd::List<Data>::Node::~Node()
{
    dato = 0;
    next = nullptr;
}

//specifier constructor
template <typename Data>
lasd::List<Data>::Node::Node(Data &val)
{
    dato = val;
    next = nullptr;
}

//copy constructor
template <typename Data>
lasd::List<Data>::Node::Node(const Node &n1)
{
    dato = n1.dato;
    next = n1.next;
}

//move constructor
template <typename Data>
lasd::List<Data>::Node::Node(Node &&n1)
{
    std::swap(dato, n1.dato);
    std::swap(next, n1.next);
    delete[] n1;
}

//operator ==
template <typename Data>
bool lasd::List<Data>::Node::operator==(const Node &n1)
{
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
bool lasd::List<Data>::Node::operator!=(const Node &n1)
{
    return !operator==();
}

//List Copy Constructor
template <typename Data>
lasd::List<Data>::List(const List<Data> &list)
{
    if (list.head != nullptr)
    {
        size = list.size;
        Node *curr = list.head;
        head = new Node(curr->data);
        Node *tmp = head;
        Node *succ = curr->next;

        while (curr->next != nullptr)
        {
            tmp->next = new Node(succ->data);
            curr = curr->next;
            succ = succ->next;
            tmp = tmp->next;
        }

        delete curr;
        delete tmp;
        delete succ;
    }
}

//List Move Constructor
template <typename Data>
lasd::List<Data>::List(List<Data> &&list)
{
    std::swap(this->size, list.size);
    std::swap(head, list.head);
}

//destructor
template <typename Data>
lasd::List<Data>::~List() noexcept
{
    if (head != nullptr)
    {
        Node *tmp = head;
        while (head->next != nullptr)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        this->size = 0;
    }
}

//copy assignment
template <typename Data>
lasd::List<Data> &lasd::List<Data>::operator=(const List<Data> &list)
{
    size = list.size;
    head = list.head;
}

//move assignment
template <typename Data>
lasd::List<Data> &lasd::List<Data>::operator=(List<Data> &&list)
{
    std::swap(size, list.size);
    std::swap(head, list.head);
}

//remove
template <typename Data>
void lasd::List<Data>::RemoveFromFront()
{
    if (size == 0)
    {
        throw std::length_error("Lista vuota");
    }
    else
    {
        Node *tmp = head;
        head = head->next;
        size--;
        delete tmp;
    }
}

//Front and remove
template <typename Data>
void lasd::List<Data>::FrontNRemove()
{
    if (size == 0)
    {
        throw std::length_error("Lista vuota");
    }
    else
    {
        std::cout << head->dato << std::endl;
        Node *tmp = head;
        head = head->next;
        size--;
        delete tmp;
    }
}

//insert at front by copy
template <typename Data>
void lasd::List<Data>::InsertAtFront(const Data &val)
{
    if (size == 0)
    {
        Node *head = new Node(val);
        head->next = nullptr;
    }
    else
    {
        Node *tmp = new Node(val);
        head = tmp->next;
        head = tmp;
    }

    size++;
}

//insert at front by move
template <typename Data>
void lasd::List<Data>::InsertAtFront(Data &&val)
{
    Node *tmp = new Node();
    std::swap(tmp->dato, val);
    head = head->next;
    head = tmp;
    size++;
}

//insert at back by copy
template <typename Data>
void lasd::List<Data>::InsertAtBack(const Data &val)
{
    Node *sup = new Node(val);
    Node *tmp = head;
    if (size == 0)
    {
        head = sup;
    }
    else
    {
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = sup;
    }
    size++;
}

//insert at back by move
template <typename Data>
void lasd::List<Data>::InsertAtBack(Data &&val)
{
      Node *sup = new Node(val);
    Node *tmp = head;
    if (size == 0)
    {
        head = sup;
    }
    else
    {
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        std::swap(tmp->next, sup);
    }
    size++;
}

//Clear method
template <typename Data>
void lasd::List<Data>::Clear() noexcept
{
    if (head != nullptr)
    {
        Node *tmp = head;
        while (head->next != nullptr)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        size = 0;
    }
}

//Front method
template <typename Data>
Data &lasd::List<Data>::Front() const
{
    if (size == 0)
    {
        throw std::length_error("Empty List");
    }
    else
    {
        return head->dato;
    }
}

//Back method
template <typename Data>
Data &lasd::List<Data>::Back() const
{
    if (size == 0)
    {
        throw std::length_error("Empty List");
    }
    else
    {
        Node *tmp = head;
        while (tmp && tmp->next)
        {
            tmp = tmp->next;
        }
        return tmp->dato;
    }
}

template <typename Data>
Data &lasd::List<Data>::operator[](const ulong i) const
{

    Node *tmp = head;
    ulong ind = 0;

    if (size < i)
    {
        throw std::length_error("index out of bound");
    }
    else
    {
        while (ind < i + 1)
        {
            tmp = tmp->next;
            ind++;
        }
        return tmp->dato;
    }
}

//MapPreOrder
template <typename Data>
void lasd::List<Data>::MapPreOrder(MapFunctor mf, void *par)
{
    MapPreOrder(mf, par, head);
}

//MapPostOrder
template <typename Data>
void lasd::List<Data>::MapPostOrder(MapFunctor mf, void *par)
{
    MapPostOrder(mf, par, head);
}

//FoldPreOrder
template <typename Data>
void lasd::List<Data>::FoldPreOrder(FoldFunctor ff, const void *acc, void *par) const
{
    FoldPreOrder(ff, acc, par, head);
}

//FoldPostOrder
template <typename Data>
void lasd::List<Data>::FoldPostOrder(FoldFunctor ff, const void *acc, void *par) const
{
    FoldPostOrder(ff, acc, par, head);
}

//MapPreOrder protected
template <typename Data>
void lasd::List<Data>::MapPreOrder(MapFunctor mf, void *par, Node *nodo)
{
    while (nodo != nullptr)
    {
        mf(nodo->dato, nodo);
        nodo = nodo->next;
    }
}

//MapPostOreder
template <typename Data>
void lasd::List<Data>::MapPostOrder(MapFunctor mf, void *par, Node *nodo)
{

}

template <typename Data>
void lasd::List<Data>::FoldPreOrder(FoldFunctor ff, const void *acc, void *par, Node *nodo) const
{
    while(nodo != nullptr){
        ff(nodo->dato, acc, par);
        nodo = nodo->next;
    }
}

template <typename Data>
void lasd::List<Data>::FoldPostOrder(FoldFunctor ff, const void *acc, void *par, Node *nodo) const
{
}
