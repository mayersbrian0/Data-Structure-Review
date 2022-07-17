#include <iostream>
#include "myqueue.h"

template<typename T> Queue<T>::Queue() {
    size = 20;
    arr = new T[size];
    start = 0;
    end = 0;
    fill_count = 0;
}

template<typename T> Queue<T>::Queue(int new_size) {
    size = new_size;
    arr = new int[size];
    start = 0;
    end = 0;
    fill_count = 0;
}

template<typename T> Queue<T>::~Queue() {
    delete arr;
}

template<typename T> bool Queue<T>::empty() {
    return fill_count == 0;
}

template<typename T> bool Queue<T>::full() {
    return fill_count == size;
}

template<typename T> void Queue<T>::enqueue(T value) {
    if (full()) {
        std::cout << "Error Queue is Full\n";
        return;
    }

    arr[end] = value;
    end = ++end % size;
    fill_count++;
}

template<typename T> T Queue<T>::dequeue() {
    if (empty()) {
        std::cout << "Error Queue is Empty\n";
        return INT_MIN;
    }

    int val = arr[start];
    start = ++start % size;
    fill_count--;
    return val;
}

template<typename T> void Queue<T>::print_info() {
    std::cout << "Queue Size: " << size << "\n";
    std::cout << "Start IDX: " << start << "\n";
    std::cout << "Start VAL: " << arr[start] << "\n";
    std::cout << "End IDX: " << end << "\n";  
}