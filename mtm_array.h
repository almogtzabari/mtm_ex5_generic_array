#ifndef EX5_MTM_ARRAY_H
#define EX5_MTM_ARRAY_H

#include <utility>
#include <stdexcept>

template <class T, int SIZE>
class Array
{
public:
    // TODO: Need to complete interface of iterator classes (x++,++x, ->, operator==, operator!=), as well
    // as that of array itself (operator [], operator [] const, ctor, copy ctor, dtor, operator=),
    // and implement everything.

    class iterator {
    public:
        T& operator*() const;
    };

    class const_iterator {
    public:
        T const& operator*() const;
    };

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
};



#endif //EX5_MTM_ARRAY_H