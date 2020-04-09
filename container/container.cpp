#include <iostream>

// Specific member functions (Container)

bool lasd::Container::Empty() const noexcept
{
    if (this->size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ulong lasd::Container::Size() const noexcept
{
    return this->size;
}

/* ************************************************************************** */

// Specific member functions (LinearContainer)

// template <typename Data>
// Data lasd::LinearContainer<Data>::Front() const{

//     if (size != 0)
//     {
        
//     }

// }
/* ************************************************************************** */

// Specific member functions (TestableContainer)

// ...

/* ************************************************************************** */

// Specific member functions (SearchableContainer)

// ...
