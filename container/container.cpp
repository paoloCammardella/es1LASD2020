#include <iostream>

// Specific member functions (Container)
bool lasd::Container::Empty() const noexcept
{
    return size == 0;
}

unsigned long lasd::Container::Size() const noexcept
{
    return size;
}
// ...

/* ************************************************************************** */

// Specific member functions (LinearContainer)

// ...

/* ************************************************************************** */

// Specific member functions (TestableContainer)

// ...

/* ************************************************************************** */

// Specific member functions (SearchableContainer)

template <typename Data>
void FoldExists(const Data &data, const void *value, void *found)
{
    if (data == *((Data *)value))
    {
        *((*bool)found) = true;
    }
}

template <typename Data>
bool lasd::SearchableContainer<Data>::Exists(const Data &) const noexcept
{
    bool found = false;
    FoldPostOrder(&FoldExists, &data, &found);

    return found;
}
// ...
