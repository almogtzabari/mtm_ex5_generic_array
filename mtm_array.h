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
    explicit Array():size(SIZE),data(new T[SIZE]){};

    /** Copy constructor */
    Array(const Array& copy_from){
        size = copy_from.size;
        for(int i=0;i<size;i++){
            data[i] = copy_from.data[i];
        }
    }

    /** Destructor */
    ~Array(){
        delete[] data;
    }

    /** Operator= */
    Array& operator=(const Array& array){
        T* temp_data = new T[array.size];
        delete[] data;
        data = temp_data;
        size = array.size;
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
//-----------------------------------------------------------------------//
//                              Iterator                                 //
//-----------------------------------------------------------------------//
    class iterator {
        Array<T,SIZE>* array;
        int index;

        /** Constructor */
        iterator(Array<T,SIZE>* array, int index = 0): array(array),index(index){};
        friend class Array<T,SIZE>;

    public:

        /** Operator* */
        T& operator*() const {
            return (*array)[index];
        }

        /** Operator++ */
        iterator operator++(int){
            index++;
            return iterator(array,index-1);
        }

        /** ++Operator */
        iterator& operator++() {
            index++;
            return *this;
        }

        /** Operator== */
        bool operator==(const iterator& it) const{
            return array == it.array && index == it.index;
        }

        /** Operator!= */
        bool operator!=(const iterator& it) const{
            return !(this->operator==(it));
        }

        /** Operator-> */
        T& operator->(){
            return &((*array)[index]);
        }
    };

    iterator begin(){
        return iterator(this);
    }

    iterator end(){
        return iterator(this,size);
    }

//-----------------------------------------------------------------------//
//                        Const Iterator                                 //
//-----------------------------------------------------------------------//
    class const_iterator {
        T* ptr;

        /** Constructor */
        const_iterator(T* address): ptr(address){};

        friend class Array<T,SIZE>;

    public:

        /** Operator* */
        T const& operator*() const{
            return *ptr;
        }

        /** Operator++ */
        const_iterator operator++(int){
            const_iterator it = *this;
            ptr++;
            return it;
        }

        /** ++Operator */
        const_iterator& operator++(){
            if(ptr == )
            ptr++;
            return *this;
        }

        /** Operator== */
        bool operator==(const const_iterator& it) const{
            return ptr == it.ptr;
        }

        /** Operator!= */
        bool operator!=(const const_iterator& it) const{
            return !(this->operator==(it));
        }

        /** Operator-> */
        const T& operator->(){
            return ptr;
        }
    };

    const_iterator begin() const{
        return &data[0];
    }
    const_iterator end() const{
        return &data[size];
    }
};



#endif //EX5_MTM_ARRAY_H