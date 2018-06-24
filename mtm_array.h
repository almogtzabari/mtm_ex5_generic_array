#ifndef EX5_MTM_ARRAY_H
#define EX5_MTM_ARRAY_H

#include <utility>
#include <stdexcept>

template <class T, int SIZE>
class Array
{
    T* data;
    int size;
public:
    /** Constructor */
    explicit Array():size(SIZE),data(new T[SIZE]){}; // todo: throw exception if needed.

    /** Copy constructor */
    Array(const Array& copy_from){
        size = copy_from.size;
        for(int i=0;i<size;i++){
            data[i] = copy_from.data[i]; // Requires operator= for <T>.
        }
    }

    /** Operator= */
    Array& operator=(const Array& array){
        if(this == &array){
            /* Self assignment. */
            return *this;
        }
        delete[] data;
        size = array.size;
        data = new T[size];
        for(int i=0; i<size; i++){
            data[i] = array.data[i]; // Requires operator= for <T>.
        }
        return *this;
    }

    /** Operator[] */
    T& operator[](const int i){
        if(i<0 || i>=size){
            throw std::out_of_range("mtm_array::operator []: index out of range!");
        }
        return data[i];
    }

    /** Const operator[] */
    const T& operator[](const int i)const {
        if(i<0 || i>=size){
            throw std::out_of_range("mtm_array::operator []: index out of range!");
        }
        return data[i];
    }


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

    iterator begin(){
        return data;
    }
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
};



#endif //EX5_MTM_ARRAY_H