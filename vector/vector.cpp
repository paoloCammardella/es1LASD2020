
#include <stdexcept>

/* ************************************************************************** */

//Destructor
template <typename Data>
lasd::Vector<Data>::~Vector()
{
    delete[] this;
}

template <typename Data>
void lasd::Vector<Data>::Resize(ulong size)
{
    Vector v2;
    v2.size = size;
    for (int i = 0; i < this.size; i++)
    {
        v2[i] = this[i];
    }
    this = v2;
    ~v2();
}

// ...
