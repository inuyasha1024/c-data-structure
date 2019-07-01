//
// Created by James Zhang - Vendor on 2019-06-30.
//

#ifndef DATA_STRUCTURE_VECTOR_H
#define DATA_STRUCTURE_VECTOR_H
#define DEFAULT_CAPACITY 3
typedef int Rank;

namespace vector{


template <typename T> class Vector {
protected:
    Rank _size;
    int _capacity;
    T* _elem;
    void copyFrom(T const* A, Rank lo, Rank hi);
    void expand();
    void shrink();
    bool bubble(Rank lo, Rank hi);
    void bubbleSort(Rank lo, Rank hi);
    Rank max(Rank lo, Rank hi);

public:
    Vector(int c = DEFAULT_CAPACITY, int s =0,T v =0){
        _elem = new T[ _capacity = c];
        for (_size=0; _size< s; _elem[_size++] = v );
    };
    Vector(T const* A, Rank lo, Rank hi){
        _elem = new T[ _capacity = 2*(hi - lo)];
        _size = 0;
        while (lo < hi){
            _elem[_size++] = A[lo++];
        }
    }

    ~Vector(){
        delete [] _elem;
    };

    //read only method
    Rank size() const { return _size; };

    //writable method
    T& operator[](Rank r) const;
    Vector<T> &operator=(Vector<T> const&);
    T remove(Rank r);
    int remove(Rank lo, Rank hi);
    Rank insert(Rank r, T const& e);

    //iterate
    void traverse(void (*)(T&));
    template <typename VST> void traverse(VST&);
};

}


#endif //DATA_STRUCTURE_VECTOR_H
