#ifndef MY_QUEUE
#define MY_QUEUE
#include <climits>

template<typename T>class Queue {
    private:
    T* arr;
    int size;
    int start;
    int end;
    int fill_count;

    public:

    Queue();
    Queue(int size);
    ~Queue();

    void enqueue(T value);
    T dequeue();
    bool empty();
    bool full();

    void print_info();

};


#endif 
