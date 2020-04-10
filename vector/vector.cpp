
#include <stdexcept>

/* ************************************************************************** */

//Constructor with given dimension
template <typename Data>
lasd::Vector<Data>::Vector(ulong dimension)
{
    size = dimension;
    items = new Data[size];
}

//Copy Constructor
template <typename Data>
lasd::Vector<Data>::Vector(const Vector<Data> &vector2)
{
    items = new Data[vector2.size];
    std::copy(vector2.items, vector2.items + vector2.size, items);
    size = vector2.size;
}

//Move Constructor
template <typename Data>
lasd::Vector<Data>::Vector(Vector<Data> &&vector2)
{
    std::swap(items, vector2.items);
    std::swap(size, vector2.size);
    
}

//Destructor
template <typename Data>
lasd::Vector<Data>::~Vector()
{
    for (ulong i = 0; i < size; i++)
    {
        items[i] = 0;
    }
    delete[] items;
}

//copy assignment
template <typename Data>
lasd::Vector<Data> lasd::Vector<Data>::operator=(const Vector<Data> &v)
{

    Vector<Data> vTmp = new Vector<Data>(v);
    std::swap(*vTmp, *this);
    delete vTmp;

    return *this;
}

//move assignment
template <typename Data>
lasd::Vector<Data> lasd::Vector<Data>::operator=(Vector<Data> &&v)
{
    std::swap(items, v.items);
    std::swap(size, v.size);
    delete v;

    return *this;
}

//comparison operators

//Equality operator
template <typename Data>
bool lasd::Vector<Data>::operator==(const Vector &vector2)
{

    bool equal = true;
    ulong i = 0;

    if (size == vector2.size)
    {
        while (equal && i < size)
        {
            if (items[i] != vector2.items[i])
            {
                equal = false;
            }
            else
            {
                i++;
            }
        }
    }
    else
    {
        equal = false;
    }
    return equal;
}

template <typename Data>
bool lasd::Vector<Data>::operator!=(const Vector &vector2)
{

    bool equal = false;
    ulong i = 0;

    if (size == vector2.size)
    {
        while (!equal && i < size)
        {
            if (items[i] != vector2.items[i] && i < size)
            {
                equal = true;
            }
            i++;
        }
    }
    else
    {
        equal = true;
    }
    return equal;
}

//resize method
template <typename Data>
void lasd::Vector<Data>::Resize(ulong size)
{

    Vector v2;
    v2.size = size;
    for (ulong i = 0; i < this.size; i++)
    {
        v2[i] = this[i];
    }
    this = v2;
    ~v2();
}

//Clear method
template <typename Data>
void lasd::Vector<Data>::Clear() noexcept
{
    for (ulong i = 0; i < size; i++)
    {
        items[i] = 0;
    }
    items = nullptr;
    size = 0;
}

//front method
template <typename Data>
Data &lasd::Vector<Data>::Front() const
{
    if (size != 0)
    {
        return items[0];
    }
    else
    {
        throw std::length_error("length error");
    }
}

//back method
template <typename Data>
Data &lasd::Vector<Data>::Back() const
{
    if (size != 0)
    {
        return items[size];
    }
    else
    {
        throw std::length_error("length error");
    }
}

//operator []
template <typename Data>
Data &lasd::Vector<Data>::operator[](const ulong i)
{
    if (i < size)
    {
        return items[i];
    }
    else if (i > size)
    {
        throw std::out_of_range("index out of range");
    }
    else
    {
        throw std::length_error("length error");
    }
}

//Pre order map
template <typename Data>
void lasd::Vector<Data>::MapPreOrder(MapFunctor f, void *par)
{
    for (ulong i = 0; i < size; i++)
    {
        f(items[i], par);
    }
}

//Post order map
template <typename Data>
void lasd::Vector<Data>::MapPostOrder(MapFunctor f, void *par)
{
    for (ulong i = size - 1; i > -1; i--)
    {
        f(items[i], par);
    }
}

//Pre order fold
template <typename Data>
void lasd::Vector<Data>::FoldPreOrder(FoldFunctor f, const void *acc, void *par) const
{
    for (ulong i = 0; i < size; i++)
    {
        f(items[i], acc, par);
    }
}

//Post order fold
template <typename Data>
void lasd::Vector<Data>::FoldPostOrder(FoldFunctor f, const void *acc, void *par) const
{
    for (ulong i = size - 1; i > -1; i--)
    {
        f(items[i], acc, par);
    }
}
