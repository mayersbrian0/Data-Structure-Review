#include "myvector.h"
#include <iostream>

//constructor
template<typename T> vector<T>::vector()  {
    //allocate 16 to start with
    cap = 16;
    curr_size = 0;
    arr = new T[cap];
}

//deallocate the memory when finished
template<typename T> vector<T>::~vector() {
    delete arr;
}

template<typename T> void vector<T>::resize() {
    unsigned int new_capacity = cap*2;
    int i = 0;
    T* new_arr = new T[new_capacity];
    for (i = 0; i < curr_size; i++) {
        *(new_arr + i) = *(arr + i);
    }
    delete arr;

    arr = new_arr;
    cap = new_capacity;
    return;
}

template<typename T> int vector<T>::size() {
    return curr_size;
}

template<typename T> unsigned int vector<T>::capacity() {
    return cap;
}

template<typename T> bool vector<T>::is_empty() {
    return curr_size == 0;
}

template<typename T> int vector<T>::at(unsigned int index) {
    if (index >= curr_size) {
        std::cout << "Error: Index out of Range\n";
        return -1;
    }

    return *(arr + index);
}

template<typename T> void vector<T>::push(T item) {
    //resize if capacity is reached
    if (curr_size == cap) resize();

    *(arr+curr_size) = item;
    curr_size++;
    return;
}

template<typename T> void vector<T>::insert(T item, unsigned int index) {
    int temp1 = 0, temp2 = 0, i = 0;

    if (index > curr_size) {
        std::cout << "Error Index out of Range\n";
        return;
    }

    if (index == curr_size) resize();

    curr_size++;
    temp1 = item;
    for (i = index; i < curr_size; i++) {
        temp2 = *(arr + i);
        *(arr + i) = temp1;
        temp1 = temp2;
    }

    return;
}

template<typename T> void vector<T>::prepend(T item) {
    insert(item, 0);
    return;
}


template<typename T> int vector<T>::pop() {
    curr_size--;
    return *(arr + curr_size );

}

template<typename T> void vector<T>::del(unsigned int index) {
    int i = 0;
    curr_size--;
    for (i = index; i < curr_size; i++) {
        *(arr + i) = *(arr + i + 1);
    }
    return;
}

template<typename T> void vector<T>::remove(T item) {
    int i = 0;

    while (i < curr_size) {
        if (*(arr + i) == item) del(i);
        else i++;
    }
    return;
}

template<typename T> int vector<T>::find(T item) {
    int i = 0;
    for (i = 0; i < curr_size; i++) {
        if (*(arr + i) == item) return i;
    }
    return -1;
}

template<typename T> void vector<T>::print() {
    int i = 0;
    for (i = 0; i < curr_size; i++) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << "\n";
    return;
}