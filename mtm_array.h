#ifndef EX5_MTM_ARRAY_H
#define EX5_MTM_ARRAY_H

#include <utility>
#include <stdexcept>

template <class T, int SIZE>
class Array
{
    T* data;
    int size;
    static_assert(SIZE>0);
    
public:
    /** Constructor */
    explicit Array():data(new T[SIZE]),size(SIZE){}

    /** Constructor */
    /** Creates a new array and initializing all cells to 'num'. */
    explicit Array(const T& t):data(new T[SIZE]),size(SIZE){
        for(int i=0;i<size;i++){
            data[i] = t;
        }
    }

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
            data[i] = array.data[i];
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


//-----------------------------------------------------------------------//
//                              Iterator                                 //
//-----------------------------------------------------------------------//
    class iterator {
        Array<T,SIZE>* const array;
        int index;

        /** Constructor */
        explicit iterator(Array<T,SIZE>* const array, const int index = 0):
                array(array),index(index){}
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
        T* operator->() const{
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
        const Array<T,SIZE>* const array;
        int index;

        /** Constructor */
        explicit const_iterator(const Array<T,SIZE>* const array, const int index = 0):
                array(array),index(index){}

        friend class Array<T,SIZE>;

    public:

        /** Operator* */
        const T& operator*() const {
            return (*array)[index];
        }

        /** Operator++ */
        const_iterator operator++(int){
            index++;
            return const_iterator(array,index-1);
        }

        /** ++Operator */
        const_iterator& operator++() {
            index++;
            return *this;
        }

        /** Operator== */
        bool operator==(const const_iterator& it) const{
            return array == it.array && index == it.index;
        }

        /** Operator!= */
        bool operator!=(const const_iterator& it) const{
            return !(this->operator==(it));
        }

        /** Operator-> */
        const T* operator->() const{
            return &((*array)[index]);
        }
    };

    const_iterator begin() const{
        return const_iterator(this);
    }

    const_iterator end() const{
        return const_iterator(this,size);
    }
};



#endif //EX5_MTM_ARRAY_H